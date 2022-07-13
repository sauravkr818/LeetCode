class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        // at max there can be two majority elements
        // therefore declaring two numbers num1 and num2.
        int num1 = -1;
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2){
                count2++;
            }
            else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == num1){
                count1++;
            }
            else if(nums[i] == num2){
                count2++;
            }
        }
        vector<int>arr;
        if(count1>floor(n/3)){
            arr.push_back(num1);
        }
        if(count2>floor(n/3)){
            arr.push_back(num2);
        }
        return arr;
    }
};