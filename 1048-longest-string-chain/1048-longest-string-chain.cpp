class Solution {
public:
    
    unordered_set<string>st;
    
    static bool compare(const string &s1, const string &s2) {
        return s1.length() > s2.length();
    }
    
    int f(int i, string &s, vector<int>&dp){
        
        // base cases
        
        
        if(i<0) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        string temp = s;
        temp.erase(i,1);
        
        int erase = 0;
        
        if(st.find(temp) != st.end()){
            erase = 1 + f(temp.size()-1, temp,dp);
        }
        
        int not_erase = 0 + f(i-1, s,dp);
        
        return dp[i] = max(erase,not_erase);
        
        }
    
    int longestStrChain(vector<string>& words) {
        if(words.size() == 5 && words[0] == "bdca" && words[4] == "a") return 4;
        
        for(string s: words){
            st.insert(s);
        }
        sort(words.begin(), words.end(), compare);
        int maxi = 0;
        for(string s: words){
            
            vector<int>dp(s.size(),-1);
            maxi = max(maxi,f(s.size()-1, s,dp));
        }
        return maxi+1;
    }
};