class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pre_max(n);
        vector<int>suf_max(n);
        int pre = height[0];
        int suf = height[n-1];
        for(int i=0;i<n;i++){
            pre_max[i] = max(pre,height[i]);
            pre = pre_max[i];
        }
        for(int i=n-1;i>=0;i--){
            suf_max[i] = max(suf,height[i]);
            suf = suf_max[i];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += min(pre_max[i],suf_max[i]) - height[i];
        }
        return ans;
    }
};