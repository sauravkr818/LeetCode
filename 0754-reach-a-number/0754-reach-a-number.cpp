class Solution {
public:
    int reachNumber(int target) {
        if(target<0){
            target = -target;
        }
        
        int steps = 0;
        int sum = 0;
        while(1){
            steps++;
            sum = sum + steps;
            if(sum == target) return steps;
            
            if(sum>target && (sum-target)%2 ==0) return steps;
        }
        return 0;
    }
};