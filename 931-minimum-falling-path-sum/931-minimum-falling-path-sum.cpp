class Solution {
public:
    
    int f(int i,int j, vector<vector<int>>&matrix, int m, int n, vector<vector<int>>&dp){
        // base cases
        if(i == n-1 && j>=0 && j<m) return matrix[i][j];
        if(i>=n || j<0 || j>=m) return 1e8;
        if(dp[i][j] != -1) return dp[i][j];
        // below
        int below = matrix[i][j] + f(i+1,j,matrix,m,n,dp);
        // left diagnoal
        int left = matrix[i][j] + f(i+1,j-1,matrix,m,n,dp);
        // right diagonal
        int right = matrix[i][j]+f(i+1, j+1,matrix,m,n,dp);
        return dp[i][j] = min(below, min(left, right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // number of rows
        int m = matrix[0].size(); // number of cols
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        int ans = 100000;
        for(int i=0;i<m;i++){
            ans = min(ans,f(0,i,matrix,m,n,dp));
        }
        return ans;
    }
};