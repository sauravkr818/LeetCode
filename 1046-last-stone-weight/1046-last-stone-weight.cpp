class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int it: stones){
            pq.push(it);
        }
        while(pq.size() != 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a == b) {
                if(pq.size() == 0) break;
                continue;
            }
            else if(a>b){
                pq.push(a-b);
            }
        }
        if(pq.size() == 0) return 0;
        else return pq.top();
    }
};