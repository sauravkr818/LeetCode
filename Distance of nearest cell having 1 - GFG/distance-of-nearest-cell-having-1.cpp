//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>>ans(n, vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q; // {{i,j},step}
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j] == 1){
	                q.push({{i,j},0});
	            }
	        }
	    }
	    vector<int>delrow = {-1,0,1,0};
	    vector<int>delcol = {0,-1,0,1};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        //cout<<row<<" "<<col<<endl;
	        int step = q.front().second;
	        q.pop();
	        if(ans[row][col] == 0)
	        ans[row][col] = step;
	        for(int i=0;i<4;i++){
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
	            && grid[nrow][ncol] == 0 && ans[nrow][ncol] == 0){
	                q.push({{nrow,ncol},step+1});
	            }
	        }
	        
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends