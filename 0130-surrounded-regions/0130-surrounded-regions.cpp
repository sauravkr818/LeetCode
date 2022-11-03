class Solution {
public:
    
    void dfs(int row, int col, vector<vector<char>>&mat, vector<vector<int>>&vis){
         // base case
        if(row<0 || col<0 || row>=mat.size() || col>=mat[0].size()) return;
        if(mat[row][col] == 'X') return;
        if(vis[row][col] == 1) return;
        
        vis[row][col] = 1;
        
        // four direction
        dfs(row+1,col,mat,vis);
        dfs(row-1,col,mat,vis);
        dfs(row,col+1,mat,vis);
        dfs(row,col-1,mat,vis);
    }
    
    
    void solve(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){ // 1st row all cols
            if(!vis[0][i])
            dfs(0,i,mat,vis);
        }
        for(int i=0;i<n;i++){ // 1st col all rows
            if(!vis[i][0])
            dfs(i,0,mat,vis);
        }
        for(int i=0;i<m;i++){ // last row all cols
            if(!vis[n-1][i])
            dfs(n-1,i,mat,vis);
        }
        for(int i=0;i<n;i++){ // last col and all rows
            if(!vis[i][m-1])
            dfs(i,m-1,mat,vis);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O' && vis[i][j] == 0){
                    mat[i][j] = 'X';
                }
            }
        }
    }
};