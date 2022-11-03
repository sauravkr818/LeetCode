//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    
    void dfs(int row, int col, vector<vector<int>>&grid, 
    vector<vector<int>>&vis, vector<pair<int,int>>&arr, int row0, int col0){
        vis[row][col] = 1;
        arr.push_back({row-row0,col-col0});
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,grid,vis,arr,row0,col0);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    // dfs(row,col,grid,vis,base, base)
                    // using base to convert and check whether the different islands are same or not
                    vector<pair<int,int>>arr;
                    dfs(i,j,grid,vis,arr,i,j);
                    st.insert(arr);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends