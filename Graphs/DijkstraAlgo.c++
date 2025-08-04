                  //Dijkstra Algorithm
//USING PRIORITY QUEUE.

class Solution{
public:
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
  //declare a priority queue
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(V);
  for(int i=0;i<V;i++) dist[i]=1e9;

  dist[S]=0;
  pq.push({0,S}); //(dist, source)

  while(!pq.empty()){
    int dis=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto it: adj[node]){
      int edgeWeight=it[1];
      int adjNode=it[0];

      if(dis + edgeWeight<dist[adjNode]){
        dist[adjNode]= dis + edgeWeight;
        pq.push({dist[adjNode],adjNode});
      }     
    }
  }
  return dist;
  }
};

//T.C:O(E*logV)
//Dijkstra does not works in any graph having negative weights and negative cycles.

//USING SET data structure.
//set is used to erase already existing paths.
//set.erase() takes logarithmic time complexity 
//so not saving much on T.C.
//set stores unique values and the smallest at the top and everything in ascending order.

class Solution{
 public:
vector<int> dijkstra(int V, vector<vector<int>> aadj[], int S){
  set<pair<int,int>> st;
  vector<int> dist(V,1e9);

  st.insert({0,S});
  dist[S]=0;

  while(!st.empty()){
    auto it: *(st.begin());
    int node=it.second;
    int dis=it.first;
    st.erase(it);    

    for(auto it: adj[node]){
      int adjNode=it[0];
      int edgW=it[1];

      if(dis+edgW<dist[adjNode){
        //erase it it existed
        if(dist[adjNode]!=1e9)
          st.erase({dist[adjNode], adjNode});

        dist[adjNode]= dis+edgW;
        st.insert({dist[adjNode], adjNode});  
      }
    }
  }
  return dist;
 }
};
