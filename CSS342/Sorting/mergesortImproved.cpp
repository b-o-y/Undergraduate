// ------------------------------- mergeSortImproved.cpp -------------------------------
// Travis Henderson, CSS 342A
// Creation Date: 2016/05/05
// Date of Last Modification 2016/05/09
// -------------------------------------------------------------------------------------
// Purpose of this assignment is to implement mergeSort iteratively rather than
// recursively.  Then one is to compare the running time, using the built in functions
// of Linux, of recursive mergeSort and quickSort.
// -------------------------------------------------------------------------------------
// Assumptions/notes: The requirements of this assignment compared against two other
// sorts.  These are readily available on many other resources, and not turned in
// for this assignment.  If one wants to compare the times themselves, simply create
// the cpp files and comment out the mergesortImproved call in the driver. This
// is what I did to make the comparisons.
//
// Additionally, this may or may not be special, but I had to exclude the various
// cpp of the respective sorts from the build.  Otherwise there was a compiler
// error in that it would see the fxns in the include file of driver as well as the
// sort.cpp file itself.  Then when compiling on the linux servers, one only does:
// g++ driver.cpp
// To test the different sorts then, one would comment out/in whichever sort is being
// tested.
// An alternative is to remove the include from the driver and compiling both the
// sort.cpp and driver.cpp on the linux servers together.
// -------------------------------------------------------------------------------------

#include <vector>
#include <math.h> // may need to use pow( )
#include <iostream>
using namespace std;

// ---------------------------- findMin ------------------------------------------------
// Description: Returns the minimum of two integers.  This just a helper method to be
// used with the iterative mergeSort.
// -------------------------------------------------------------------------------------
int findMint(int a, int b) // These aren't const...bad programming?
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}



// ------------------------------------- merge ----------------------------------------
// Description: This is a helper method to merge the subarrays used in both mergesorts.
// After this method is ran, the subarrays will be sorted.  This is not my own
// implementation, but rather pulled from Data Abstraction & Problem Solving With C++
// by Carrano and Henry.
// ------------------------------------------------------------------------------------
template <class Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &b, int &start, int &mid, int &end)
{
	if (mid > end) // This is a cheap fix, but the last iteration on larger arrays puts mid out of bounds, this fixes it.
		return;

	// Initialize the local indices to indicate the subarrays.
	int first1 = start;		// Beginning of first subarray.
	int last1 = mid;		// End of first subarray.
	int first2 = mid + 1;	// Beginning of the second array.
	int last2 = end;		// End of second subarray.

	// While both subarrays are not empty copy the smaller item into the temporrary array (b).
	int index = first1;  // Next available location in 'b'.
	while ((first1 <= last1) && (first2 <= last2))
	{
		// At this point, b[first...index-1] is in order
		if (a[first1] <= a[first2])
		{
			b[index] = a[first1];
			first1++;
		}
		else
		{
			b[index] = a[first2];
			first2++;
		}
		index++;
	}

	// Finish off the first subarray, if necessary.
	while (first1 <= last1)
	{
		// At this point, b[first....index-1] is in order.
		b[index] = a[first1];
		first1++;
		index++;
	}

	// Finish off the second subarray, if necessary.
	while (first2 <= last2)
	{
		// At this point, b[first....index-1] is in order.
		b[index] = a[first2];
		first2++;
		index++;
	}

	// Copy the result back into the original array.
	for (index = start; index <= end; index++)
	{
		a[index] = b[index];
	}
}



// --------------------------- mergeSortImproved: Iterative mergesort -----------------
// This is the merge sort algorithm done iteratively.  It divides the array into
// smaller subarrays until it reaches a size of 1 then merges the subarrays back
// together all the while sorting them.
// ------------------------------------------------------------------------------------
template <class Comparable>
void mergesortImproved(vector<Comparable> &a) {

	int size = a.size();
	vector<Comparable> b(size);  // this is only one temporary array.     

								 // implement a nonrecursive mergesort only using vectors a and b.

	int sizeSubArr; // Size of the sub array
	int start; // Starting index of the subarray

	for (sizeSubArr = 1; sizeSubArr < size - 1; sizeSubArr *= 2)
	{
		for (start = 0; start < size - 1; start += (2 * sizeSubArr))
		{
			int mid = start + sizeSubArr - 1;
			int end = findMint((start + (2 * sizeSubArr) - 1), size - 1); // End will be which ever is the smaller of the two, this avoids out of index errors.

			merge(a, b, start, mid, end); //  Merge sub arrays[start-mid] and arrays[mid+1-end] 
		}
	}
}












// This main is only for testing purposes.
/*int main()
{
	vector<int> a;
	a.push_back(5);
	a.push_back(11);
	a.push_back(4);
	a.push_back(1);
	a.push_back(13);
	a.push_back(32);
	a.push_back(4);
	a.push_back(1);
	a.push_back(6);
	a.push_back(5);
	a.push_back(32);

	cout << "unsorted: " << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

	mergesortImproved(a);

	cout << "sorted: " << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}*/