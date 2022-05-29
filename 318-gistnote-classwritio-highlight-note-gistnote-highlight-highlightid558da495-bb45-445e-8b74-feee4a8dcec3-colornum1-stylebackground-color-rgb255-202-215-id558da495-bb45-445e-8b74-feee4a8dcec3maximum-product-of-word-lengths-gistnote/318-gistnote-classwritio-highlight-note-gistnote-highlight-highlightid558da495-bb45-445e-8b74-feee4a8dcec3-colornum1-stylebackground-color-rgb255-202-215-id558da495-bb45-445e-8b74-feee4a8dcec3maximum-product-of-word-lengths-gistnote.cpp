class Solution {
public:
    
    bool check(vector<int>&a, vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i] == 1 && b[i] == 1) return true;
        }
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            vector<int>temp(26,0);
            for(char ch : words[i]){
                temp[ch-'a'] = 1;
            }
            mp[i] = temp;
            for(int j=0;j<i;j++){
                if(!check(mp[i],mp[j])){
                    ans = max(ans, int(size(words[i]) * size(words[j])));
                }
            }
        }
        return ans;
    }
};