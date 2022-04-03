class Solution {
public:
    void f(vector<vector<int>>&ans, vector<int>&nums, vector<int>&temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
        }
        
        for(int i=0;i<nums.size();i++){
            if(count(temp.begin(),temp.end(),nums[i])) continue;
            temp.push_back(nums[i]);
            f(ans,nums,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>temp;
        f(ans,nums,temp);
        return ans;
    }
};