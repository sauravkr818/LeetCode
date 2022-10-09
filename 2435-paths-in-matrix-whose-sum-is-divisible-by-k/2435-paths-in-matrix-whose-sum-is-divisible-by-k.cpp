class Solution {
public:
    const static int MOD = 1e9 + 7;
    int f(int i, int j, vector<vector<int>>& grid, int k, int sum, vector<vector<vector<int>>>&dp){
        if(i<0 || j<0) return 0;
        if(i == 0 && j == 0){
            if((sum+grid[0][0]) % k == 0) return 1;
        }
        if(dp[i][j][(sum)%k] != -1) return dp[i][j][sum%k];
        
        int left = f(i,j-1,grid,k, sum + grid[i][j],dp);
        int up = f(i-1,j,grid,k, sum + grid[i][j],dp);
        
        return dp[i][j][sum%k] = (left + up)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return f(n-1,m-1,grid,k,0,dp) % MOD;
    }
};