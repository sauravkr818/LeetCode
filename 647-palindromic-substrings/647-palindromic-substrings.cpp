class Solution {
public:
    
    int lcs(string s)
    {
        //Write your code here
        if (s.length() <= 1)
            return s.length();
        
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
            count++;
        }

        for (int start = s.length() - 1; start >= 0; start--) {
            for (int end = start + 1; end < s.length(); end++) {
                if (s.at(start) == s.at(end)) {
                    if (end - start == 1 || dp[start + 1][end - 1]) {
                        dp[start][end] = true;
                        count++;
                    }
                }

            }
        }
        
        return count;
    }
    
    
    int countSubstrings(string s) {
        string t = s;
        return lcs(s);
    }
};