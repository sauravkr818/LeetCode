class Solution {
public:
   long long int f(int i, int j,vector<vector<int>>& grid,vector<vector<long long int>>& dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0||j<0) return INT_MAX;
        if( dp[i][j] != -1) return dp[i][j];
       
        long long int up = f(i-1,j,grid,dp) + grid[i][j];
        long long int left = f(i,j-1,grid,dp) + grid[i][j];
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        long long int m = grid.size();
        long long int n = grid[0].size();
        vector<vector<long long int>>dp(m,vector<long long int>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};