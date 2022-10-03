class Solution {
public:
    vector<int> sumZero(int n) {
        bool temp = false;
        if((n&1) == 0) temp = true;
        vector<int>arr;
        for(int i = -1*(n/2);i<=(n/2);i++){
            if(i == 0 && temp) continue;
            else arr.push_back(i);
        }
        return arr;
    }
};