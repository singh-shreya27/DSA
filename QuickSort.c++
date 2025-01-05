                            //Quick sort
//This also has T.C. similar to merge sort but it does not uses any extra space unlie merge sort.
//T.C: O(n*log2n)
//S.C:O(1)
//STEPS:
//STEP1:pick a pivot and place it in its correct place in the sorted array.
//there is no rule to pick up the pivot element.
//a. 1st element in the array.
//b. last element in the array.
//c. median of the array.
//d. random element of the array.
//STEP2:smaller on the left and larger on the right.

#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int low, int high){
      int pivot = arr[low];
      int i=low;
      int j=high;
      while(i<j){
          while(arr[i]<=pivot && i<=high){   // Find an element greater than pivot
            i++;
          }  
          while(arr[j]>pivot && j>=low){    // Find an element less than or equal to pivot
            j--;
          }
          if(i<j) swap(arr[i],arr[j]);        // Swap out-of-place elements
      }
      swap(arr[low],arr[j]);
      return j;                    // Place pivot in the correct position

}
void qs(vector<int> &arr, int low, int high){
      if(low<high){
            int pIndex= partition(arr,low,high);
            qs(arr,low,pIndex-1);
            qs(arr,pIndex+1,high);

      }
}
void quickSort(vector<int> &arr){
      qs(arr,0,arr.size()-1);
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
    
    quickSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;



      return 0;
}

//T.C: O(n*log2n)
//S.C:O(1)

//write code for descending.
