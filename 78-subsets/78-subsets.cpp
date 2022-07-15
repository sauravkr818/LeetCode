class Solution {
public:
    void f(int i, vector<int>&nums, vector<int>temp, vector<vector<int>>&ans){
        // base case
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        f(i+1,nums,temp,ans);
        temp.push_back(nums[i]);
        f(i+1,nums,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,nums,temp,ans);
        
        return ans;
    }
};