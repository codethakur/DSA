//O(m * log(m)) if k is much smaller than m.
// the space complexity is O(m + k).
class Solution {
public:
    typedef pair<int, int>p;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<p>store;
        for(int i=0; i<m; i++)
        {
            int soldiersCount = 0;
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==1){
                    soldiersCount++;
                }else{
                    break;
                }
            }
            store.push_back({soldiersCount, i});
        }
        sort(store.begin(),store.end());
        
        vector<int> indices;
        for(int i = 0; i < k; i++) {
            indices.push_back(store[i].second);
        }
        
        return indices;

    }
};
/////////``````````````````````//////////////



class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> store;
        int m = mat.size();
        
        for (int i = 0; i < m; i++) {
            int soldiers = countSoldiers(mat[i]);
            store.push_back({soldiers, i});
        }
        
        sort(store.begin(), store.end());
        
        vector<int> indices;
        for (int i = 0; i < k; i++) {
            indices.push_back(store[i].second);
        }
        
        return indices;
    }
    
private:
    int countSoldiers(vector<int>& row) {
        int count = 0;
        for (int val : row) {
            if (val == 1) {
                count++;
            } else {
                break; // As soldiers are positioned in front of civilians
            }
        }
        return count;
    }
};





//T.C : //O(m*log(n) + m*log(k))
//S.C : O(k) to store count of ones and corresponding row in the min-heap
class Solution {
public:
    
    typedef pair<int, int> P;
    
    int binarySearch(vector<int>& arr, int l, int r) {
        int mid;
        int result = -1;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(arr[mid] == 1) {
                result = mid;
                l = mid+1;
            } else if(arr[mid] == 0) {
                r = mid-1;
            }
            
        }

        return result+1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        priority_queue<P> pq;
        
        //O(m*log(n) + m*log(k))
        for(int row = 0; row < m; row++) {
            
            int num_ones = binarySearch(mat[row], 0, n-1); //O(log(n))
            
            pq.push({num_ones, row});
            
            if(pq.size() > k)
                pq.pop();

        }
       
        
        vector<int> result(k);
        int j = k-1;

        //log(k)
        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();
            
            result[j--] = temp.second;
         }
        
        return result;
    }
};
