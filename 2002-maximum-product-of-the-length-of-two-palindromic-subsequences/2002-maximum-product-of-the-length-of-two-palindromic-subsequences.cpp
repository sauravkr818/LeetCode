class Solution {
public:
    
    int lcs(string s)
    {
        //Write your code here
        string t = s;
        reverse(s.begin(),s.end());
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        unordered_set<string>st;
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }

        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }

        int a = 0, b = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // matches
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
    
    
    int maxProduct(string s) {
        
        
        int ans=0;
        int n=s.size();
        for(int i=1;i<(1<<n)-1;i++)
        {
            string s1="",s2="";
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    s1.push_back(s[j]);
                }
                else
                {
                    s2.push_back(s[j]);
                }
            }
            
            ans=max(ans,lcs(s1)*lcs(s2));
        }
        return ans;
        
        
        //return lcs(s,t);
    }
};