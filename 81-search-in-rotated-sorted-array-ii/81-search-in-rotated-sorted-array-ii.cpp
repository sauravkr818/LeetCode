class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int st=0,en=n-1;
        while(st<=en){
            int mid = (st+en)/2;
            if(arr[mid] == target) return true;
            
            if(arr[st] == arr[mid] && arr[en] == arr[mid]){
                st++;
                en--;
            }
            else if(arr[st] <= arr[mid]){
                if(arr[st] <= target && arr[mid] > target){
                    en = mid-1;
                }
                else{
                    st = mid+1;
                }
            }
            else{
                if(arr[st] > target && arr[mid] < target){
                    st = mid+1;
                }
                else{
                    en = mid-1;
                }
            }
        }
        return false;
    }
};