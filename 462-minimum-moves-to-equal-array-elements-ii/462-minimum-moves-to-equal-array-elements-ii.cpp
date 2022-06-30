class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mid = n/2;
        int moves = 0;
        for(int i=0;i<n;i++){
            moves += abs(nums[mid]- nums[i]);
        }
        return moves;
    }
};