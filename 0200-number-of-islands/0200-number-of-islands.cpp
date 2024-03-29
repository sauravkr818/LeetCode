class Solution {
public:
    
    private:
    
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid){
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int m = grid.size();
        int n = grid[0].size();
        while(q.empty() == false){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int deltarow=-1;deltarow<=1;deltarow++){
                for(int deltacol = -1; deltacol<=1;deltacol++){
                    int newrow = row + deltarow;
                    int newcol = col + deltacol;
                    if(abs(deltarow) != abs(deltacol) && newrow>=0 && newrow<m && newcol>=0 && newcol<n &&
                    !vis[newrow][newcol] && grid[newrow][newcol] == '1'){
                        vis[newrow][newcol] = 1;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
        
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
        
    }
};