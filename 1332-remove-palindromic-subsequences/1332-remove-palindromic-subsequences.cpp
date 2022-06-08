class Solution {
public:
    
    int lcs(string &s, string &t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int removePalindromeSub(string s) {
        string t = s;reverse(s.begin(),s.end());
        int ans = lcs(s,t);
        cout<<lcs(s,t)<<endl;
        return ans == s.size() ? 1 : 2;
        
        // string st=s;
        // reverse(st.begin(),st.end());
        // if(st==s){
        //     return 1;
        // }return 2;
    }
};