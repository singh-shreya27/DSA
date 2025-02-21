         //Connected Components:

//Connected components in a graph are subsets of vertices such that there's a path between any two 
//vertices within the same subset, and no path exists between vertices in different subsets.


//Assume a traversal algorithmn.
//Any traversal you will alsways use a visited array.
//Visited array:
//Nodes =10 , edges=8
//Make an array of size 11.
//always run loop from 1 .
 for(i=1->10){
   if(!vis[i])
     traversal(i);
 }
