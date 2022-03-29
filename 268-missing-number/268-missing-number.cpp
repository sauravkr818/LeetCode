class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = 0;
        int i = 0;
        for(i=0;i<nums.size();i++){
            n = n ^ i ^ nums[i];
        }
        return n^i;
    }
};