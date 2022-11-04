class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int N = numCourses;
        vector<int>indg(N,0);
	    vector<int>adj[N];
	    for(auto it: prereq){
            int a = it[0], b = it[1];
	        adj[a].push_back(b);
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
	    
	    int cnt = 0;
	    while(!q.empty()){
	        int node = q.front();
	        cnt++;
	        q.pop();
	        for(auto it: adj[node]){
	            indg[it]--;
	            if(indg[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    if(cnt != numCourses) return false;
	    return true;
    }
};