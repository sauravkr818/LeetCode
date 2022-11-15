class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>ways(n,0); ways[0] = 1;
        
        vector<long long>dist(n,1e18);
        dist[0] = 0;
        
        // {dist,node}
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;
        
        pq.push({0,0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            auto it = pq.top();pq.pop();
            
            long long node = it.second;
            long long time = it.first;
            for(auto temp: adj[node]){
                long long adjNode = temp.first;
                long long edgeWt = temp.second;
                if(edgeWt + time < dist[adjNode]){ // First time arriving
                    dist[adjNode] = edgeWt + time;
                    pq.push({edgeWt+time,adjNode});
                    ways[adjNode] = ways[node];
                }
                // important code
                else if(edgeWt + time == dist[adjNode]){ // if same shortest can distance occur
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};