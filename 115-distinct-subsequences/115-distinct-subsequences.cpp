class Solution {
public:
    // memoization + recursion
    int f(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        // base cases
        
        // -------------------------------------------
        // if(j<0 means we have exhausted our t string which means we have find an occurance of string t in string s therefore return 1)
        if(j<0) return 1;
        
        // -------------------------------------------
        // if(i<0) it means in finding of string t in string s we have exhausted our string s hence return 0 saying it is not possible to find with such i and j
        if(i<0) return 0;
        
        // -----------------------------------------
        if(dp[i][j] != -1) return dp[i][j];
        
        // -----------------------------------------
        // explore all possibilities
        
        // match
        if(s[i] == t[j]){
            return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
        }
        else return dp[i][j] = f(i-1,j,s,t,dp);
        
        
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // vector<vector<int>>dp(n, vector<int>(m,-1));
        // return f(n-1,m-1,s,t,dp);
        
        
        
        // ------------- tabulation -----------------------
        
//         vector<vector<double>>dp(n+1, vector<double>(m+1,0));
        
//         for(int i=0;i<=n;i++){
//             dp[i][0] = 1;
//         }
        
//         // just to not overwrite the values written by above for loop , start j from 1
//         for(int j=1;j<=m;j++){
//             dp[0][j] = 0;
//         }
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
//                 else dp[i][j] = dp[i-1][j];
//             }
//         }
        
//         return (int)dp[n][m];
        
        
        
        // ----------------- tabulation + space optimisation to 2 1D array
        
        
        vector<double>prev(m+1,0),cur(m+1,0);
        
        prev[0] = 1;
        cur[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]) cur[j] = prev[j-1] + prev[j];
                else cur[j] = prev[j];
            }
            prev = cur;
        }
        
        return (int)prev[m];
        
    
        
    }
};