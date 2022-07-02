class Solution {
public:
    
    int f(int ind, int prev_ind, vector<int>&arr, int n, vector<vector<int>>&dp){
    // base cases
    if(ind == n) return 0;
    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
    int not_take = 0; // not_take case
    not_take = 0 + f(ind+1,prev_ind,arr,n,dp);

    int take = 0; // take case
    if(prev_ind == -1 || arr[ind]>arr[prev_ind]){
    take = 1 + f(ind+1, ind, arr, n,dp);
    }
    return dp[ind][prev_ind+1] = max(take, not_take);
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};