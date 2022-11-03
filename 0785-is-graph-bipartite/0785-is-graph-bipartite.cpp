class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>vis(V,-1);
	    queue<int>q;
	    
	    for(int i=0;i<V;i++){
	        if(vis[i] == -1){
	            q.push(i);
        	    vis[i] = 0;
	            while(!q.empty()){
        	        int node = q.front();
        	        q.pop();
        	        for(auto it:adj[node]){
        	            if(vis[it] == -1){
        	                vis[it] = 1-vis[node];
        	                q.push(it);
        	            }
        	            else{
        	                if(vis[node] == vis[it]) return false;
        	            }
        	        }
        	    }
	        }
	    }
	    
	    return true;
    }
};