//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        pq.push({0,1});
        
        vector<int>dist(n+1);
        for(int i=0;i<=n;i++) dist[i] = 1e9;
        dist[1] = 0;
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;
        
        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            for(auto temp: adj[node]){
                int adjNode = temp.first;
                int edgeWt = temp.second;
                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        
        // in case you are not able to reach n
        if(dist[n] == 1e9) return {-1};
        
        int node = n;
        vector<int>arr;
        while(parent[node] != node){
            arr.push_back(node);
            node = parent[node];
        }
        // necessary step
        arr.push_back(1);
        reverse(arr.begin(),arr.end());
        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends