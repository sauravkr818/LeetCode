class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num_one = INT_MAX, num_two = INT_MAX;
        for(int val: nums){
            if(val<=num_one){
                num_one = val;
            }
            else if(val<=num_two){
                num_two = val;
            }
            else return true;
        }
        return false;
    }
};