//Binary Search Algorithm can only be applied to sorted list/array.
//If array/list is not sorted we cannot apply Binary Search on that.

/*
Workin of Binary Search Algorithm
Binary Search Algorithm is an example of divide and conquer technique

In binary search we divide the array/list in two parts from the middle and compare the middle with the key(element to found).

case1: If the middle element is equal to the key, then we return the index or the found message

case2: If the middle element is greater than the key, then we work on the next half of the array/list as all the elements present before the middle element is going to be smaller than the middle element(because the array/list is sorted). We then work from middle index + 1 to the end of the array/list and repeat case 1.

case3: If the middle element is smaller than the key, then we work on the first half of the array/list as all the elements present after the middle element is going to be greater than the middle element(because the array/list is sorted). We then work from first index to middle - 1 index of the array/list and repeat case 1.

*/


//Implementation of Binary Search Algorithm

//Here we are implementing Binary Search using recursion
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int key)
{
    if (right >=  left) {

        int mid = left + (right - left) / 2; //Calculating the middle element of the array
        //we have calculated mid in this way because if the number is very very big(out of range of int) the it will help to prevent the overflow of int

        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)     //key is present in the first half of the array
            return binarySearch(arr, left, mid - 1, key);   //searching in first half of the array

        return binarySearch(arr, mid + 1, right, key);  //searching in the last half of the array
    }
    return -1;  //if key is not found
}


int main()
{
    int arr[] = {1, 3, 6, 9, 12, 15, 18, 21, 55}; // creating a predefined array
    int key = 21;   //element to be searched in the array
    int arrSize = sizeof(arr) / sizeof(arr[0]);     //Calculating the size of the array
    int result = binarySearch(arr, 0, arrSize - 1, key);

    if(result == -1)
        cout<< "Element is missing in the array";
        
    else
        cout<< "Element is present in the array at index : " << result;

    return 0;
}
