class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long bgt) {
        int i = 0, j = 0;
        int n = ct.size();
        priority_queue<pair<long long,int>>pq;
        long long gg = 0;
        long long count = 0;
        while(j<n){
            pq.push({ct[j],j});
            gg += rc[j];
            while(pq.empty() == false && (pq.top()).first + ((j-i+1) * gg)>bgt && i<n){
                gg -= rc[i];
                if ((pq.top()).second <= i){
                    pq.pop();
                }
                i++;
            }
            count = max(count,(long long)j-i+1);
            j++;
        }
        return (int)count;
    }
};