                                                  //ARRAYS:
//A data structure which contains similar elements(integers,characters,string,pair<int,int>)
//If we declare an array inside int main(int arr[6]) then all the six positions will be filled with some garbage values.
//whereas if we declare it globally,then all of them will be filled with zeroes.
//Maximum size of array that we can define is of 10^6(inside int main),10^7(globally).


//Given number is present in the array or not using hash array.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Size of array:";
    cin>>n;
    int arr[n];
    cout<<"Array:";
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    //precompute
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    //q=query 
    int q;
    cout<<"q:";
    cin>>q;
     while(q--){
        int number;
        cout<<"number:";
        cin>>number;
        //fetch
        cout<<"No. of times it appears:"<<hash[number]<<endl;
     }


    
    return 0;
}
