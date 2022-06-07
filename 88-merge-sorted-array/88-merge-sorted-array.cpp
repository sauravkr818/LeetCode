class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>arr;
        int i = 0, j = 0;
        while(i<m && j<n){
            if(nums1[i] == nums2[j]){
                arr.push_back(nums1[i]);
                arr.push_back(nums1[i]);
                i++;j++;
            }
            else if(nums1[i]>nums2[j]){
                arr.push_back(nums2[j]);
                j++;
            }
            else{
                arr.push_back(nums1[i]);
                i++;
            }
        }
        
        if(i == m){
            while(j<n){
                arr.push_back(nums2[j]);
                j++;
            }
        }
        else if( j == n){
            while(i<m){
                arr.push_back(nums1[i]);
                i++;
            }
        }
        
        nums1 = arr;
    }
};