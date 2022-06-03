class NumMatrix {
public:
    
    vector<vector<int>>temp;
    NumMatrix(vector<vector<int>>& matrix) {
        temp = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            int s = 0;
            for(int j=0;j<n;j++){
                s += matrix[i][j];
                if(i-1>=0)
                temp[i][j] = s+ temp[i-1][j];
                else temp[i][j] = s;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int add1 = temp[row2][col2];
        int del1 = col1-1>=0 ? temp[row2][col1-1] : 0;
        int del2 = row1-1>=0 ? temp[row1-1][col2]: 0;
        int add2 = (row1-1>=0) && (col1-1>=0) ? temp[row1-1][col1-1] : 0;
        return add1 - del1 - del2 + add2;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */