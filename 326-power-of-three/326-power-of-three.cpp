class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n!=1){
            if(n % 3 != 0) return false;
            n /= 3;
            if(n == 0 || (n % 3 != 0 && n != 1)) return false;
        }
        //cout<<n<<endl;
        return n == 1 ? true : false;
    }
};