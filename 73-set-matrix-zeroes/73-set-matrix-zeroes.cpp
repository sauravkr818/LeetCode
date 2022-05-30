class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>s;
        unordered_set<int>s1;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    s.insert(i);
                    s1.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // if(matrix[i][j] == 0){
                    if(s.find(i) != s.end()){
                        if(j>0) matrix[i][j-1] = 0;
                        if(j<n-1) matrix[i][j+1] = 0;
                        matrix[i][j] = 0;
                    }
                    if(s1.find(j) != s.end()){
                        if(i>0) matrix[i-1][j] = 0;
                        if(i<m-1) matrix[i+1][j] = 0;
                        matrix[i][j] = 0;
                    }
                // }
            }
        }
        
//         for(int i=0;i<m;i++){
//             for(int j=n-1;j>=0;j--){
//                 if(matrix[i][j] == 0){
//                     if(s.find(i) != s.end()){
//                         if(j>0) matrix[i][j-1] = 0;
//                         if(j<n-1) matrix[i][j+1] = 0;
//                     }
//                     if(s1.find(j) != s.end()){
//                         if(i>0) matrix[i-1][j] = 0;
//                         if(i<m-1) matrix[i+1][j] = 0;
//                     }
//                 }
//             }
//         }
        
//         for(int i=m-1;i>=0;i--){
//             for(int j=n-1;j>=0;j--){
//                 if(matrix[i][j] == 0){
//                     if(s.find(i) != s.end()){
//                         if(j>0) matrix[i][j-1] = 0;
//                         if(j<n-1) matrix[i][j+1] = 0;
//                     }
//                     if(s1.find(j) != s.end()){
//                         if(i>0) matrix[i-1][j] = 0;
//                         if(i<m-1) matrix[i+1][j] = 0;
//                     }
//                 }
//             }
//         }
        
//         for(int i=m-1;i>=0;i--){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j] == 0){
//                     if(s.find(i) != s.end()){
//                         if(j>0) matrix[i][j-1] = 0;
//                         if(j<n-1) matrix[i][j+1] = 0;
//                     }
//                     if(s1.find(j) != s.end()){
//                         if(i>0) matrix[i-1][j] = 0;
//                         if(i<m-1) matrix[i+1][j] = 0;
//                     }
//                 }
//             }
//         }
        
    }
};