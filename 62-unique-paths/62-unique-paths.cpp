class Solution {
public:
    // memoization + recursion
    int f(int i, int j, vector<vector<int>>&dp){
        if(i == 0 && j == 0) return 1;
        if( i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = f(i-1,j,dp);
        int left = f(i,j-1,dp);
        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,dp);
        
        // tabulation
        // vector<vector<int>>dp(m,vector<int>(n,0));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i == 0 && j == 0) dp[i][j] = 1;
        //         else{
        //             int up = 0;
        //             int left = 0;
        //             if(i>0) up = dp[i-1][j];
        //             if(j>0) left = dp[i][j-1];
        //             dp[i][j] = up+left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];
        
        // tabulation + space optimisation
        vector<int>prev(n,1), cur(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(i==0 && j ==0) cur[j] = 1;
                else{
                    int up,left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = cur[j-1];
                    cur[j] = up+left;
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};