class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //for(auto t: nums) cout<<t<<" ";
        vector<vector<int>>ans;
        int n = nums.size();
        if(n<3) return ans;
        int prev = INT_MIN;
        for(int i=0;i<n;i++){
            if(prev == nums[i]) continue;
            prev = nums[i];
            int target = -1 * nums[i];
            int lo = i+1;
            int hi = n-1;
            while(lo<hi){
                if(nums[lo] + nums[hi] == target){
                    vector<int>temp = {nums[lo],nums[hi],-1* target};
                    ans.push_back(temp);
                    while (lo < hi && nums[lo] == nums[lo+1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi-1]) hi--;
                    lo++;
                    hi--;
                }
                else if(nums[lo] + nums[hi] > target){
                    hi--;
                }
                else{
                    lo++;
                }
            }
        }
        return ans;
    }
};