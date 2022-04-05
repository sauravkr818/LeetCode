class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0;
        int en = n-1;
        int area = INT_MIN;
        while(st<=en){
            int max1 = height[st];
            int max2 = height[en];
            
            area = max(min(max1,max2)*(en-st),area);
            if(max1<max2){
                st++;
            }
            else{
                en--;
            }
        }
        return area;
    }
};