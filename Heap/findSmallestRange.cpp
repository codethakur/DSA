class Solution{
    public:
    class Node {
      public:
        int data;
        int row;
        int col;
        Node(int d, int r, int c)
        {
            data = d;
            row = r;
            col = c;
        }
    };
    class compare {
      public:
        bool operator()(Node* a, Node* b)
        {
            return a -> data > b -> data; 
        }
    };
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //code here
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        priority_queue<Node*, vector<Node*>, compare> pq;
        for(int i = 0; i < k; i++)
        {
            int element = KSortedArray[i][0];
            minimum = min(minimum, element);
            maximum = max(maximum, element);
            pq.push(new Node(element, i, 0));
        }
        int start = minimum;
        int end = maximum;
        while(!pq.empty())
        {
            Node* temp = pq.top();
            pq.pop();
            minimum = temp -> data;
            if(maximum - minimum < end - start)
            {
                start = minimum;
                end = maximum;
            }
            if(temp -> col + 1 < n)
            {
                maximum = max(maximum, KSortedArray[temp -> row][temp -> col + 1]);
                pq.push(new Node(KSortedArray[temp -> row][temp -> col + 1], temp -> row, temp -> col + 1));
            }
            else
                break;
        }
        return {start, end};
    }
};
