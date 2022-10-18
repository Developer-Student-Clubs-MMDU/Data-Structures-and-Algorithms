/*
problem statement- Insertion sort using binary search 

Input:  23 45 2 1 4
Output: 1 2 4 23 45 

Algo:

1.Firstly calling the function insertion sort 
2.In that ,iterate over the loop from secound till last element
3.store the current element in key
4.find positon of element using binary search ,element just greater than  a[i] between a[0] to a[i-1]
5.suppose this element is present at some index say k
6.shift all the element towards right from k to i-1.
*/

#include <iostream>
using namespace std;
  

int binarySearch(int a[], int item,int low, int high)//using binary search to find the element 
{
    if (high <= low)
        
        return (item > a[low]) ?(low + 1) : low;
  
    int mid = (low + high) / 2;
  
    if (item == a[mid])
        return mid + 1;
  
    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);


    return binarySearch(a, item, low,mid - 1);
}
  
void insertionSort(int a[], int n)//sorting the array 
{
    int i, loc, j, k, key;
  
    for (i = 1; i < n; ++i)//iterating the loop from secound position till last position 
    {
        j = i - 1;//taking one element previous than current 
        key = a[i];
  
    
        loc = binarySearch(a,key, 0, j);//now we need to find location where key should be inserted
          
        while (j >= loc)//shifting  till we find correct position 
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
  
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertionSort(a, n);
  
    cout <<"Sorted array: \n";
    for (int i = 0; i < n; i++)
        {
            cout <<" "<< a[i];
        }
    return 0;
}
