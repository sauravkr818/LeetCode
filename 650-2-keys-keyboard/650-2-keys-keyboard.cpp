class Solution {
public:
    
    int minSteps(int n) {
        vector<int>arr = {2,3,5,7,11,13,17,19,23,29,31};
        if(n == 1) return 0;
        int count = 0;
        int i=0;
        for(int i=0;i<arr.size();i++){
            while(n % arr[i] == 0){
                count += arr[i];
                n /= arr[i];
            }
            if(n<arr[i]) break;
        }
        
        return (n>31) ? n+ count : count;
    }
};