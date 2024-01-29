class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>pq1;//max Heap
    priority_queue<int,vector<int>,greater<int>> pq2;//min Heap
    void insertHeap(int &x)
    {
        if(pq1.empty() || pq1.top()>x)
            pq1.push(x);
        else
            pq2.push(x);
            
        balanceHeaps();    
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(pq1.size()==pq2.size()){
            return;
        }else if(pq1.size()>pq2.size() && (pq1.size()-pq2.size())>1){
            pq2.push(pq1.top());
            pq1.pop();
        }else if(pq1.size()<pq2.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }

    
    //Function to return Median.
    double getMedian()
    {
        if(pq1.size()!=pq2.size()){
            return pq1.top();
        }else{
            return (pq1.top() + pq2.top())/2.0;
        }
    }
};
