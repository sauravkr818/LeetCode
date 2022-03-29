class Solution {
public:
    // Memoization + recursion
    
    // int f(int n, vector<int>&nums, vector<int>&dp){
    //     if(n == 0) return nums[n];
    //     if(n<0) return 0;
    //     if(dp[n] != -1) return dp[n];
    //     int pick = nums[n] + f(n-2,nums,dp);
    //     int not_pick = 0 + f(n-1,nums,dp);
    //     return dp[n] = max(pick,not_pick);
    // }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        // return f(n-1,nums,dp);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            // take
            int take = nums[i];
            if(i>1){
                take += dp[i-2];
            }
            //not_take
            int not_take = 0 + dp[i-1];
            
            // storing overlapping subproblems
            dp[i] = max(take,not_take);
        }
        return dp[n-1];
    }
};