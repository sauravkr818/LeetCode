class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int>arr(n+1,0);
        if(n == 0) return 0;
        if(n == 1) return 1;
        arr[0] = 0;
        arr[1] = 1;
        for(int i=1;i<n;i++){
            if(2*i<=n && 2*i >= 2){
                arr[2*i] = arr[i];
            }
            if( 2*i + 1 <= n && 2*i + 1 >= 2){
                arr[2*i + 1] = arr[i] + arr[i+1];
            }
        }
        int maxi = INT_MIN;
        for(int i: arr){
            maxi = max(maxi,i);
        }
        return maxi;
    }
};