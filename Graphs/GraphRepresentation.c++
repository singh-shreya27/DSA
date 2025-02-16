                   //Graph Representation
//INPUTS:
//Take the input of n :No. of nodes and m:No. of edges.

//m lines that will represent edges.

//How to store?
// Two ways to store:
//1.Matrix way  :adjacent matrix.
//2.List way.


//We need to store the edges so the future algorithms can be performed, this is where a MATRIX comes in.So check:
//Are the nodes 0 based or 1 based?
//Define a matrix of arr[n+1][n+1] and mark the places as 1 where we have edges(1,2 and 2,1 both ) and the rest as 0.
//Space used:n*n  , which is a costly thing.

                          //Storing a graph.
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  //1 based indexing
  int adj[n+1][m+1]; //if 0-based take adj[n][m]
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    //mark intersection as 1
    adj[u][v]=1;
    //mark reverse intersection as 1 as well
    adj[v][u]=1;

  }
//T.C:O(m)
//S.C:O(n^2)

//Optimising: ADJACENCY LIST:we use an array.
//e.g:
//n=5, 1 based:
//So we will use an array of [n+1] size.
//This array will contain a list.
//In c++, this list is : vector<int>
vector<int> adj[n+1] 
//defined as vector which means it contains empty list []

//MOTIF OF THE LIST:adjacent neighbours.
//Store all the adjacent neighbour of each node.
//Space :O(2*edges) for undirected graph

#include<bits/stdc++.h>
using namespace std;
int main(){

  int n,m;
  cin>>n>>m;
  vector<int>adj[n+1];
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    //for directed graph, edge between u---->v only
    adj[v].push_back(u);  //this line not needed for directed graph

  }
  return 0;
}
//T.C: O(edges)  for directed graph

//HOW TO STORE A WEIGHTED GRAPH:
//Here instead of writing 1 we need to store the resp weights.
//In matrix approach: change adj[u][v]=1 to
adj[u][v]=wt;
//In a list:
//We were storing only neighbours in this we here instead to storing only neighbours we will also store weights.
//so store in pairs:(node,wt)
//Define pair<int,int>
