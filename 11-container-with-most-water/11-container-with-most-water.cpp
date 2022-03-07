class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int max1 = arr[0];
        int max2 = arr[n-1];
        int area = 0;
        int x = 0;
        int y = n-1;
        for(int i=0;i<n&&x<y;i++){
            area = max(area, min(max1,max2)*(abs(y-x)));
            if(arr[x]<arr[y]){
                x++;
            }
            else{
                y--;
            }
            max1 = arr[x];
            max2 = arr[y];
            //max2 = max(max2,arr[n-i-1]);
        }
        return area;
    }
};