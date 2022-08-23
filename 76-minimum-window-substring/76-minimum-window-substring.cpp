class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n) return "";
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int count = mp.size();
        int i=0, j=0;
        string ans = "";
        while(j<n){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    count--;
                }
            }
            if(count == 0){
                string temp = s.substr(i,j-i+1);
                if(j-i+1<ans.size() || ans == ""){
                    ans = temp;
                }
                while(count == 0){
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            count++;
                        }
                    }
                    i++;
                    temp = s.substr(i,j-i+1);
                    if((j-i+1<ans.size() && count == 0) || ans == ""){
                        ans = temp;
                    }
                }
            }
            j++;
            
        }
        // string temp = s.substr(i,j-i+1);
        // if((j-i+1<ans.size() && count == 0) || ans == ""){
        //     ans = temp;
        // }
        return ans;
        
    }
};