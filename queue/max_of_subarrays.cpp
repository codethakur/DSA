class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> result;
        deque<int> dq;

        // Process the first k elements separately
        int i;
        for (i = 0; i < k; ++i)
        {
            while (!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }

        // Process the remaining elements
        for (; i < n; ++i)
        {
            result.push_back(arr[dq.front()]);

            // Remove elements outside the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove elements smaller than the current element
            while (!dq.empty() && arr[i] >= arr[dq.back()])
                dq.pop_back();

            // Add the current element to the deque
            dq.push_back(i);
        }

        // Add the maximum element of the last subarray
        result.push_back(arr[dq.front()]);
        return result;
    }
};
