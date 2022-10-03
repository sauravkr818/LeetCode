class Solution {
public:
    int n = 0;
    
    bool canPartition(vector<int>& nums) {
        int N = nums.size();
        n = N;
        int totSum = 0;
        for(auto t: nums) totSum+= t; 
        if(totSum & 1 || n == 1) return false;
        int k = totSum/2;
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        
        for(int i=0;i<N;i++){
            dp[i][0] = true;
        }
        if(nums[0]<=k)
        dp[0][nums[0]] = true;
        
        for(int i=1;i<N;i++){
            for(int target = 1; target<=k; target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(nums[i]<=target){
                    take = dp[i-1][target-nums[i]];
                }

                dp[i][target] = take | notTake;
            }
        }
        return dp[n-1][k];
    }
};