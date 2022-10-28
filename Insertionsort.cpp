#include <bits/stdc++.h>

using namespace std;


// program to implement insertion sort
int main() {
    // enter the size of array
    int n;
    cin>>n;
    int a[n];
    // take array as input
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //declare key value and an integer variable to point the position of array element which have to move ahead
    int key,c;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        c=i-1;
        while (c>= 0&& a[c]>key)
        {
           a[c+1]=a[c];
            c--;
        }
        a[c+1]= key;
    }

   // Now print the sorted array
   for(int i=0;i<n;i++)
   {
       cout<<a[i]<<" ";
   }



}
