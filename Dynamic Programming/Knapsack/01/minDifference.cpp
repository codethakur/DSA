class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += abs(arr[i]);
        }
        
        bool t[n + 1][totalSum + 1];
        
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < totalSum + 1; j++) {
                if(i == 0)
                    t[i][j] = false;
                if(j == 0)
                    t[i][j] = true;
            }
        }
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < totalSum + 1; j++) {
                if(abs(arr[i - 1]) <= j)
                    t[i][j] = t[i - 1][j - abs(arr[i - 1])] || t[i - 1][j];
                else 
                    t[i][j] = t[i - 1][j];
            }
        }

        std::vector<int> v(n + 1, 0);
        for(int j = 0; j <= totalSum / 2; j++) {
            if(t[n][j]) {
                v.push_back(j);
            }
        }

        int mini = INT_MAX;
        for(int i = 0; i < v.size(); i++) {
            mini = std::min(mini, totalSum - 2 * v[i]);
        }

        return mini;
	} 
};
