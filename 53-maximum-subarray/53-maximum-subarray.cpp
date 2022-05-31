class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum<0){
                max_sum = max(sum,max_sum);
                sum = 0;
            }else
            max_sum = max(sum,max_sum);
        }
        return max_sum;
    }
};