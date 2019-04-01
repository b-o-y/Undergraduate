// --------------------------------------------------
// Travis Henderson
// Directory File Search
// Date Last Modified: 16/11/08
// --------------------------------------------------
// Description:
// --> Nothing that unique about the driver file,
// except for this assignment students were expected
// to use the try/catch for error handling. I forget
// what purpose it was supposed to serve for the
// assignment.
// --------------------------------------------------
public class Driver
{
    public static void main(String[] args)
    {
	String targetFile = "new.txt"; // Find this file.
	String pathToSearch = "/media/boy/6E4D-9C0A"; // If you use a Windows machine change the direction of your slahes.
	FindFile find = new FindFile(60);

	try
	    {
		find.directorySearch(targetFile, pathToSearch);
	    }
	catch (IllegalArgumentException e)
	    {
		System.out.println("MAX NUMBER OF INSTANCES REACHED");
		System.out.println("There were " + find.getCount() + " target files found.");

		String[] path = find.getFiles();
		System.out.println("File was found at following locations: ");
		for (int i = 0; i < path.length; i++)
		    {
			System.out.println(path[i] + "\n");
		    }
		System.exit(0);
	    }

	System.out.println("There were " + find.getCount() + " target files found.");
	String[] path = find.getFiles();

	System.out.println("File was found at following locations: ");
	for (int i = 0; i < path.length; i++)
	    {
		System.out.println(path[i] + "\n");
	    }
    }
}
