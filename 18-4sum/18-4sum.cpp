class Solution {
public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
//         // t.c. = (n^3*logn + nlogn) s.c. = O(1)
//         // sorting + binary search the last element
//         int n = nums.size();
//         vector<vector<int>>ans;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 for(int k=j+1;k<n;k++){
//                     int new_tar = target-(nums[i]+nums[j]+nums[k]);
//                     // binary search
//                     int st = k+1, en = n;
//                     while(st<=en){
//                         int mid = st + (en-st)/2;
//                         if(nums[mid] == new_tar){
//                             vector<int>temp = {nums[i],nums[j],nums[k],nums[mid]};
//                             ans.push_back(temp);
//                             break;
//                         }
//                         else if(nums[mid]>new_tar){
//                             en = mid-1;
//                         }
//                         else{
//                             st = mid+1;
//                         }
//                     }
                    
//                 }
//             }
//         }
//         // for unique answers use a hashset
//         // our answer contains duplicates therefore remove them to get the answer
//         return s;
//     }
    
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // t.c. = (n^3*logn + nlogn) s.c. = O(1)
        // sorting + two pointers to find the last 2 element
        int n = nums.size();
        vector<vector<int>>ans;
        if(n == 0) return ans;
        
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long int new_tar = target - nums[i];
                new_tar -=  nums[j];
                int st = j+1, en = n-1;
                while(st<en){
                    if(nums[st]+nums[en] == new_tar){
                        vector<int>temp = {nums[i],nums[j],nums[st],nums[en]};
                        ans.push_back(temp);
                        
                        // Processing the duplicates of 4th number
                        while(st<en && nums[en] == temp[3]) en--;
                        // Processing the duplicates of 3rd number
                        while(st<en && nums[st] == temp[2]) st++;
                        
                        
                    }
                    else if(nums[st]+nums[en] > new_tar){
                        en--;
                    }
                    else{
                        st++;
                    }
                }
                // Processing the duplicates of 2nd number
                while(j+1<n && nums[j] == nums[j+1]) j++;
            }
            // Processing the duplicates of 1st number
            while(i+1<n && nums[i] == nums[i+1]) i++;
        }
        
        // for unique answers use a hashset
        // our answer contains duplicates therefore remove them to get the answer
        return ans;
    }
};