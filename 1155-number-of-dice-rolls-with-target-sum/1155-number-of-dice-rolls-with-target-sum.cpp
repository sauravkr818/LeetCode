class Solution {
public:
    const static int MOD = 1e9+7;
    int f(int i, int j, int target,vector<vector<int>>&dp){
        // base case
        if(i == 0 && target == 0) return 1;
        if(target<=0 || i<=0) return 0;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int sum = 0;
        for(int m=1;m<=j;m++){
            sum += f(i-1,j,target-m,dp);
            sum = sum%MOD;
        }
        return dp[i][target] = sum%MOD;  
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(n,k,target,dp);
    }
};