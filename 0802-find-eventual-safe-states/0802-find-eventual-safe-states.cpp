class Solution {
private:
  bool dfs(int node, vector<vector<int>>& adj, vector<int>&vis, vector<int>&pathVis, vector<int>&check){
      vis[node] = 1;
      pathVis[node] = 1;
      check[node] = 0;
      for(auto it: adj[node]){
          if(!vis[it]){
              if(dfs(it,adj,vis,pathVis,check)) {
                  // detected a cycle hence not a safe node
                  check[node] = 0;
                  return true;
              }
          }
          else if(pathVis[it]) {
                // detected a cycle hence not a safe node
                check[node] = 0;
                return true;
          }
      }
      // not detected a cycle hence a safe node
      check[node] = 1;
      // remove from the path if the node is done
      pathVis[node] = 0;
      return false;
  }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>check(V,0);
        for(int i=0;i<V;i++){
            dfs(i,adj,vis,pathVis,check);
        }
        
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};