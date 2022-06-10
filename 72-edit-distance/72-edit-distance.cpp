class Solution {
public:
    
    int f(int i, int j, string &s1, string &s2,vector<vector<double>>&dp){
        // base cases
        if(i<0) return j+1;
        
        if(j<0) return i+1;
        
        
        if(dp[i][j] != -1) return dp[i][j];
        //matching
        if(s1[i] == s2[j]) return dp[i][j] = 0 + f(i-1,j-1,s1,s2,dp);
        else{
            // insert + delete + replace
            return dp[i][j] = (int) min( 1 + f(i,j-1,s1,s2,dp), min( 1 + f(i-1,j,s1,s2,dp), 1 + f(i-1,j-1,s1,s2,dp) ));
        }
    }
    
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<double>>dp(n, vector<double>(m,-1));
        return (int) f(n-1,m-1,word1,word2,dp);
    }
};