class Solution {
public:
    bool dfs(int src,int col, vector<int>&vis, vector<vector<int>>& adj, int V){
        vis[src] = col;
        for(auto node: adj[src]){
            if(vis[node] == -1){
                if(dfs(node,!col,vis,adj,V) == false) return false;
            }
            else if(vis[node] == col) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>vis(V,-1);
        for(int i=0;i<V;i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(dfs(i,0,vis,adj,V) == false){
                    return false;
                }
            }
        }
        return true;
        
        // -- bfs --
// 	    queue<int>q;
	    
// 	    for(int i=0;i<V;i++){
// 	        if(vis[i] == -1){
// 	            q.push(i);
//         	    vis[i] = 0;
// 	            while(!q.empty()){
//         	        int node = q.front();
//         	        q.pop();
//         	        for(auto it:adj[node]){
//         	            if(vis[it] == -1){
//         	                vis[it] = 1-vis[node];
//         	                q.push(it);
//         	            }
//         	            else{
//         	                if(vis[node] == vis[it]) return false;
//         	            }
//         	        }
//         	    }
// 	        }
// 	    }
	    
// 	    return true;
    }
};