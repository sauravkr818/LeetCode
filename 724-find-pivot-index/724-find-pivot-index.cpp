class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            prefix.push_back(sum);
        }
        for(int i=0;i<n;i++){
            int leftS;
            if(i-1<0){
                leftS = 0;
            }
            else {
                leftS = prefix[i-1];
            }
            int rightS;
            rightS = prefix[n-1] - prefix[i];
            if(leftS == rightS) return i;
        }
        return -1;
    }
};