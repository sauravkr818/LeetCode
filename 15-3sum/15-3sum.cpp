class Solution {
public:
    // Two-pointers approach
    // Time - O(n*n)
    // space - O(m) - ans array that is returned at last;
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        if(n<3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int a = nums[i];
            if(a>0) break;
            // a+b+c = 0;
            // therefore b+c = -a which is a two-sum problem
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int lo = i+1;
                int hi = n-1;
                while(lo<hi){
                    if(nums[lo]+nums[hi] == -a){
                        vector<int>arr = {nums[lo],nums[hi],a};
                        ans.push_back(arr);
                        while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                        lo++;
                        hi--;

                    }
                    else if(nums[lo]+nums[hi] < -a){
                        lo++;
                    }
                    else if(nums[lo]+nums[hi] > -a){
                        hi--;
                    }
                }
            }
        }
        return ans;
    }
};