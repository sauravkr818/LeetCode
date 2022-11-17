class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ay2 - ay1) * (ax2 - ax1);
        int area2 = (by2 - by1) * (bx2 - bx1);
        
        int totalArea = area1 + area2;
        //cout<<totalArea<<endl;
        
        int cx1 = 0;
        if(bx1>=ax1 && bx1<=ax2){
            cx1 = bx1;
        }
        else if(ax1>=bx1 && ax1<=bx2){
            cx1 = ax1;
        }
        
        int cy1 = 0;
        if(by1>=ay1 && by1<=ay2){
            cy1 = by1;
        }
        else if(ay1>=by1 && ay1<=by2){
            cy1 = ay1;
        }
        
        int cx2 = 0;
        if(bx2>=ax1 && bx2<=ax2){
            cx2 = bx2;
        }
        else if(ax2>=bx1 && ax2<=bx2){
            cx2 = ax2;
        }
        
        int cy2 = 0;
        if(by2>=ay1 && by2<=ay2){
            cy2 = by2;
        }
        else if(ay2>=by1 && ay2<=by2){
            cy2 = ay2;
        }
        //cout<<cx1<<" "<<cx2<<" "<<cy1<<" "<<cy2<<endl;
        int area3 = (cy2-cy1) * (cx2-cx1);
        return totalArea - area3;
    }
};