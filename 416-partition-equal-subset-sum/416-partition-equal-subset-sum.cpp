class Solution {
public:
    int n = 0;
    bool f(int i, vector<int>&nums, int target, vector<vector<int>>&dp){
        // base cases
        if(target == 0) return true;
        if(i == 0) return (nums[0] == target);
        
        
        if(dp[i][target] != -1) return dp[i][target];
        
        bool notTake = f(i-1,nums,target,dp);
        bool take = false;
        if(nums[i]<=target){
            take = f(i-1,nums,target-nums[i],dp);
        }
        
        return dp[i][target] = take | notTake;
        
    }
    
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        n = N;
        int totSum = 0;
        for(auto t: nums) totSum+= t; 
        if(totSum & 1) return false;
        vector<vector<int>>dp(N,vector<int>((totSum/2)+1,-1));
        return f(n-1,nums,totSum/2,dp);
    }
};