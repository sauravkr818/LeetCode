class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        unordered_set<int>st;
        for(auto it: mp){
            st.insert(it.second);
        }
        if(mp.size() == st.size()) return true;
        return false;
    }
};