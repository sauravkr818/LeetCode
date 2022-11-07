class Solution {
public:
    int maximum69Number (int num) {
        int digits = 0;
        int temp = num;
        while(num>0){
            digits++;
            num /= 10;
        }
        int val1 = pow(10,digits);
        while(digits>0){
            int val = 3*pow(10,digits-1);
            if(temp+val>temp && temp+val<val1) return temp+val;
            digits--;
        }
        return temp;
    }
};