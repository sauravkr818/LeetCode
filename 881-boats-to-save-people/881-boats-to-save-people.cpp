class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.rbegin(),people.rend());
        int count = 0;
        int sum = 0;
        int i = 0, j = n-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }
            else{
                i++;
            }
            count++;
        }
        return count;
    }
};