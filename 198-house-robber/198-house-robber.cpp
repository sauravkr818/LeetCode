class Solution {
public:
    // Method - 1 = Recursion
    // Method - 2 = Memoization (Top-down) + Recursion
    // Method - 3 = Tabulation (Bottom-up)
    // Method - 4 = Tabulation + Space Optimisation
    
    // Memoization + recursion
    // T.C. = O(n) and S.C. = O(n) + O(n)
    // int f(int n, vector<int>&nums, vector<int>&dp){
    //     if(n == 0) return nums[n];
    //     if(n<0) return 0;
    //     if(dp[n] != -1) return dp[n];
    //     int pick = nums[n] + f(n-2,nums,dp);
    //     int not_pick = 0 + f(n-1,nums,dp);
    //     return dp[n] = max(pick,not_pick);
    // }
    
    // int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>dp(n,0);
        // recursion fn call
        // return f(n-1,nums,dp);
        
        // tabulation 
        // T.C. = O(n) and S.C. = O(n)
        
//         dp[0] = nums[0];
//         for(int i=1;i<n;i++){
//             // take
//             int take = nums[i];
//             if(i>1){
//                 take += dp[i-2];
//             }
//             //not_take
//             int not_take = 0 + dp[i-1];
            
//             // storing overlapping subproblems
//             dp[i] = max(take,not_take);
//         }
//         return dp[n-1];
        
        
        // Tabulation + Space Optimisation
        // T.C. = O(n) and S.C. = O(1)
        
//         int prev,prev2;
//         prev = 0;
//         prev2 = 0;
//         for(int i=0;i<n;i++){
//             // take
//             int take = nums[i];
//             if(i>1){
//                 take += prev2;
//             }
//             //not_take
//             int not_take = 0 + prev;
            
//             // storing overlapping subproblems
//             int curri = max(take,not_take);
            
//             prev2 = prev;
//             prev = curri;
//         }
//         return prev;
//     }
    
    
    int f(int i, vector<int>&nums, vector<int>&dp){
        // base cases
        
        if(i<0) return 0;
        
        if(i == 0) return nums[0];
        
        // take and not-take
        
        if(dp[i] != -1) return dp[i];
         
        int take = nums[i] + f(i-2,nums,dp);
        
        int not_take = f(i-1,nums,dp);
        
        return dp[i] = max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};