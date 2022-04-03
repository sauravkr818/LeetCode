class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int en = n-1;
        int temp = n-2;
        int i;
        while(temp>=0 && nums[temp]>=nums[temp+1]){
            temp--;
        }
        cout<<temp<<endl;
        if(temp < 0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(i=n-1;i>temp;i--){
                if(nums[i]>nums[temp]) break;
            }
            swap(nums[i],nums[temp]);
            reverse(nums.begin()+temp+1,nums.end());
        }
    }
};