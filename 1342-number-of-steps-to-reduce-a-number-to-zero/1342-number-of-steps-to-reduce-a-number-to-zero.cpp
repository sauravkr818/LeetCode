class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while(num){
            ans += (num&1) ? 2 : 1;
            num >>= 1;
        }
        return (ans == 0) ? 0 : ans-1;
    }
};