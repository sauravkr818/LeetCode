class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        multiset<int> s;
        for(int i=0; i<intervals.size(); i++){
            auto it = s.upper_bound(-intervals[i][0]);
            if(it==s.end()){
                s.insert(-intervals[i][1]);
            }
            else{
                s.erase(it);
                s.insert(-intervals[i][1]);
            }
        }
        return s.size();
    }
};