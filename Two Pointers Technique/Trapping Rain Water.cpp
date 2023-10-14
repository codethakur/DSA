class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int water = 0;
        
        for (int i = 0; i < n; i++) {
            int maxLeft = 0;
            int maxRight = 0;
            
            for (int j = i; j >= 0; j--) {
                maxLeft = max(maxLeft, height[j]);
            }
            
            for (int j = i; j < n; j++) {
                maxRight = max(maxRight, height[j]);     //Time complexity O(n^3)
            }
            
            water += min(maxLeft, maxRight) - height[i];
        }
        
        return water;
    }
};

//////////////`````````````````````````````````````///////////////////

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        int Maximum = -1; 
        int water = 0;
        
        for (int i = 0; i < height.size(); i++) {
            Maximum = max(Maximum, height[i]);
            prefix[i] = Maximum;
        }
        
        Maximum = -1; 
        for (int i = height.size() - 1; i >= 0; i--) {
            Maximum = max(Maximum, height[i]);
            suffix[i] = Maximum;
        }

        for (int i = 0; i < height.size(); i++) {
            water += min(suffix[i], prefix[i]) - height[i];
        }

        return water;
    }
};
/*
  Since each of these loops operates independently and iterates through the height array only once,
  the overall time complexity of the code is O(n).
*/

///////````````````/////////``````````````````////////////
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // edge case: empty input vector

        vector<int> maxl(n), maxr(n);
        maxl[0] = height[0];
        for (int i = 1; i < n; i++) {
            maxl[i] = max(maxl[i-1], height[i]);
        }
        maxr[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxr[i] = max(maxr[i+1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(maxl[i], maxr[i]) - height[i];
        }

        return water;
    }
};
/*
  time complexity of this code is O(n), and the space complexity is O(n)
  due to the additional arrays used to store the left and right maximum heights
*/

