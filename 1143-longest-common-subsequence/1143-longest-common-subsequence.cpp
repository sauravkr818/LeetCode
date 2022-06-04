class Solution {
public:
    
    int f(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        // base case
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        // match condition
        if(s[i] == t[j]) return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);

        // not_match condition
        return dp[i][j] = 0 + max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,text1,text2,dp);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int j = 0;j<=m;j++){
            dp[0][j] = 0;
        }
        
        for(int i = 0;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // match condition
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];

                // not_match condition
                else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};