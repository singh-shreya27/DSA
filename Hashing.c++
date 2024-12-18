#include<bits/stdc++.h>
using namespace std;
int main(){
                    //taking input
     int n;  //size of array           //5
     cout<<"n:";
     cin>>n;
     int arr[n];                       //1 2 1 3 2
     cout<<"arr:";
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
            //precompute
    //assuming at max size can be till 12

    //depending on the maximum size of the array, we declare the hash.
    int hash[13] ={0};  //to declare an array having every element as 0.
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }



     int q;   //no. of numbers about which we want to check how many times they appear.(no. of queries)
     cout<<"q:";                         //5
     cin>>q;
     while(q--){
         cout<<"number:";
        int number;      //for every query , the number   (1 ,4,2,3,12)
        cin>>number;
          //fetch
     cout<<hash[number]<<endl;
     }



    return 0;
}
