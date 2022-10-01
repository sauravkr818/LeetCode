class Solution {
public:
    int f(int i, int n, string &s,vector<int>&dp){
        // base case
        if(i == n) return 1;
        if(s[i] == '0') return 0;
        
        if(dp[i] != -1) return dp[i];
        // pick single
        int single = f(i+1,n,s,dp);
        
        // pick 2 letters or couple
        int coupl = 0;
        if(i+1<n && ((s[i] == '1' && s[i+1] <= '9') || (s[i] == '2' && s[i+1] <='6'))){
            coupl = f(i+2,n,s,dp);
        }
        return dp[i] = single + coupl;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,n,s,dp);
    }
};