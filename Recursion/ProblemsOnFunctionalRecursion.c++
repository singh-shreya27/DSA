                   //Reverse an array:
    //using two pointers.
#include<bits/stdc++.h>
using namespace std;
void reverseArray(int arr[],int l,int r){
  
   if(l>=r) return;
   swap(arr[l],arr[r]);
    reverseArray(arr,l+1,r-1);
}
int main(){
     int n;
     cout<<"n:";
     cin>>n;
     int arr[n];
     cout<<"arr:";
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     reverseArray(arr,0,n-1);
     cout<<"reversed array:";
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
    
    return 0;
}
                 //using one variable.
#include<bits/stdc++.h>
using namespace std;
void reverseArray(int arr[],int n,int i){
    if(i>=n/2){
        return ;
    }
    swap(arr[i],arr[n-i-1]);
    reverseArray(arr,n,i+1);
}
int main(){
     int n;
     cout<<"n:";
     cin>>n;
     int arr[n];
     cout<<"arr:";
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     reverseArray(arr,n,0);
     cout<<"reversed array:";
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
    return 0;
}

                 //Check if the given string is palindrome or not.
 #include<bits/stdc++.h>
 using namespace std;
 bool palindromeCheck(const string &str ,int n,int i){
    if(i>=n/2) return true;
    if(str[i] != str[n-i-1]) return false;

   return palindromeCheck(str,n,i+1);
 }

 int main(){
   
    string str;
    cout<<"Enter a string:";
    cin>>str;
    int n=str.length();
    if(palindromeCheck(str,n,0)){
        cout<<"The string is a palindrome."<<endl;
    } else{
        cout<<"The string is not a palindrome."<<endl;
    };
    return 0;
 }
//T.C:O(n/2)
//S.C:O(n/2)
