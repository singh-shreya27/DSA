                          //Insertion sort
      //Takes an element and places it in its correct order.
#include<bits/stdc++.h>
using namespace std;
   
void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
      int j=i;
      while(j>0 && arr[j-1]>arr[j]){
        swap(arr[j-1],arr[j]);
        j--;
      }
    }
}

int main(){
   int n;
    cout<<"n:";
    cin>>n;
    cout<<"arr:";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
   insertionSort(arr,n);
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
  
}

//T.C: O(n(n+1)/2) ~O(n^2)  avg and worst case complexity.
//Best case:The given array is already sorted.
//O(n)  best case complexity.

