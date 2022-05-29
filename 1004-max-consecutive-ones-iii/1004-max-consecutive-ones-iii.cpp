class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int save = k;
        int count = 0;
        int max_count = 0;
        int lo = 0,hi = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                hi++;
            }
            else if(save>0){
                hi++;
                save--;
            }
            else{
                max_count = max(max_count,hi-lo);
                while(nums[lo] != 0){
                    lo++;
                }
                i = i-1;
                lo++;
                save++;
            }
            max_count = max(max_count,hi-lo);
        }
        return max_count;
    }
};