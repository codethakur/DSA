class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      vector<int>v;

      for(auto num:nums1){
        v.push_back(num);
      } 
      for(auto num:nums2)
      {
        v.push_back(num);
      }
      sort(v.begin(),v.end());
      int n =v.size();
      return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
      
    }      // O(log (m+n))
          //O(m+n);
};
//```````````````````````````````
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;
        
        while (low <= high) {
            int cutt1 = (low + high) / 2;
            int cutt2 = (n1 + n2) / 2 - cutt1; 

            int l1 = cutt1 == 0 ? INT_MIN : nums1[cutt1 - 1];
            int l2 = cutt2 == 0 ? INT_MIN : nums2[cutt2 - 1];

            int r1 = cutt1 == n1 ? INT_MAX : nums1[cutt1];
            int r2 = cutt2 == n2 ? INT_MAX : nums2[cutt2];
            
            if (l1 > r2) {
                high = cutt1 - 1;
            } else if (l2 > r1) {
                low = cutt1 + 1;
            } else {
                // Found the correct partition
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return min(r1, r2);
                }
            }
        }
        
        return 0.0; // O(long(min(n1+n2)));
    }
};
