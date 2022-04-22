class Solution {
public:
    
    // unordered_set<int>s;
    int dp[10001];
    int f(vector<int>&arr,int i){
        
        if(i>=arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(arr[i]+f(arr,i+2),f(arr,i+1));
        
        
    }
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        vector<int>arr(10001,0);
        for(auto it: nums){
            arr[it] += it;
        }
        int n = nums.size();
        return f(arr,0);
    }
};