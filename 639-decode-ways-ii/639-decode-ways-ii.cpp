class Solution {
public:
    
    const static int MOD = 1e9 + 7;
    
    long long f(int i, int n, string &s,vector<int>&dp){
        if(i >= n) return 1;
        if(s[i] == '0') return 0;
        
        if(dp[i] != -1) return dp[i];
        
        // pick single
        long long single = f(i+1,n,s,dp);
        long long coupl = 0;
        if(s[i] == '*'){
            single *= 9;
            
            // next character or pick couple
            // second character as '1'
            if(i+1<n && s[i+1]>='0' && s[i+1]<='9'){
                coupl += f(i+2,n,s,dp);
            }
            
            // second character as '*'
            
            if(i+1<n && s[i+1] == '*'){
                coupl += 9*f(i+2,n,s,dp);
            }
            
            // second character as '2'
            
            if(i+1<n && s[i+1]>='0' && s[i+1]<='6'){
                coupl += f(i+2,n,s,dp);
            }
            
            // second character as '*'
            if(i+1<n && s[i+1] == '*'){
                coupl += 6*f(i+2,n,s,dp);
            }
        }
        else if(i+1<n && s[i] == '1'){
            if(s[i+1]>='0' && s[i+1]<='9')
            coupl += f(i+2,n,s,dp);
            else if(s[i+1] == '*'){
                coupl += 9*f(i+2,n,s,dp);
            }
        }
        else if(i+1<n && s[i] == '2'){
            if(s[i+1]>='0' && s[i+1]<='6')
            coupl += f(i+2,n,s,dp);
            else if(s[i+1] == '*'){
                coupl += 6*f(i+2,n,s,dp);
            }
        }
       
        
        return dp[i] = (single+coupl)%MOD;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        long long ans = f(0,n,s,dp);
        return ans % MOD;
    }
};