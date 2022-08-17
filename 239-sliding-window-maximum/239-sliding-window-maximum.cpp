class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int B) {
        int n = A.size();
        int i=0, j =0;
        deque<int>dq;
        vector<int>ans;
        while(j<n){
            while(!dq.empty() && dq.back()<A[j]){
                dq.pop_back();
            }
            dq.push_back(A[j]);
            if(j-i+1 <B){
                j++;
            }
            else if(j-i+1 == B){
                ans.push_back(dq.front());
                if(A[i] == dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};