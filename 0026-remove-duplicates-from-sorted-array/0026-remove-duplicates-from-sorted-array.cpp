class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int count = 0;
        int i = 0;
        for(i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                while(i<n && nums[i] == nums[i-1]){
                    i++;
                }
                i--;
            }
            else{
                count++;
                nums[j] = nums[i-1];
                j++;
            }
        }
        nums[j] = nums[i-1];
        count++;
        return count;
    }
};