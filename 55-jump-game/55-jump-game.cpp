class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // edge cases
        if(nums[0] == 0 && n>1) return false;
        else if(nums[0] == 0 && n == 1) return true;
        
        int dist = 0;
        for(int i=0;i<=dist;i++){
            dist = max(dist,i+nums[i]);
            if(dist>=n-1) return true;
        }
        
        return false;
        
    }
};