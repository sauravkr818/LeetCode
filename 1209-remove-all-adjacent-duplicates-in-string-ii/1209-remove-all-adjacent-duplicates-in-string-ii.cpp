class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        
        for(char c: s){
            if(!st.empty() && st.back().first == c){
                ++st.back().second;
            }
            else{
                st.push_back({c,1});
            }
            
            if(st.back().second == k){
                st.pop_back();
            }
        }
        string ans = "";
        for(auto it: st){
            ans.append(it.second, it.first);
        }
        return ans;
    }
};