class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int V, int s) {
        vector<pair<int,int>>adj[V];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        set<pair<int,int>>st;
        vector<int>dist(V);
        for(int i=0;i<V;i++) dist[i] = 1e9;
        
        
        dist[s-1] = 0;
        st.insert({0,s-1});
        while(!st.empty()){
            auto temp = *(st.begin());
            int dis = temp.first;
            int node = temp.second;
            st.erase(temp);
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;
                //cout<<adjNode<<" "<<edgeWt<<endl;
                if(dis + edgeWt< dist[adjNode]){
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis + edgeWt;
                    st.insert({dist[adjNode],adjNode});
                }
                
            }
        }
        int ans = 0;
        for(auto it: dist){
            if(it != 1e9){
                ans =  max(ans,it);
            }
            else return -1;
        }
        return ans;
    }
};