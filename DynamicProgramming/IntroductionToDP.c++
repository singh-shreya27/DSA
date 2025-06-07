           //Dynamic Programming

#include<bits/stdc++.h>
using namespace std;
int f(int n, vector<int> &dp){
    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];  //step1
    return dp[n]=f(n-1,dp)+f(n-2,dp);  //step2
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);  //step3
    cout<< f(n,dp);
    return 0;
}
//T.C:O(n)
//S.C:O(n)+O(n) [recursion stack space + array]

//Recursion to Tabulation Format.[BOTTOM UP]
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
  vector<int> dp(n+1,-1);
  dp[0]=0;
  dp[1]=1; //base case
for(int i=2;i<=n;i++){
     dp[i]=dp[i-1]+dp[i-2];
}
   cout<<dp[n];
    return 0;
}

//T.C:O(n)
//S.C:O(n) No recursion stack space.

//SPACE OPTIMISATION:
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int prev2=0;
    int prev=1;
    for(int i=2;i<=n;i++){
        int cur_i=prev+prev2;
        prev2=prev;
        prev=cur_i;
    }
    cout<<prev;
    return 0;
}
//T.C:O(n)
//S.C:O(1)
