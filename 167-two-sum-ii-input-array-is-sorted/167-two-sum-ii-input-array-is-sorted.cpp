class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         int ans1 = 0 ,ans2 = 0;
//         for(int i=0;i<n;i++){
//             int a = nums[i];
//             int b = target - a;
//             cout<<a<<" "<<b<<endl;
//             ans1 = i+1;
//             if(lower_bound(nums.begin()+i+1, nums.end(), b) != nums.end()){
//                 ans2 = (lower_bound(nums.begin()+i+1, nums.end(), b)) - nums.begin();
//                 cout<<ans2<<endl;
//                 cout<<"nums :"<<nums[ans2]<<"target :"<<b<<endl;
//                 if(nums[ans2] != b){
//                     continue;
//                 }
//                 break;
//             }
            
//         }
//         vector<int>arr = {ans1, ans2+1};
//         return arr;
        
        // Method-2 more good
         int l = 0;
    int r = nums.size() -1;
   
    while(l < r){
        if(nums[l] + nums[r] == target){
           
            return {l+1,r+1};;
        }
        else if(nums[l] + nums[r] > target){
            r--;
        }
        else{
            l++;
        }
    }
	return {};
    }
};