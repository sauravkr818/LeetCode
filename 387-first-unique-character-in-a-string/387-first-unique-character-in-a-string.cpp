class Solution {
public:
    int firstUniqChar(string s) {
        //unordered_map<char,int>mp;
        vector<int>arr(26,0);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(arr[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};