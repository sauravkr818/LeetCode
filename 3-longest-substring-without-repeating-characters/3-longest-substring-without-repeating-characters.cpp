class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int j = 0;
        int max_l = 1;
        unordered_set<char>mp;
        mp.insert(s[0]);
        for(int i=1;i<n;i++){
            while(mp.count(s[i]) != 1 && i<n){
                mp.insert(s[i]);
                i++;
            }
            cout<<i<<" "<<j<<endl;
            max_l = max(max_l, i-j);
            
            if(i == n) break;
            while(j<i){
                if(s[i] == s[j]) break;
                mp.erase(s[j]);
                j++;
            }
            j += 1;
            cout<<i<<" "<<j<<endl;
            
        }
        return max_l;
    }
};