class Solution {
public:
    
    int mod = 1000000007;
    int f(int m, int n, int maxMove, int i, int j,vector<vector<vector<int>>>&dp){
        // base case
        
        
        if((i<0 || i>=m || j<0 || j>=n)){
            return 1;
        }
        if(maxMove == 0) return 0;
        
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        return dp[i][j][maxMove] = ((f(m,n,maxMove-1,i,j+1,dp) + f(m,n,maxMove-1,i,j-1,dp))%mod + (f(m,n,maxMove-1,i+1,j,dp) + f(m,n,maxMove-1,i-1,j,dp))%mod)%mod;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return f(m,n,maxMove,startRow,startColumn,dp);
    }
};