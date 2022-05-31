class Solution {
public:
    
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string>h;
        for(int i=0;i<n-k+1;i++){
            //cout<<s.substr(i,k)<<" ";
            h.insert(s.substr(i,k));
        }
        if(h.size() == pow(2,k))
        return true;
        else return false;
    }
};