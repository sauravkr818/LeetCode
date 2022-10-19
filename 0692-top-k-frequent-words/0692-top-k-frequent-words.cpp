struct compare{
        bool operator() (pair<int,string>&a, pair<int,string>&b){
            if(a.first == b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        }
    };

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto str: words) mp[str]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;
        
        for(auto item: mp){
            pq.push({item.second,item.first});
        }
        vector<string>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};