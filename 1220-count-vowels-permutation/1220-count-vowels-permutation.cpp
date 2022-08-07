class Solution {
public:
    int dp[100][20001];
    static const int MOD = 1e9+7;
    long long f(char last, int n){
        // base cases
        if(n == 0) {
            return 1;
        }
        
        if(dp[abs(last-'a')][n] != -1) return dp[abs(last-'a')][n];
        // take
        long long take = 0;
        if(last == '$'){
            
            take = f('a',n-1) + f('e',n-1) + f('i',n-1) + f('o',n-1) + f('u',n-1);
        }
        else if(last == 'a'){
            take = f('e',n-1);
        }
        else if(last == 'e'){
            take = f('a',n-1) + f('i',n-1);
        }
        else if(last == 'i'){
            take = f('a',n-1) + f('e',n-1) + f('o',n-1) + f('u',n-1);
        }
        else if(last == 'o'){
            take = f('i',n-1) + f('u',n-1);
        }
        else if(last == 'u'){
            take = f('a',n-1);
        }
        
        
        return dp[abs(last-'a')][n] = take % (MOD);
            
    }
    long long countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        char last = '$';
        long long t = f(last,n);
        
        return t%MOD;
    }
};
