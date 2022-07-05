class Solution {
public:
    
    
bool compare(string &s1, string &s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    while(first<s1.size()){
        if(s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first == s1.size() && second == s2.size()) return true;
    return false;
}

static bool sortBySize(string &s1, string &s2){
    return s1.size()<s2.size();
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int>dp(n,1);
    sort(arr.begin(), arr.end(), sortBySize);
    int maxi = 0;
    for(int i=0;i<n;i++){
        for(int prev = 0; prev<i; prev++){
            if(compare(arr[i], arr[prev]) && 1 + dp[prev]> dp[i]){
                dp[i] = 1 + dp[prev];
            }
        }
        maxi = max(maxi,dp[i]);
    }
    
    return maxi;
    
}
};