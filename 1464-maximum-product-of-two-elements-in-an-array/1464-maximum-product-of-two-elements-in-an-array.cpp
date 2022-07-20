class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int cur_max = max(nums[0],nums[1]);
        int res = (nums[0]-1)*(nums[1]-1);
        for(int i=2;i<n;i++){
            int product = (cur_max-1) * (nums[i]-1);
            cur_max = max(cur_max,nums[i]);
            res = max(res,product);
        }
        return res;
    }
};