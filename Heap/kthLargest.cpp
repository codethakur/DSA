//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int>sumStore;
        for(int i =0; i<N; i++)
        {
            int sum =0;
            for(int j=i; j<N; j++){
                sum +=Arr[j];
                sumStore.push_back(sum);
            }
        }
        sort(sumStore.begin(), sumStore.end());
        return sumStore[sumStore.size()-K];
    }
};
///////////////// using Heap//////////////////////////


class Solution{
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;

    int kthLargest(vector<int> &Arr,int N,int K){
          for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = i; j < N; j++) {
                sum += Arr[j];
                minheap.push(sum);
                if (minheap.size() > K) {
                    minheap.pop();
                }
            }
        }
        return minheap.top();
    }
};
