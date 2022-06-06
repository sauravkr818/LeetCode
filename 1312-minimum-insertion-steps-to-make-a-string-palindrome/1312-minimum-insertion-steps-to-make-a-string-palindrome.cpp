class Solution {
public:
    
    // pre-req - DP-25, DP-26, DP-27, DP-28 - takeuforward DP series by Striver

int lcs(string s, string t)
{
    //Write your code here
    int n = s.size();
    int m = t.size();
    //return f(n-1,m-1,s,t,dp);
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // matches
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

    int minInsertions(string &str){
        // Write your code here.
        string t = str;
        reverse(str.begin(),str.end());
        return str.size() - lcs(str,t);
    }
};