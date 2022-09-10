class Solution {
public:
    
    // there are two soltution to this problem 
    // I have solved using the first method where dp is of n*2*k size
    // which also means I have declared 3D DP
    
    // Method 2 involves transactions Number which ranges from 0 to 2*k-1
    // hence when k = 2 then there are 4 transaction numbers
    // 0,1,2,3 where B,S,B,S is denoted by the numbers respectively
    // When the number is even = buy and when the number is odd sell
    // Therefore here we will declare a dp array of size dp[n+1][2k+1]
    // Only 2D DP 
    
    int maxProfit(int k, vector<int>& prices) {
        
        // tabulation written from buy and sell stock-(iii) recursion code
        
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        // bases cases return 0 but since we have initiallized our dp array to 0 hence we need not write base cases
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    // copy paste the recurrence
                    int profit = 0;
                    if(buy){
                        profit = max( -prices[ind] + dp[ind+1][0][cap],
                                    0 + dp[ind+1][1][cap] );
                    }
                    else{
                        // max( either sell on the ith day and move to (i+1)th day to buy or not sell on the ith day and move to (i+1)th day).
                        profit = max( prices[ind] + dp[ind+1][1][cap-1] ,
                                    0 + dp[ind+1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};