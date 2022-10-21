class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0;
        unordered_set<int>st;
        while(j<nums.size()){
            if(abs(i-j)<=k){
                if(i != j && st.find(nums[j]) != st.end()) return true;
                st.insert(nums[j]);
                j++;
            }
            else{
                st.erase(nums[i]);
                i++;
            }
        }
        return false;
    }
};