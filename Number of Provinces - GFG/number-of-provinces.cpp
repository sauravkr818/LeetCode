//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(int node, vector<int>adj[], vector<bool>&vis){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    
  public:
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjL[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i != j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        vector<bool>vis(V,false);
        int count = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,adjL,vis);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends