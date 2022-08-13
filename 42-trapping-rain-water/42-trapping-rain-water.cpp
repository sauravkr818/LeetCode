class Solution {
public:
    // storing the leftmax and rightmax in 2 arrays
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<int>prefix(n);
    //     prefix[0] = height[0];
    //     vector<int>suffix(n);
    //     suffix[n-1] = height[n-1];
    //     for(int i=1;i<n;i++){
    //         prefix[i] = max(prefix[i-1],height[i]);
    //     }
    //     for(int i = n-2;i>=0;i--){
    //         suffix[i] = max(suffix[i+1],height[i]);
    //     }
    //     int ans = 0;
    //     for(int i=1;i<n-1;i++){
    //         ans += min(prefix[i], suffix[i]) - height[i];
    //     }
    //     return ans;
    // }
    int trap(vector<int>& height) {
        int n = height.size();
        int lo = 0, hi = n-1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while(lo<=hi){
            if(height[lo]<height[hi]){
                if(height[lo]>left_max){
                    left_max = height[lo];
                }
                else ans += left_max - height[lo];
                lo++;
            }
            else{
                if(height[hi]>right_max){
                    right_max = height[hi];
                }
                else ans += right_max - height[hi];
                hi--;
            }
        }
        return ans;
    }
};