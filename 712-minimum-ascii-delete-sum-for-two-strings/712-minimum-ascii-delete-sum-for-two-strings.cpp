class Solution {
public:
    
    int lcs(string s, string t)
    {
        //Write your code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }

        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        
        int ans = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // matches
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + (int)(s[i-1]);
                    //ans++;
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        for(char &a: s){
            ans += (int)(a);
        }
        for(char &a: t){
            ans += (int)(a);
        }
        return ans-2*dp[n][m];
    }
    
    int minimumDeleteSum(string s1, string s2) {
        return lcs(s1,s2);
    }
};