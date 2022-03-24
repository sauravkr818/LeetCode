class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int>arr;
        while(k != 0){
            if(k>26 && k-n+1>26){
                arr.push_back(26);
                k -= 26;
                n--;
            }
            else{
                arr.push_back(k-n+1);
                // k -= n-1;
                n--;
                for(int i=0;i<n;i++){
                    arr.push_back(1);
                }
                k = 0;
            }
        }
        string s;
        for(int i=arr.size()-1;i>=0;i--){
            char st = char(arr[i] + 96);
            s += st;
        }
        return s;
    }
};