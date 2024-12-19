                       //SELECTION SORT.
//We select minimums and swap.
#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
     //last index is n-1
    //so we sort till (n-2)th index..last index is already sorted.
    for(int i=0;i<=n-2;i++){
    int min=i;
     for(int j=i;j<=n-1;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
        // swap(arr[min],arr[i]);
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
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
   
      //selection sort.
      selectionSort(arr,n);
      cout<<"Sorted array:";
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }

}

//T.C:
//O(n(n+1)/2)~O(n^2)   in best,worst and average case
//O(n^2)
