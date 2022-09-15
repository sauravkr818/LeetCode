class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        int n = changed.size();
        if(n % 2 != 0) return {};
        map<int,int>mp;
        for(int it: changed){
            mp[it]++;
        }
        vector<int>arr;
        for(int i=0;i<n;i++){
            if(mp[changed[i]] == 0) continue;
            if(mp[2*changed[i]] == 0) return {};
            arr.push_back(changed[i]);
            mp[changed[i]]--;
            mp[2*changed[i]]--;
        }
        return arr;
    }
};