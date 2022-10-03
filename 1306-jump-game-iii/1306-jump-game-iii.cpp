class Solution {
public:
    
    bool f(vector<int>& arr, int i, vector<bool>&dp){
        // base case
        if(i>=arr.size() || i<0) return false;
        if(arr[i] == 0) return true;
        
        if(dp[i] == true) return false;
        else dp[i] = true;
        
        return f(arr,i+arr[i],dp) || f(arr,i-arr[i],dp);
        
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool>dp(arr.size(),false);
        return f(arr,start,dp);
    }
};