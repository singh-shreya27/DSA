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

//but the array can have maximum element till 10^9.
//Can we declare an array of size arr[10^9 +1]?
//Answer:   NO
//The maximum size array that we can declare is 10^6 if it is of integer (inside main).
//but if we declare that will show you error :segmentation fault.
//However, if we declare it GLOBALLY, we can declare till 10^7 : arr[1e7]

//Number hashing : we can use arrays to hash them.
//Character hashing:  Can we do character hashing using arrays?
//Answer: Yes, we can.

//Imagine array only has lowercase letters.
//The numbers are converted into their ASCII Value.
//'a'=97 and 'z'=122.
//corresponding index in the hash array=  char-'a'

//We have 256 characters in total.
//If we have uppercase letters as well, create an array of 256 size.(0-255)

             //character hashing
    //assuming string has only lowercase letters
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"s:";
    cin>>s;
  
    //precompute
    int hash[26]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }

    //no. of queries
    int q;
    cout<<"q:";
    cin>>q;
    while(q--){
        char c;
        cout<<"char:";
        cin>>c;
        //fetch
       cout<<hash[c-'a']<<endl;
    }

    return 0;
}

//imagine we don't know that only lowercase letters exist.

//make an array of size 256 and don't need to do char-'a'.
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"s:";
    cin>>s;

    //precompute
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }
    //no. of queries
    int q;
    cout<<"q:";
    cin>>q;
    while(q--){
        char c;
        cout<<"char:";
        cin>>c;
        //fetch
       cout<<hash[c]<<endl;
    }

    return 0;
}

//There will never be any complications in character hashing because at max there will be 256 characters
//and an array can easily store 256 characters.
//so always prefer arrays for character hashing and always use char-'a' for lowercase  and char-'A' for uppercase.
//if all elements present  make an array of 256 size.
