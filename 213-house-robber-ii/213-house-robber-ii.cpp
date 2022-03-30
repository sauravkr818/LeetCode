class Solution {
public:
    
    // f function is same as house robber I
    int f(int n, vector<int>&dp, vector<int>&nums){
        if(n == 0) return nums[n];
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int take = nums[n] + f(n-2,dp,nums);
        int non_take = 0 + f(n-1,dp,nums);
        return dp[n] = max(take,non_take);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>temp,temp2;
        for(int i=0;i<n;i++){
            if(i != 0) temp.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        vector<int>dp(temp.size(),-1);
        vector<int>dp1(temp2.size(),-1);
        return max(f(temp.size()-1,dp,temp), f(temp2.size()-1,dp1,temp2));
    }
};