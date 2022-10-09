class Solution {
public:
    string largestPalindromic(string num) {
        
        int count = 0;
        string str = "";
        for(auto chr: num){
            if(chr != '0'){
                count++;
                str += chr;
            }
        }
        if(count == 1) return str;
        if(count == 0) {
            str += '0';
            return str;
        }
        unordered_map<char,int>mp;
        for(auto it: num) mp[it]++;
        string s = "";
        char maxi = ' ';
        bool temp = false;
        for(auto it: mp){
            if((it.second)>1){
                if(it.first != '0'){
                    temp = true;
                }
                s += it.first;
                if(it.second % 2 != 0){
                    if(maxi<it.first){
                    maxi = it.first;
                }
                }
            }
            else{
                if(maxi<it.first){
                    maxi = it.first;
                }
            }
        }
        if(temp == false){
            string ans = "";
            ans += maxi;
            return ans;
        }
        sort(s.begin(),s.end(),greater<int>());
        //cout<<s<<endl;
        string ans = "";
        for(int i=0;i<s.size();i++){
            for(int j=0;j<(mp[s[i]])/2;j++){
                ans += s[i];
            }
        }
        //cout<<ans<<endl;
        if(maxi != ' ')
        ans += maxi;
        
        //cout<<maxi<<endl;
        int n = ans.size();
        if(maxi != ' '){
            n = n-2;
        }
        else{
            n = n-1;
        }
        for(int i = n;i>=0;i--){
            ans += ans[i];
        }
        return ans;
    }
};