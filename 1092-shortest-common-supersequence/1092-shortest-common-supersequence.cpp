class Solution {
public:
    string lcs(string &text1, string &text2) {
        int n = text1.size();
        int m = text2.size();
        string ans = "";
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
        
        int i = n, j = m;
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                ans += text1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans += text1[i-1];
                i--;
            }
            else{
                ans += text2[j-1];
                j--;
            }
        }
        while(i>0){
            ans += text1[i-1];
            i--;
        }
        while(j>0){
            ans += text2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        return lcs(str1,str2);
    }
};