class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        for(int i: nums){
            totalSum += i;
        }
        totalSum -= x;
        if(totalSum == 0) return nums.size();
        
        int i = 0, j;
        int sum = 0;
        int ans = 0;
        for(int j = 0;j<n;j++){
            sum += nums[j];
            while(i<nums.size() && sum>totalSum){
                sum -= nums[i];
                i++;
            }
            if(sum == totalSum){
                ans = max(j-i+1,ans);
            }
        }
        if(!ans){
            return -1;
        }
        
        return nums.size() - ans;
    }
};