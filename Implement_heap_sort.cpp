/*
                                                    HEAP SORT
                                                    =========

## So what is heap?
A heap is a data structure that respects the below properties -
1) Complete binary tree(cbt) property :
In CBT all the levels except the last level, i.e., leaf node should be completely filled, and all the nodes should be left-justified.
2) Heap order property

There are two types of heap 
1. Min heap
(heap order property of min heap is -> root data has minimum/low priority data as compared to child data)
1. Max heap
(heap order property of max heap is -> root data has maximum/high priority data as compared to child data)

** Note : we imagine heaps as a complete binary tree but internally store the data in a array/vector
          for a data present in index 'i' of array its children will be present at index '2i+1' and index '2i+2'.
          for a data present at index 'j' its parent node data  will be present at index '(j-1)/2'

## Heap Sort
Heap sort, as the name suggests, makes use of heap data structure to sort the given array. 
It is one of the most preferred sorting algorithms due to its favorable worst-case time complexity.
Time complexity of inplace heap sort - O(nlog(n))       
Space complexity of inplace heap sort - O(1)

*/

// CODE :

#include <iostream>
using namespace std;


void inplaceHeapSort(int pq[], int n) {

	for(int i = 1; i < n; i++) {
		
		int childIndex = i;
		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
	}

	int size = n;

	while(size > 1) {
		int temp = pq[0];
		pq[0] = pq[size - 1];
		pq[size-1] = temp;

		size--;

		int parentIndex = 0;
		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndx = 2 * parentIndex + 2;

		while(leftChildIndex < size) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[leftChildIndex]) {
				minIndex = leftChildIndex;
			}
			if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) {
				minIndex = rightChildIndx;
			}
			if(minIndex == parentIndex) {
				break;
			}
			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndx = 2 * parentIndex + 2;
		}
	}
}


int main() {
	int input[] = {5, 1, 2, 0, 8};
	inplaceHeapSort(input, 5);
	for(int i = 0; i < 5; i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;

}
