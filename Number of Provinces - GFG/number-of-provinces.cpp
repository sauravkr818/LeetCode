//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int i, vector<int>adj[], vector<int>&vis){
        // base case
        vis[i] = 1;
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int n = adj.size(), m = adj[0].size();
        int count = 0;
        vector<int>vis(V,0);
        vector<int>Adj[V];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i != j && adj[i][j] == 1){
                    Adj[i].push_back(j);
                    Adj[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(i,Adj,vis);
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