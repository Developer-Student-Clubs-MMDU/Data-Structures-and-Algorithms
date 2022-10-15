/*Probelm statement :Sort the following array using inserion sort in Ologn complexity
Input : 45 32 12 15 19
Output: 12 15 19 32 45

Approach
1.iterate over loop from arr[1] to arr[N] over the array
2.Comapre current element with its previous element
3.if current element is smaller than previous then compare with previous to previous element
4.move the greater element one position up ,basically swapping the data

*/

#include <bits/stdc++.h>
using namespace std;
  
void insertionSort(int arr[], int n) 
{
	    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];//storing secound element and comparing it with first 
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shifting 
                arr[j+1] = arr[j];
            }
            else { // will break 
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
    } 
 }

int main() 
{ 
    int n;
	cin>>n;
	int arr[n];
	//input the elements in array 
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

    insertionSort(arr, n); //calling the sort function

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";//calling the print out function 
	}
  
    return 0; 
} 
