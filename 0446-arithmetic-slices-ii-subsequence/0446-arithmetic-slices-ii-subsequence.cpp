class Solution {
public:
    
//     vector<vector<int>>ans;
//     set<vector<int>>st;
//     int count = 0;
//     void f(int i, vector<int>& nums, vector<int>& arr){
//         if(i>nums.size()) return;
//         if(i == nums.size()){
//             if(arr.size()>=3){
//                 if(arr[arr.size()-1] - arr[arr.size()-2] == arr[arr.size()-2] - arr[arr.size()-3] ){
//                     count++;
//                     if(st.find(arr) == st.end()){
//                         ans.push_back(arr);
//                         // count++;
//                         st.insert(arr);
//                     }
                
//             }
//             return;
//         }
//         }
//         if(arr.size()>=3){
//             if(arr[arr.size()-1] - arr[arr.size()-2] 
//             == arr[arr.size()-2] - arr[arr.size()-3] ){
//                 count++;
//                 if(st.find(arr) == st.end()){
//                     ans.push_back(arr);
//                     // count++;
//                     st.insert(arr);
//                 }
//             }
//             else return;
//         }
        
        
//         arr.push_back(nums[i]);
//         f(i+1,nums,arr);
//         arr.pop_back();
//         f(i+1,nums,arr);
//     }
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>arr;
//         f(0,nums,arr);
//         // for(auto it: ans){
//         //     for(auto t: it){
//         //         cout<<t<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         return count;
//     }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n =  nums.size();
        vector<map<long long, int>> dp(n);
        long long ans =0;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long long dif = (long long)nums[i]- (long long)nums[j];
                if(dif <= INT_MIN || dif>= INT_MAX) continue;

                int seq = 0;
                if(dp[j].find(dif) != dp[j].end()){
                    seq = dp[j][dif];
                }
                dp[i][dif] += seq+1;
                ans += seq;
            }
        }
        return (int)ans;
    }
};