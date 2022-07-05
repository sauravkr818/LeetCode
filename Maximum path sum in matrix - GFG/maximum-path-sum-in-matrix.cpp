// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int f(int i, int j, vector<vector<int>>&arr, vector<vector<int>>&dp){
        // base cases
        
        if(i<0 || j<0 || j>=arr.size()) return -1e8;
        
        if(i == 0) return arr[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int up = 0;
        up = arr[i][j] + f(i-1,j,arr,dp);
        
        int leftD = 0;
        leftD = arr[i][j] + f(i-1,j+1,arr,dp);
        
        int rightD = 0;
        rightD = arr[i][j] + f(i-1,j-1,arr,dp);
        
        return dp[i][j] = max(up,max(rightD,leftD));
        
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans = 0;
        vector<vector<int>>dp(N+1, vector<int>(N+1,-1));
        // check for every column in the last row
        for(int i=N-1;i>=0;i--){
            ans = max(ans,f(N-1,i,Matrix,dp));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends