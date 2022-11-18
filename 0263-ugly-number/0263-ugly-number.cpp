class Solution {
public:
    bool isUgly(int n) {
        //if(n<0) n = -n;
        if(n<=0) return false;
        while (n % 2 == 0)
        {
            
            n = n/2;
            //cout<<n<<endl;
        }
        
        // n must be odd at this point. So we can skip
        // one element (Note i = i +2)
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            // While i divides n, print i and divide n
            while (n % i == 0)
            {
                //cout << i << " ";
                if(i != 3 && i!= 5) return false;
                n = n/i;
                //cout<<n<<endl;
            }
        }
        //cout<<n<<endl;
        
        if(n>2 && n!=3 && n!=5) return false;
        return true;
    }
};