class Solution {
public:
    // strong observation - this is problem similar to fibonacci number
    
    
//     int solve(int n, vector<int>&dp){
//         // base case 
//         if(n == 0) return 1;
//         if(n == 1) return 1;
        
//         if(dp[n] != -1){
//             return dp[n];
//         }
        
//         return dp[n] = solve(n-1,dp) + solve(n-2,dp);
//     }
    
    int climbStairs(int n) {
        
        if(n == 1) return 1;
        // recursive approach
        
            //         if(n == 0) return 1;
            //         if(n == 1) return 1;

            //         return climbStairs(n-1) + climbStairs(n-2);
        
        // memoization - use an array to store the sub-problems
            // value so that we need not to compute it again. T.C. = O(n), S.C. = O(n) for recursion call stack and O(n) for dp array;
            // vector<int>dp(n+1,-1);
            // solve(n,dp);
            // return dp[n];
        
        // Tabulation - Bottom-up 
            // We just need to remember the (i-1)th subproblem and the (i-2)th problem
            // because f(i) is totally dependent on f(i-1) + f(i-2);
            // this will reduce the space complexity of recursion call stack hence T.C. = O(n), S.C. = O(n)
            // code...
            // vector<int>dp(n+1,-1);
            // dp[0] = dp[1] = 1;
            // for(int i=2;i<=n;i++){
            //     dp[i] = dp[i-1] + dp[i-2];
            // }
            // return dp[n];
        
        // Tabulation - Bottom-up - Space optimised = O(1);
           // We can see that only remembering the prev and prev to prev value gives the current result val;
           // Instead of creating a dp array we will use only two variables : prev and prev2;
            
            long long prev = 1; // prev represents the just prev to current element. For ex. In f(3), curr = 3 and prev = 2 and prev2 = 1;
            long long prev2 = 1; // prev to prev is prev2;
            long long total = 0;
            for(int i=2;i<=n;i++){
                long long curri = prev+prev2;
                // update prev and prev2 as current will also be update after each iteration;
                prev2 = prev;
                prev = curri;
                total = curri;
            }
        // return the last curri which will give f(n);
        return total;
            
        
    }
};