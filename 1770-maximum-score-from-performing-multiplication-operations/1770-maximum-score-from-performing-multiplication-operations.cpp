class Solution {
public:
    int f(int i,int k,vector<int>&nums,vector<int>&mul,vector<vector<int>>&dp){
        // base cases
        if(i>=nums.size() || i>=mul.size() || k>=mul.size()) return 0;
        
        if(dp[i][k] != INT_MIN) return dp[i][k];
        
        int j = nums.size() - 1 - (k - i);
        int start = (nums[i] * mul[k]) + f(i+1,k+1,nums,mul,dp);
        int end = (nums[j] * mul[k]) + f(i,k+1,nums,mul,dp);
        return dp[i][k] = max(start,end);
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size();
        int m = mul.size();
        int i = 0;
        int k = 0;
        vector<vector<int>>dp(m,vector<int>(m,INT_MIN));
        return f(i,k,nums,mul,dp);
    }
};