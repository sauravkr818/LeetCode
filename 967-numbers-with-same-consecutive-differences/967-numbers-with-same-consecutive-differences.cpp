class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>arr = {1,2,3,4,5,6,7,8,9};
        for(int i=2;i<=n;i++){
            vector<int>cur;
            for(int num: arr){
                int y = num%10;
                if(y+k<10){
                    cur.push_back(num*10+y+k);
                }
                if(k>0 && y-k>=0){
                    cur.push_back(num*10+y-k);
                }
            }
            arr = cur;
        }
        return arr;
        
    }
};