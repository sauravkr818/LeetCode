//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int src, vector<int> adj[], int V, int parent, vector<int>&vis){
        vis[src] = 1;
        for(auto it: adj[src]){
            if(!vis[it]){
                if(dfs(it,adj,V,src,vis)) return true;
            }
            else if(it != parent){
                return true;
            }
        }
        return false;
        
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // bfs
        // vector<int>vis(V,0);
        // for(int i=0;i<V;i++){ // loop for connected components
        //     if(!vis[i]){
        //         queue<pair<int,int>>q;
        //         q.push({i,-1});
        //         vis[i] = 1;
        //         while(!q.empty()){
        //             int node = q.front().first;
        //             int parent = q.front().second;
        //             q.pop();
        //             for(auto child: adj[node]){
        //                 if(!vis[child]){
        //                     q.push({child,node});
        //                     vis[child] = 1;
        //                 }
        //                 else if(child != parent){
        //                     return true;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return false;
        


        //dfs
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                if(dfs(i,adj,V,-1,vis)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends