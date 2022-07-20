class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int curMax = 1, curMin = 1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) {
                curMax = 1;
                curMin = 1;
                res = max(0,res);
                continue;
            }
            int temp = curMax;
            curMax = max(curMax*nums[i],max(curMin*nums[i],nums[i]));
            curMin = min(temp*nums[i], min(curMin*nums[i], nums[i]));
            cout<<res<<endl;
            res = max(curMax,res);}return res;}};