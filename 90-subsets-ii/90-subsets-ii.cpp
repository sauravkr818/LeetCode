class Solution {
public:
    
    // recursion - take and not_take
    void f(int ind, vector<int>&nums, vector<int>temp, vector<vector<int>>&ans){
        // base case
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i != ind && nums[i] == nums[i-1]) continue; // ignoring the duplicates
            temp.push_back(nums[i]);
            f(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        f(0,nums,temp,ans);
        return ans;
    }
};