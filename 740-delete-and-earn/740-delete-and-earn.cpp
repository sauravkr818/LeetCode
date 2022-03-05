class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(10001,0);
        for(int i=0;i<n;++i){
            freq[nums[i]]++;
        }
        int cost = 0, max_cost = 0;
        for(int i=1;i<10001;++i){
            int val = max_cost + freq[i]*i;
            max_cost = max(max_cost,cost);
            cost = val;
        }
        return max(cost,max_cost);
    }
};