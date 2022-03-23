class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        while(target>startValue){
            if(target%2 == 0){
                target/= 2;
                count += 1;
            }
            else{
                target += 1;
                count += 1;
            }
        }
        
        return count+(startValue-target);
        
    }
};