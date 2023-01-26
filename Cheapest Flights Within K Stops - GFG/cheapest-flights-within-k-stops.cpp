//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // [IMP QUESION] - because here queue does not depends upon price rather than it depends upon stops.,
    // Time Complexity - O(ElogV) but since we are not using priority_queue hence we can erase logV part
    // hence T.C. - O(E);
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        // Innthis question priority queue will be sorted according to stops
        // since stops will be increasing by one hence there is no use of priority queue
        // we can use queue instead
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q; // {stops,{node,price}}
        vector<int>dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;
            
            if(stops>k) continue; // if stops exceeds the given max stop then no need to go further node
            
            for(auto temp: adj[node]){
                int adjNode = temp.first;
                int newPrice = temp.second;
                if(price + newPrice < dist[adjNode] && stops<=k){
                    dist[adjNode] = price + newPrice;
                    q.push({stops+1,{adjNode,price + newPrice}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends