class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n);
        long long total = 0;
        for(int it: nums) total += it;
        long long frontSum = 0;
        for(int i=0;i<n;i++){
            frontSum += nums[i];
            if(i == n-1){
                arr[i] = (frontSum)/n;
            }
            else
            arr[i] = abs((frontSum)/(i+1) - (total-frontSum)/(n-i-1));
        }
        //for(int it: arr) cout<<it<<" ";
        //cout<<arr.size()<<endl;
        int idx = 0;
        int mini = arr[0];
        for(int i=1;i<n;i++){
            if(mini>arr[i]){
                mini = arr[i];
                idx = i;
            }
        }
        return idx;
    }
};