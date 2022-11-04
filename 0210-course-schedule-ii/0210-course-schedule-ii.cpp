class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        int N = numCourses;
        vector<int>indg(N,0);
	    vector<int>adj[N];
	    for(auto it: prereq){
            int a = it[0], b = it[1];
	        adj[b].push_back(a); // reverse egde
	    }
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        for(auto it: adj[i]){
	            indg[it]++;
	        }
	    }
	    
	    for(int i=0;i<N;i++){
	        if(indg[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int>topo;
	    while(!q.empty()){
	        int node = q.front();
	        topo.push_back(node);
	        q.pop();
	        for(auto it: adj[node]){
	            indg[it]--;
	            if(indg[it] == 0){
	                q.push(it);
	            }
	        }
	    }
        if(topo.size() == numCourses)
	    return topo;
        else return {};
    }
};