class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || vis[row][col] == 1 || grid[row][col] == 0) return;
        
        vis[row][col] = 1;
        
        dfs(row+1,col,grid,vis);
        dfs(row-1,col,grid,vis);
        dfs(row,col+1,grid,vis);
        dfs(row,col-1,grid,vis);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            // first row
            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(0,i,grid,vis);
            }
            
            // last row
            if(grid[m-1][i] == 1 && !vis[m-1][i]){
                dfs(m-1,i,grid,vis);
            }
        }
        
        for(int i=0;i<m;i++){
            // first col
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            
            // last col
            if(grid[i][n-1] == 1 && !vis[i][n-1]){
                dfs(i,n-1,grid,vis);
            }
        }
        
        
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};