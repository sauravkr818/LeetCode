class Solution {
public:
    
    int f(int row, int col, vector<vector<int>>&grid){
        // base case
        if(row == grid.size()) return col;
        // case - 1 : if the ball falls to right then check for the next adj col
        // that is if diagonal is right at grid[row][col] then look for grid[row][col+1]
        
        if(grid[row][col] == 1){// right diagonal 
            int nextCol = col+1;
            if(nextCol<grid[0].size() && grid[row][col] == grid[row][col+1]){
                return f(row+1,nextCol,grid);
            }
            else return -1;
        }
        else if (grid[row][col] == -1){ // case-2: left diagonal
            int nextCol = col-1;
            if(nextCol>=0 &&  grid[row][col] == grid[row][nextCol]){
                return f(row+1,nextCol,grid);
            }
            else return -1;
       }
        return 0;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i] = f(0,i,grid);
        }
        return ans;
    }
};