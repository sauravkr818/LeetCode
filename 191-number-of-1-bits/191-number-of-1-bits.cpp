class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        while(n>0){
            int k = n%2;
            ones += k;
            n = n/2;
        }
        return ones;
    }
};