class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int even = 0;
        for(auto t: nums){
            if(t % 2 == 0){
                even += t;
            }
        }
        vector<int>ans;
        int m = queries.size();
        for(int i=0;i<m;i++){
            int index = queries[i][1], val = queries[i][0];
            if(nums[index] % 2 == 0)
            even -= nums[index];
            nums[index] = nums[index] + val;
            if(nums[index] % 2 == 0){
                even += nums[index];
                ans.push_back(even);
            }
            else{
                ans.push_back(even);
            }
        }
        return ans;
    }
};