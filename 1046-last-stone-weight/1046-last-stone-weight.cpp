class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int it: stones){
            pq.push(it);
        }
        int top = 0;
        while(pq.size() != 1){
            int a = pq.top(); pq.pop();
            // if(pq.size() == 1) break;
            int b = pq.top(); pq.pop();
            // if(pq.size() == 1) break;
            if(a == b) {
                top = a;
                if(pq.size() == 0) break;
                continue;
            }
            else if(a>b){
                pq.push(a-b);
            }
            else{
                cout<<"skip"<<endl;
                pq.push(b-a);
            }
        }
        if(pq.size() == 0) return 0;
        else return pq.top();
    }
};