//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  void dfs(int u, vector<pair<int,int>>adj[], vector<bool>&vis, stack<int>&st){
      vis[u] = true;
      for(auto it: adj[u]){
          if(!vis[it.first]){
              dfs(it.first,adj,vis,st);
          }
      }
      st.push(u);
      return;
  }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        stack<int>st;
        vector<bool>visited(N,0);
        vector<pair<int,int>>adj[N];
        
        // adj[] list
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        // find the topo sort - O(N+M)
        // Why topo sort - because we reach that node which comes first with no node it is dependent on means no edge dependent on
        // And therefore with topo sort, we reach node on the basis of their reachibility. The node which have longer path to reach comes later
        // and hence should be computer later
        for(int i=0;i<N;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        vector<int>dist(N, 1e9);
        
        int src = 0;
        dist[src] = 0;
        
        // Time - O(N+M)
         while(st.empty() == false){
            int u = st.top();
            st.pop();
            for(auto it: adj[u]){
                if(dist[it.first]> dist[u]+ it.second){
                    dist[it.first] = dist[u] + it.second;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends