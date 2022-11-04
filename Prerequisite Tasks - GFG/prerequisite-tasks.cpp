//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prereq) {
	    // Code here
	    int indg[N] = {0};
	    vector<int>adj[N];
	    for(auto it: prereq){
	        adj[it.first].push_back(it.second);
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
	    
	    if(cnt != N) return false;
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends