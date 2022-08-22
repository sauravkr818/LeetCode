class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans = {nums[0]};
        for(int i=1;i<m;i++){
            int val = ans.size();
            if(nums[i][0]>ans[val-1][1]) {
                ans.push_back({nums[i][0],nums[i][1]});
                continue;
            }
            else if(nums[i][0]<=ans[val-1][1]){
                vector<int>arr1;
                arr1.push_back(ans[val-1][0]);
                arr1.push_back(max(ans[val-1][1],nums[i][1]));
                ans.pop_back();
                ans.push_back(arr1);
            }
        }
        return ans;
    }
};