class Solution {
public:
    
    int f(int i, int j, string &s1, string &s2,vector<vector<double>>&dp){
        // base cases
        if(i<0) return j+1;
        
        if(j<0) return i+1;
        
        
        if(dp[i][j] != -1) return dp[i][j];
        //matching
        if(s1[i] == s2[j]) return dp[i][j] = 0 + f(i-1,j-1,s1,s2,dp);
        else{
            // insert + delete + replace
            return dp[i][j] = (int) min( 1 + f(i,j-1,s1,s2,dp), min( 1 + f(i-1,j,s1,s2,dp), 1 + f(i-1,j-1,s1,s2,dp) ));
        }
    }
    
    
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // vector<vector<double>>dp(n, vector<double>(m,-1));
        // return (int) f(n-1,m-1,word1,word2,dp);
        
        
        vector<vector<double>>dp(n+1, vector<double>(m+1,0));
        
        for(int j=0;j<=m;j++){
            dp[0][j] = j;
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }
        
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else{
                    dp[i][j] = min( 1 + dp[i][j-1], 
                                   min( 1 + dp[i-1][j], 1 + dp[i-1][j-1] ));
                }
            }
        }
        return dp[n][m];
    }
};