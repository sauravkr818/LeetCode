class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> aux_arr(100001,0);
        for(int i=0;i<nums.size();i++){
            aux_arr[nums[i]]++;
        }
        int a;
        for(int i=0;i<100001;i++){
            if(aux_arr[i]>1){
                a = i;
                return i;
            }
        }
        
        return a;
        
    }
};