class Solution {
public:
    
    // LIS + some modification
    // Problem similar to longest bitonic subsequence
    // You can also use binary search way to find LIS which will make it run faster.
    int minimumMountainRemovals(vector<int>& arr) {
    
    int n = arr.size();
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int prev = 0; prev<i; prev++){
            if( arr[i] > arr[prev] && 1 + dp[prev]> dp[i]){
                dp[i] = 1 + dp[prev];
            }
        }
    }
    vector<int>dp1(n,1);
    for(int i=n-1;i>=0;i--){
        for(int prev = n-1; prev>=i; prev--){
            if( arr[i] > arr[prev] && 1 + dp1[prev]> dp1[i]){
                dp1[i] = 1 + dp1[prev];
            }
        }
    }
    int maxi = 0;
    for(int i=0;i<n;i++){
        if(dp[i] != 1 && dp1[i] != 1)
        maxi = max(maxi, dp[i]+dp1[i]-1);
    }
    return n - maxi;
    }
};