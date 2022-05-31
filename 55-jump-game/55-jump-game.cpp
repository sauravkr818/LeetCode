class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // edge cases
        int max_ind = 0;
        for(int i=0;i<n;i++){
            if(i>max_ind) return false;
            if(i+nums[i]>max_ind) max_ind = i+ nums[i];
        }
        return true;
        
    }
};