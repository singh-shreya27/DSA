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

//so to solve the problem in number hashing, STL/collection(java) comes in.
//STL: 1.Map , 2. Unordered map.

                            //MAP:
//suppose we are given an array[1,2,3,1,2,12]
//map is a data structure in which we have a key(number) and a value(frequency).
//Before iterating in the array , mpp[1]=0 because it does not exist in the map.
//mpp[arr[i]]++
//If we use array hashing, we would be taking an array of size 13, but we are just storing the few elements 
//but in map we are just storing the elements.
//So , map takes a little less space

//MAP

#include<bits/stdc++.h>
using namespace std;
int main(){
      
   int n;
   cout<<"n:";
   cin>>n;
   int arr[n];
   cout<<"arr:";
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   //pre-compute
   map<int,int> mpp;     //if large no. is there take long 
   for(int i=0;i<n;i++){
    mpp[arr[i]]++;
   }

   //to see that map stores all values in sorted order.
   //iterate in the map
   for(auto it :mpp){                                                 // 1->2
     cout<<it.first<<"->"<<it.second<<endl;                            //2->2
   }                                                                   //3->2
                                                                       //12->1
   int q;
   cout<<"q:";
   cin>>q;
   cout<<"number:"<<endl;
   while(q--){
    int number;
     cin>>number;
     //fetch
     cout<<"frequency:"<<mpp[number]<<endl;
   }

    return 0;
}

//Map stores all the values in sorted order.
   //Time -complexity of Map:
//Storing and fetching both of them in a map takes log(N) in all best, avg and worst case.
                                         //Unordered Map
//we cannot decide the order.

#include<bits/stdc++.h>
using namespace std;
int main(){
      
   int n;
   cout<<"n:";
   cin>>n;
   int arr[n];
   cout<<"arr:";
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   //pre-compute
   unordered_map<int,int> mpp;     //if large no. is there take long 
   for(int i=0;i<n;i++){
    mpp[arr[i]]++;
   }

   //to see that map stores all values in sorted order.
   //iterate in the map
   for(auto it :mpp){                                       // 3->2
     cout<<it.first<<"->"<<it.second<<endl;                 //12->1
   }                                                        //2->2
                                                            //1->2

   int q;
   cout<<"q:";
   cin>>q;
   cout<<"number:"<<endl;
   while(q--){
    int number;
     cin>>number;
     //fetch
     cout<<"frequency:"<<mpp[number]<<endl;
   }
    return 0;
}

//What is the advantage of unordered map?
//In average and best case , for storing and fetching , T.C=O(1)
//But in worst case :O(N) where N is the number of elements in the map data structure which happens becoz of internal collisions.
//Most of the times we use unordered map, if it gives TLE(Time limit exceeded) then we switch to map.

//Hashing ->1.Division method. 
        //2.Folding method.
        //3.Mid-square method.

//Q.If we are given an array[2,5,16,28,139] and creating an array of size greater then 10 is not allowed.
//So, this is where division method comes in.
//ANS: Create an array from 0-9.
//then we will modulate every number by 10. arr[i]%10 
//so we will get 2,5,6,8,9 resp for this given array.
//But what if after %10 there are same numbers such as for array[2,5,16,28,139,38,48,28,18]
//we store the numbers by linear chaining.. 18->28->28->38->48(sorted)


