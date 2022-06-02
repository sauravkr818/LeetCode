class Solution {
public:
    
    int f(int ind, int val, vector<int>& coins,vector<vector<int>> &dp){
        // base cases
        if(ind == 0){
            if(val%coins[0] == 0) {
                //cout<<int(val/coins[0])<<" ";
                return 1;
            }
            else return 0;
        }
        if(dp[ind][val] != -1) return dp[ind][val];
        int notTake = 0 + f(ind-1,val,coins,dp);
        int take = 0;
        if(coins[ind]<=val){
            take = f(ind,val-coins[ind],coins,dp);
        }
        
        return dp[ind][val] = (take+notTake);
        
    }
    
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        if(amount == 0) return 1;
        int val = f(n-1,amount,coins,dp);
        return val<0 ? 0 : val;
    }
};