class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i] = {efficiency[i],speed[i]};
        }
        sort(rbegin(temp),rend(temp));
        long sum = 0, ans = 0;
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto& [a,b] : temp){
            pq.emplace(b);
            sum += b;
            if(pq.size()>k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans,sum*a);
        }
        return ans % (int)(1e9+7);
    }
};