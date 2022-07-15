// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    int f(int i, vector<int>&arr, int N, vector<int>&ans,int sum){
        // base case
        if(i == N) {
            ans.push_back(sum);
            return 0;
        }
        int not_take = 0 + f(i+1,arr,N,ans,sum); //not_take case
        // take case
        int take = arr[i] + f(i+1,arr,N,ans,sum+arr[i]);
        
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        int sum = 0;
        f(0,arr,N,ans,sum);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends