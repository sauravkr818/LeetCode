class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int it: nums){
            m[it]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto it: m){
            pq.push(make_pair(it.second,it.first));
        }
        vector<int>arr;
        for(int i=0;i<k;i++){
            auto it = pq.top(); pq.pop();
            arr.push_back(it.second);
        }
        // for(auto it: pq){
        //     it = pq.top(); pq.pop();
        //     arr.push_back(it.second);
        // }
        return arr;
    }
};