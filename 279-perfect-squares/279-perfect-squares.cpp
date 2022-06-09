class Solution {
public:
    
    int f(int ind, int val, vector<int>& coins,vector<vector<int>> &dp){
        // base cases
        if(ind == 0){
            if(val%coins[0] == 0) {
                //cout<<int(val/coins[0])<<" ";
                return int(val/coins[0]);
            }
            else return 1e8;
        }
        if(dp[ind][val] != -1) return dp[ind][val];
        int notTake = 0 + f(ind-1,val,coins,dp);
        int take = 1e8;
        if(coins[ind]<=val){
            take = 1 + f(ind,val-coins[ind],coins,dp);
        }
        
        return dp[ind][val] = min(take,notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        if(amount == 0) return 0;
        int val = f(n-1,amount,coins,dp);
        return (val >= 1e8) ? -1 : val;
    }
    
    
    int numSquares(int n) {
        vector<int>arr;
        for(int i=1;i<100;i++){
            int sq = i*i;
            if(sq>n) break;
            arr.push_back(sq);
        }
        return coinChange(arr,n);
    }
};