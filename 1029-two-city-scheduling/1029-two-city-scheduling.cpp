class Solution {
public:
    
   static bool sortbydiff(vector<int>a,vector<int>b){
        return a[0] - a[1] < b[0] - b[1];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(),sortbydiff);
        // for(int i=0;i<n;i++){
        //     for(int j =0;j<costs[i].size();j++){
        //         cout<<costs[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int weightA = 0;
        int weightB = 0;
        for(int i=0;i<n/2;i++){
                weightB += costs[i+(n/2)][1];
                weightA += costs[i][0];
        }
        return weightA + weightB;
    }
};