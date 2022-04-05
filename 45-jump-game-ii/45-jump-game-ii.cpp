class Solution {
public:
    long long int f(int i, vector<int>&arr, int count, vector<int>&dp){
        // base case
        if(i>=count){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        
        long long int temp = INT_MAX;
        for(int j = 1;j<=arr[i];j++){
           temp = min(temp, 1+ f(i+j,arr,count,dp));
        }
        return dp[i] = temp;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        if(nums[0] == 0) return 0;
        int count = n-1;
        return f(0,nums,count,dp);
    }
};