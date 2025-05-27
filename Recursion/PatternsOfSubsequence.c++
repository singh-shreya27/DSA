
//Printing Subsequence whose sum is K

//pesudo code:
// function(int i, ds,s){
//     if(i==n){
//         if(s==sum)
//           print ds;
//           return;
//     }

//     ds.add(arr[i]);
//     s+=arr[i];
//     f(i+1,ds,s)
//     ds.remove(arr[i]);
//     s-=arr[i];
//     f(i+1,ds,s);
// }

#include<bits/stdc++.h>
using namespace std;
void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
        // Base case: if we have processed all elements in arr
    if(ind==n){
        // Check if the current subset ds sums up to the required sum
        if(s==sum){
            // If yes, print the subset ds
            for(auto it:ds)
             cout<<it<<" ";
            cout<<endl;
        }
        return;
    } 
    // Recursive case: include arr[ind] in the subset
    ds.push_back(arr[ind]);   // Include arr[ind] in the current subset
    s+=arr[ind];     // Update the current sum s
    
    // Recursive call to process the next element (ind+1) and update state
    printS(ind+1, ds, s, sum, arr, n);

    // Backtrack: remove arr[ind] from the subset and update state
    s-=arr[ind];
    ds.pop_back();
    
    // Recursive call to not include arr[ind] in the subset
    //not pick
    printS(ind+1,ds,s,sum,arr,n);
}
int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;  // Vector to store the current subset
    // Call printS function with initial parameters
    printS(0,ds,0,sum,arr,n);

    return 0;
}


////Print any 1 subsequence whose sum is sum:

#include<bits/stdc++.h>
using namespace std;
bool flag=false;
void printS(int ind, vector<int> & ds, int s, int sum,int arr[], int n){
    if(ind==n){
        if(s== sum && flag==false){
            flag=true;
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    s+=arr[ind];

    printS(ind+1, ds, s,sum,arr,n);
    s-= arr[ind];
    ds.pop_back();

    //not pick
    printS(ind+1, ds,s,sum,arr,n);
}
int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;
    printS(0,ds,0,sum,arr,n);
    return 0;
}
//But this method is not preferred.

//Technique to print 1 answer.
//bool f(){
//base case
//condition: satisfied
// return(true);
//condition: not satisfied
//return false;
//if(f()==true)
//return true;
//f();
//return false;
//}

#include<bits/stdc++.h>
using namespace std;
bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    if(ind==n){
        //condition satisfied
        if(s==sum){
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        //condition not satisfied
        return false;
    }

    ds.push_back(arr[ind]);
    s+= arr[ind];

    if(printS(ind+1,ds,s,sum,arr,n)==true){
        return true;
    }
    s-=arr[ind];
    ds.pop_back();

    //not pick
    if(printS(ind+1,ds,s,sum,arr,n)==true) return true;

    return false;

}
int main(){
    int arr[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int> ds;
    printS(0,ds,0,sum,arr,n);
    return 0;
}
