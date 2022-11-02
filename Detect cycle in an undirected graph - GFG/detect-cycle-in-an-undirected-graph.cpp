//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detectCycle(int src, vector<int>adj[], int vis[]){
        vis[src] = 1;
        queue<pair<int,int>>q; // pair<src,parent where it came from>
        q.push({src,-1});
        while(!q.empty()){
            int adjNode = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adj[adjNode]){
                if(!vis[it]){
                    q.push({it,adjNode});
                    vis[it] = 1;
                }
                else if(parent != it) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        // connected components
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycle(i,adj,vis) == true) return true;
            }
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