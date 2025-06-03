               //Subset Sum

//Total number of subsets that we can generate is 2^n.

//Brute force approach:
//Using power set.->T.C:o(2^n *N) 
//so optimise .


//Optimal approach:
 //we are choosing which elements to take in subset.

class Solution
{
public:
void func(int ind, int sum, vector<int> 7arr, int N, vector<int>&sumSubset){
  if(ind==N){
    sumSubset.push_back(sum);
    return;
  }
  //pick the element
  func(ind+1,sum+arr[ind],arr,N,sumSubset);

  //do not pick the element
  func(ind+1, sum, arr,N,sumSubset);
}
public:
vector<int> subsetSums(vector<int> arr, int N){
  vector<int> sumSubset;
  func(0,0,arr,N,sumSubset);
  sort(sumSubset.begin(),sumSubset.end());
  return sumSubset;
}
};
