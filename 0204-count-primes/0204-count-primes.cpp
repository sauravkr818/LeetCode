class Solution {
public:
    // seive of eratosthenes
    int countPrimes(int n) {
        if(n<=2) return 0;
        // 2 is a prime hence start ans with 1.
        int ans = 1;
        int upper = sqrt(n);
        vector<int>vis(n,0);
        for(int i=3;i<n;i+=2){
            if(vis[i] == 1) continue;
            ans++;
            //avoid overflow
			if (i>upper) continue;
            for(int j = i*i;j<n;j += i){
                vis[j] = 1;
            }
        }
        return ans;
    }
};