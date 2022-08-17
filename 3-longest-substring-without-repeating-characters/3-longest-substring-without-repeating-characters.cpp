class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_set<char>st;
        
        int count = 0;
        while(j<n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                j++;
            }
            else{
                while(s[i] != s[j]){
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                i++;
            }
            count = max(count,j-i);
        }
        return count;
    }
};