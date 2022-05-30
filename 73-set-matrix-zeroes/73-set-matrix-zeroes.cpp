class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size(); // row size
        int n = arr[0].size(); // col size
        
        vector<int>row(m,1);
        vector<int>col(n,1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(col[j] == 0 || row[i] == 0){
                    arr[i][j] = 0;
                }
            }
        }
    }
};