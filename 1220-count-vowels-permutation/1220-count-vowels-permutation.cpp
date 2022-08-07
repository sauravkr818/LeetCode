class Solution {
public:
//     int dp[100][20001];
//     int f(char last, int n){
//         // base cases
//         if(n == 0) {
//             return 1;
//         }
        
//         // take
//         int take = 0;
//         if(last == '$'){
            
//             take = f('a',n-1) + f('e',n-1) + f('i',n-1) + f('o',n-1) + f('u',n-1);
//         }
//         else if(last == 'a'){
//             take = f('e',n-1);
//         }
//         else if(last == 'e'){
//             take = f('a',n-1) + f('i',n-1);
//         }
//         else if(last == 'i'){
//             take = f('a',n-1) + f('e',n-1) + f('o',n-1) + f('u',n-1);
//         }
//         else if(last == 'o'){
//             take = f('i',n-1) + f('u',n-1);
//         }
//         else if(last == 'u'){
//             take = f('a',n-1);
//         }
        
        
//         return dp[abs(last-'a')][n] = take;
            
//     }
//     int countVowelPermutation(int n) {
//         memset(dp,-1,sizeof(dp));
//         char last = '$';
//         int t = f(last,n);
        
//         return t;
//     }
    
    static const int a = 0, e = 1, i = 2, o = 3, u = 4, s = 5, MOD = 1e9 + 7;
    const vector<vector<int>> mapping = {{e}, // a ->
                                         {a, i}, // e -> 
                                         {a, e, o, u}, // i ->
                                         {i, u}, // o ->
                                         {a}, // u ->
                                         {a, e, i, u, o}}; // s ->
    int dp[20001][6] = {};
    
    int f(int n, int last){
        if (n == 0) return 1;
        if (dp[n][last]) return dp[n][last];
        int ans = 0;
        for (int nxt : mapping[last]) {
            ans = (ans + f(n-1, nxt)) % MOD;
        }
        return dp[n][last] = ans;
    }
    int countVowelPermutation(int n) {
        
        int last = 5;
        int t = f(n,last);
        
        return t;
    }
};