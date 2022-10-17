/*
                                    SHELL SORT
                                    ==========

# Shell sort is a improved version of insertion sort
# In insertion sort we initial consider the first item to be sorted then the remaining array is searched sequentially and unsorted items are moved and inserted into the sorted sub-list at correct position.
# Shell sort was introduced by Donald Shell to improve the complexity of insertion sort.
# In shell sort the method begins by sorting pairs of elements far apart from each other, then gradually narrows the gap between elements to be compared.
Advantage of shell sort is that some far apart elements can be moved into position faster than what a simple nearest neighbor exchange would, by starting with far apart elements.
This algorithm uses insertion sort on widely spread elements to sort them and then sort the less widely spaced elements. This spacing is termed as the interval.

# To find the interval gap in which shell sort is applied we use Knuth's Formula:
   i = i * 3 + 1 , Where i is the interval with a starting value of 1.

# Algorithm
1.) decide interval i.
2.)Separate the list into sub-lists with the i interval.
3.)Using insertion sort, sort these sub-lists.
4.) reduce the interval and Continue until the entire list has been sorted.

# Time complexity = O(n^2)
# Space complexity = O(1)

*/

// CODE : 

#include <iostream>
using namespace std;

void shellsortalgorithm(int array[], int number){
    int i, j, k, temp;
    for (i = number / 2; i > 0; i = i / 2){
        for (j = i; j < number; j++){
            for (k = j - i; k >= 0; k = k - i){
                if (array[k + i] >= array[k])
                    break;
                else
                {
                    temp = array[k];
                    array[k] = array[k + i];
                    array[k + i] = temp;
                }
            }
        }
    }
    return;
}

int main(){

    int array[100];
    int k, values;
    cout<<"Enter total no. of elements : ";
    cin>>values;
    cout<<"\nEnter the values: ";

    for (k = 0; k < values; k++){
        cin>>array[k];
    }

    shellsortalgorithm(array, values);

    cout<<"\nArray after the sorting: ";
    for (k = 0; k < values; k++)
        cout<<array[k]<<" ";

    return 0;
}
