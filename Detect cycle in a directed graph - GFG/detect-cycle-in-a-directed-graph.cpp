//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
//   bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
//       vis[node] = 1;
//       pathVis[node] = 1;
//       for(auto it: adj[node]){
//           if(!vis[it]){
//               if(dfs(it,adj,vis,pathVis)) return true;
//           }
//           else if(pathVis[it]) return true;
//       }
//       // remove from the path if the node is done
//       pathVis[node] = 0;
//       return false;
//   }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // 1st method - using dfs
        
        // int vis[V] = {0};
        // int pathVis[V] = {0};
        // for(int i=0;i<V;i++){
        //     if(dfs(i,adj,vis,pathVis)) return true;
        // }
        // return false;
        
        // 2nd method - using bfs - kahn's algo - topo sort
        int indegree[V] = {0};
	   for(int i=0;i<V;i++){
	       for(auto it: adj[i]){
	           indegree[it]++;
	       }
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++){
	       if(indegree[i] == 0) {
	           q.push(i);
	       }
	   }
	   
	   int temp = 0; // number of topo sort elements 
	   // if temp != V means there was a cycle and if temp == V means it was a DAG.
	   while(!q.empty()){
	       int node = q.front();
	       temp++;
	       q.pop();
	       for(auto it: adj[node]){
	           indegree[it]--;
	           if(indegree[it] == 0){
	               q.push(it);
	           }
	       }
	   }
	   //return ans;
	   if(temp != V) return true;
	   return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends