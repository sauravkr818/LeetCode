class Solution {
public:
    // recursion + memoization gives tle 
    // see solution of leetcode
    int f(int n, int k, vector<vector<int>>&dp){
        if(n == 0) return 0;
        if(k == 0) return 1;
        if(dp[n][k] !=-1) return dp[n][k];
        int inv = 0;
        for(int i=0;i<=min(k,n-1);i++){
            inv = (inv + f(n-1,k-i,dp))% 1000000007;
        }
        return dp[n][k] = inv;
    }
    
    int kInversePairs(int n, int k) {
        // vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        // return f(n,k,dp);
        vector<int> dp(k+1, 0);
        int mod = 1e9+7;
        for(int i=1; i<=n; i++){
            vector<int> tmp(k+1, 0);
            tmp[0] = 1;
            for(int j =1; j<=k; j++){
                long long val = (dp[j] + mod - ((j-i) >=0 ? dp[j-i] : 0))%mod;
                tmp[j] = (tmp[j-1] + val)%mod;
            }
            dp = tmp;
        }
        return (dp[k] + mod - (k>0 ? dp[k-1] : 0))%mod;
    }
};