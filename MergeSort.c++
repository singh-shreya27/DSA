 
                           //Merge sort
//Bubble,Insertion and Selection sort takes O(n^2) time complexity,that's why merge sort comes in.
//Merge sort takes much better complexity. It is much more optimised.

                     //Divide and merge.

#include<bits/stdc++.h>
using namespace std;

//low: index 0
//high: last index (n-1)
//function to merge two sorted halves
void merge(vector<int> & arr, int low, int mid,int high){
   vector<int> temp;
   int left = low;
   int right = mid+1;

   while(left<=mid && right <=high){
    if(arr[left]<=arr[right]){
        temp.push_back(arr[left]);
        left++;
    }
    else{
        temp.push_back(arr[right]);
        right++;
    }
   }
   while(left<=mid){
    temp.push_back(arr[left]);
        left++;
   }
   while(right<=high){
    temp.push_back(arr[right]);
        right++;
   }

   for(int i=low;i<=high;i++){
    arr[i]=temp[i-low];
   }
}
//recursive merge sort function
void mS(vector<int> &arr,int low,int high){
      if(low>=high) return;
      int mid=(low+high)/2;
      mS(arr,low,mid);
      mS(arr,mid+1,high);
      merge(arr,low,mid,high);
}
//wrapper function for merge sort
void mergeSort(vector<int> &arr, int n){
    mS(arr,0,n-1);
}
int main(){
    int n;
    cout<<"n:";
    cin>>n;
    cout<<"arr:";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    mergeSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    return 0;
}

//T.C: O(n*log2n)
//S.C: O(n)
