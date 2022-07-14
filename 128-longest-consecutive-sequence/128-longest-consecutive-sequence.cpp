class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_set<int>s(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            
            if(s.find(nums[i] - 1)!=s.end()) //impoertant step
                continue;
            else{
                int val = nums[i];
                int cnt = 1;
                while(s.find(val+1) != s.end()){
                    cnt++;
                    val = val+1;
                    //cout<<"he"<<endl;
                }
                count = max(cnt,count);
            }
            
        }
        return count;
    }
};