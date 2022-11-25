class Solution {
public:
    // concept of monotonic stack
    // 1 4 3 8 5 2
    // what are the subarrays that consists 3 as the smallest number
    // they are 4,3 | 4,3,8 | 4,3,8,5 | 3 | 3,8 | 3,8,5
    // hence there are 6 subarrays having 3 as the smallest element
    // now the sum of 3's in these subarrays are = (no. of elements are on the right) * (no. of elements on the left) * arr[i]
    // for finding the no of elements on the right we can use next smaller elements index and for no. of elements on the left we can use prev smaller elements index.
    // therefore sum = (next smaller element index - i) * (i- prev smaller element index) * arr[i]
    // sum = (5-2) * (2-0) * arr[2] = 3*2*3 = 6*3 = 18 as the sum
    
    // edge case
    // when there are no next smaller element then number of elements on the right = A.size()-i-1;
    
    // when there are no prev smaller element then number of elements are on the left = i-1;
    
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>s1,s2;
        int n = arr.size();
        vector<int>next_smaller(n),prev_smaller(n);
        for(int i=0;i<n;i++){
            next_smaller[i] = n-i-1;
            prev_smaller[i] = i;
        }
        
        // for finding the number of elements on the right // next smaler element code
        for(int i=0;i<n;i++){
            while(!s1.empty() && (arr[s1.top()] > arr[i])){
                next_smaller[s1.top()] = i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        // for finding the prev smaller element on the left // prev smaller element code
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && (arr[s2.top()]>=arr[i])){
                prev_smaller[s2.top()] = s2.top() - i - 1;
                s2.pop();
            }
            s2.push(i);
        }
        
        int ans = 0;
        int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            ans = (ans + 1LL * arr[i]*(prev_smaller[i]+1)*(next_smaller[i]+1))%mod;
            //ans %= mod;
        }
        return ans;
    }
};