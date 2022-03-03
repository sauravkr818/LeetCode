class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        if(n<3){
            return 0;
        }
        else{
            int total_subarr = 0;
            int temp_n = 0;
            int count = 0;
            while(temp_n<n-2){
                if(arr[temp_n+1]-arr[temp_n] == arr[temp_n+2]-arr[temp_n+1]){
                    count++;
                }
                else{
                    total_subarr += (count*(count+1))/2;
                    count = 0;
                }
                temp_n++;
            }
            if(count) total_subarr += (count*(count+1))/2;
            return total_subarr;
        }
    }
};