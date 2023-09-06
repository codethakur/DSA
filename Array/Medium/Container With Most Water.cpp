//Time : O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int max_Area=0;
        int r= height.size()-1;
        while(l<r)
        {
         int area = (r-l)* min(height[l],height[r]);
         max_Area = max(max_Area, area);
         if(height[l]<height[r]){
             l+=1;
         }else{
             r-=1;
         }

        }
        return max_Area;
    }
};
