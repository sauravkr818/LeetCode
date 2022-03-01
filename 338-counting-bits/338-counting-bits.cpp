class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        ans[0] = 0;
        for(int i=1;i<=n;i++){
    // Number of set bit in X is equal to number of set bit in X/2 if X is even.
    // else if X is odd then number of set bits in X = Number of set bits in (X/2) + 1.
            ans[i] = ans[i/2] + i%2;
        }
        return ans;
    }
};