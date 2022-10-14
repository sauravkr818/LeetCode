//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int u, vector<int>adj[], vector<bool>&visited, vector<bool>&recSt){
        visited[u] = true;
        recSt[u] = true;
        for(auto v: adj[u]){
            if(visited[v] == false){
                if(dfs(v,adj,visited,recSt)) return true;
            }
            else if(recSt[v] == true) return true;
        }
        recSt[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V+1,false);
        vector<bool>recSt(V+1,false);
        for(int i=0;i<V;i++){
            if(visited[i] == false){
                if(dfs(i,adj,visited,recSt)) return true;
            }
        }
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