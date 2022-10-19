#include<iostream>
using namespace std;
void printArray(int *array,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void SelectionSort(int *array,int n)
{
    for(int i=0;i< n-1;i++)
    {
       int minIndex=i;
       for(int j=i+1;j<n;j++)
       {
        if(array[j]<array[minIndex])
        {
            minIndex=j;
        }
       }
       int temp= array[i];
       array[i]= array[minIndex];
       array[minIndex]=temp;
    }
}
int main()
{
    cout<<"This is Selection Sort Algorithm program"<<endl;
    int array[6]={40,20,30,10,60,50};
    int n=6;
    printArray(array,n);
    SelectionSort(array,n);
    printArray(array,n);
    string s;
    s="abcd";
    cout<<s.at(2);
    return 0;
}