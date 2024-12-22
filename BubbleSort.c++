               //Bubble Sort
 //It pushes the maximum to the last by adjacent swaps.
#include<bits/stdc++.h>
using namespace std;
 
 void bubbleSort(int arr[],int n){ 
   for(int i=n-1;i>=1;i--){
    for(int j=0;j<=(i-1);j++){
    if (arr[j]>arr[j+1]){
      swap(arr[j],arr[j+1]);
    }
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
  
  //bubble sort
  bubbleSort(arr,n);
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
      }


  return 0;
}

//T.C:O(n(n+1)/2)~O(n^2)    Worst,avg complexity
//Best case: if the given array is already sorted, we don't need to do swapping
//O(n)    Best case   [INPORTANT:Asked in interviews]
void bubbleSort(int arr[],int n){ 
   for(int i=n-1;i>=1;i--){
    int didSwap =0;
    for(int j=0;j<=(i-1);j++){
    if (arr[j]>arr[j+1]){
      swap(arr[j],arr[j+1]);
      didSwap =1;
    }
   }
   if(didSwap ==0){
    break;
   }
   cout<<"runs"<<endl;
   }
 }
