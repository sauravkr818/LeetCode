class Solution {
public:
    
    // copied from buy and sell stock - (ii)
    // just minor change is that after a successful buy-sell, pay transaction fee
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // tabulation
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1;buy++){
                int profit = 0;
                if(buy==1){
                    profit = max( -prices[ind] + dp[ind+1][0], 
                                0 + dp[ind+1][1]); 
                }
                else{
                    profit = max( prices[ind] -fee + dp[ind+1][1],
                                0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};