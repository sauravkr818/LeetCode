class Solution {
public:
    static bool sortBy2nd(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),sortBy2nd);
        int ans = 0;
        for(int i=0;i<boxTypes.size()&&truckSize>0;i++){
            if(truckSize - boxTypes[i][0]>=0){
                ans += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                ans += boxTypes[i][1] * truckSize;
                break;
            }
        }
        return ans;
        
    }
};