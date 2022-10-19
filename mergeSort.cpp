// Merge Sort is useful for sorting linked lists in O(N log N) time. In the case of linked lists, the case is different mainly due 
// to the difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in 
// memory. Unlike an array, in the linked list, we can insert items in the middle in O(1) extra space and O(1) time.
// Therefore, the merge operation of merge sort can be implemented without extra space for linked lists.
// In arrays, we can do random access as elements are contiguous in memory. Let us say we have an integer (4-byte) array A and 
// let the address of A[0] be x then to access A[i], we can directly access the memory at (x + i*4). 
// Unlike arrays, we can not do random access in the linked list. Quick Sort requires a lot of this kind of access. 
// In a linked list to access i’th index, we have to travel each and every node from the head to i’th node as we don’t have a 
// contiguous block of memory. Therefore, the overhead increases for quicksort. 
// Merge sort accesses data sequentially and the need of random access is low.

// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne
		= 0, // Initial index of first sub-array
		indexOfSubArrayTwo
		= 0; // Initial index of second sub-array
	int indexOfMergedArray
		= left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursively

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

// Driver code
int main()
{
	cout<<"Enter the length of array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
	cout << "Given array is \n";
	printArray(arr, n);

	mergeSort(arr, 0, n - 1);
    cout<<endl;

	cout << "\nSorted array is \n";
	printArray(arr, n);
	return 0;
}

