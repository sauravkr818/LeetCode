class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int left = 0;
        int right = 1;
        int sum = 0;
        int max_sum = 0;
        for(int i=0;i<n;i++){
            if(st.count(nums[i]) == 0){
                st.insert(nums[i]);
                sum += nums[i];
            }
            else{
                
                while(left<n && nums[left] != nums[i]){
                    st.erase(nums[left]);
                    sum -= nums[left];
                    left++;
                }
                //left++;
                sum -= nums[left];
                st.erase(nums[left]);
                left++;
                sum += nums[i];
                st.insert(nums[i]);
            }
            max_sum  = max(sum,max_sum);
        }
        return max_sum;
    }
};