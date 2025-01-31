                           //Binary Search.

//Take a unique SORTED array.
//[3,4,6,7,9,12,16,17] ..find target=6 in this array.

//take two pointers: low=3, high=17..indexes are from 0 to 7
//so mid=0+7/2=3.5 ~3

//iterative code.
int binarySearch(vector<int> &nums, int target){
  int n=nums.size();
   int low=0,high=n-1; 
  while(low<=high){
    int mid=(low+high)/2;
    if(nums[mid] == target) return mid;
     else if(target > nums[mid]) low=mid+1;
       else  high=mid-1;
  }
  return -1;
}

//leetcode solution:
class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n=nums.size();
   int low=0,high=n-1; 
  while(low<=high){
    int mid=(low+high)/2;
    if(nums[mid] == target) return mid;
     else if(target > nums[mid]) low=mid+1;
       else  high=mid-1;
  }
  return -1;
    }
};

//recursive implementation:
int bs(vector<int> &nums, int low, int high, int target){
  if(low>high) return -1;
  int mid=(low+high) /2;
  if(nums[mid] == target) return mid;
  else if(target > nums[mid]) return bs(nums, mid+1,high,target)
    return bs(nums, low, high-1,target);
}

int search(vector<int> & nums, int target){
  return bs(nums, 0, nums.size()-1, target);
}

//T.C:O(log 2 n)

//overflow case:
//if the given search space is from 0 to INT_MAX then mid will be 2*INT_MAX, which cannot be stored.
//solution: use long long ,
//write mid as mid= low+(high-low)/2;
