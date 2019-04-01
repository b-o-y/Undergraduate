// --------------------------------------------------
// Travis Henderson
// Directory File Search
// Date Last Modified: 16/11/08
// --------------------------------------------------
// Description:
// --> What this program does is start with a file
// path name, then from that starting point it
// searches for a user given file name.
//
// --> The FindFile class finds a user given file
// name and finds the location of that file name,
// and reports back the path.  It will only do this
// for the first 'n' instances of the file, this
// amount 'n' is set by the user. It is called count.
//
// --> This is an assignment from my second 100-level
// programming class a year ago.  I wanted to clean
// up the program and revisit it because honestly, I
// completely forgot how I did it.
//
// Notes:
// --> I added a lot of "unneccessary" comments
// detailing what functions of the File class do.
// They're necessary for me, because I forget.
// --------------------------------------------------

import java.io.File;
import java.util.Arrays;

public class FindFile
{
    private int maxFiles; // How many instances of a file one wants to find.
    private int count; // How many instances of said file were actually found.
    private String[] locations; // The path names of where the file was found is stored here.

    // Contructor sets the max number of files to find, and size of array.
    public FindFile(int maxFiles)
    {
	this.maxFiles = maxFiles;
	this.locations = new String[maxFiles];
    }

    // --------------- directorySearch ---------------
    // This method first checks that the dirName is
    // actually a valid directory, if so, it then
    // begins searching by calling a private method.
    // The private method is necessary to handle
    // when f is NOT a directory but a file, and
    // if it's not the target file, it needs to search
    // again.
    // -----------------------------------------------
    public void directorySearch(String target, String dirName)
    {
	File f = new File(dirName); // Have to make this object so I can check dirName.

	if (f.isDirectory())
	    {
		find(target, dirName);
	    } 
	else
	    {
		throw new IllegalArgumentException();
	    }
    }

    private void find(String target, String dirName)
    {
	File f = new File(dirName);

	if (f.isDirectory())
	    {
		String[] fileList = f.list();
		/* .list returns an array of strings naming the files and directories in the
		   directory denoted by this abstract pathname. */

		/* The recursion in this for loop  allows the search to contine to pick up 
		   where it left off when target is not found, or needs to go back 
		   a directory. */
		for (int i = 0; i < fileList.length; i++)
		    {
			find(target, dirName + "/" + fileList[i]);
		    }
	    } 
	 else if (target.equals(dirName.substring(((dirName.length()-1) - (target.length() - 1)), (dirName.length()))))
	    {
		/* An UGLY line, but necessary, need to compare the target name to /blah/blah/last that comes at the end of
		   dirName */
		if (count < maxFiles) // An instance was found, add it to the FindFile object.
		    {
			locations[count++] = dirName;
		    } 
		 else
		    {
			throw new IllegalArgumentException("MAX_NUMBER_OF_FILES_TO_FIND");
		    }
	    }
    }

    // Returns the number of matching files found.
    public int getCount()
    {
	return this.count;
    }

    // Returns the array of file locations, up to maxFiles in size.
    public String[] getFiles()
    {
	String[] retVal = Arrays.copyOf(locations, count);
	return retVal;
    }
} 
