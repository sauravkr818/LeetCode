class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0, j = n-1;
        int count = 0;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum == k){
                count++;
                i++;j--;
            }
            if(sum>k){
                j--;
            }
            else if(sum<k){
                i++;
            }
        }
        return count;
    }
};