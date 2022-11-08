//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    // using priority queue
    
    // vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    // {
    //     // Code here
    //     // min-heap
    //     priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq; // pair<dist,node>
    //     vector<int>dist(V);
    //     for(int i=0;i<V;i++) dist[i] = 1e9;
        

    //     dist[s] = 0;
    //     pq.push({0,s});
    //     while(!pq.empty()){
    //         int node_dist = pq.top().first;
    //         int node = pq.top().second;
    //         pq.pop();
    //         for(auto it: adj[node]){
    //             // it[0] = adjacent node
    //             // it[1] = edgeWeight req to reach node to adj node it
    //             if(node_dist + it[1]< dist[it[0]]){
    //                 dist[it[0]] = node_dist + it[1];
    //                 pq.push({dist[it[0]], it[0]});
    //             }
    //         }
    //     }
    //     return dist;
    // }
    
    // using set
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        // min-heap
        set<pair<int,int>>st;
        vector<int>dist(V);
        for(int i=0;i<V;i++) dist[i] = 1e9;
        
        
        dist[s] = 0;
        st.insert({0,s});
        while(!st.empty()){
            auto temp = *(st.begin());
            int dis = temp.first;
            int node = temp.second;
            st.erase(temp);
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                
                if(dis + edgeWt< dist[adjNode]){
                    // erase if someone already visited the adjNode
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis + edgeWt;
                    st.insert({dist[adjNode],adjNode});
                }
                
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends