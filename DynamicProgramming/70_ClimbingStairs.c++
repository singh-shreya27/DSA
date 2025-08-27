                //Climbing stairs

        //Recursive approach
class Solution {
public:
    int f(int ind){
        if(ind==0 || ind==1) return 1;
        return f(ind-1)+f(ind-2);
    }
    int climbStairs(int n) {
       return f(n);
    }
};

//TLE when submiting:
// Recursive approach is giving TLE (Time Limit Exceeded) because of the huge number of repeated calls in the recursion tree.
//For large n (like n = 40 or more), this grows exponentially.
//The time complexity is O(2^n).
// Why TLE happens
// LeetCode has strict time limits (usually ~1 second).
// For n = 45, your recursion will make billions of calls → too slow → TLE.


//Memoization approach:
class Solution {
public:
    int f(int ind, vector<int> &dp){

        if(ind==0 || ind==1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=f(ind-1,dp)+f(ind-2,dp);
    }

    int climbStairs(int n) {
      vector<int> dp(n+1,-1);
       return f(n,dp);
    }
};

//Tabulation apparoach:
class Solution{
    public:
    int climbStairs(int n){
        vector<int> dp(n+1,-1);
        if(n==0 || n==1) return 1;
        dp[0]=1;
        dp[1]=1;
        for(int ind=2;ind<=n;ind++){
           dp[ind]=dp[ind-1]+dp[ind-2];
        }
        return dp[n];
    }
};

//Space optimization:
class Solution{
    public:
    int climbStairs(int n){
        if(n==0 || n==1) return 1;
      int prev2=1;
      int prev=1;
      
      for(int ind=2;ind<=n;ind++){
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
      }
      return prev;
    }
};
