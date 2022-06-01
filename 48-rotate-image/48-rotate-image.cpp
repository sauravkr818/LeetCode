class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // code intuition:
        // 1st transpose of the given matrix
        // 2nd Reverse each row.
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // 1st step
        
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        // 2nd step
        
        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};