class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>decreasing(n,1), increasing(n,1);
        // prefix sum for decreasing array
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                decreasing[i] = 1 + decreasing[i-1];
            }
        }
        
        // prefix-sum for increasing array
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                increasing[i] = 1 + increasing[i+1];
            }
        }
        
        // now you know how many elements are on the left of i are decreasing and how mnay elements are there on the right of i are increasing in O(1)
        vector<int>ans;
        for(int i=1;i<n-1;i++){
            if(decreasing[i-1]>=k && increasing[i+1]>=k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};