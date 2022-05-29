class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int max_ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                ans++;
            }
            else{
                ans = 0;
            }
            max_ans = max(max_ans,ans);
        }
        return max_ans;
    }
};