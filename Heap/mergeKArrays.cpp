class Node{
  public:
  int data;
  int  i;
  int j;
  Node(int data, int row, int col){
    this->data=data;
    i=row; 
    j=col;
  }
};
  class compare{
      public:
      bool operator()(Node* a, Node* b)
      {
          return a->data>b->data;
      }
  };

class Solution
{
    public:
    //Function to merge k sorted arrays.
    priority_queue<Node*, vector<Node*>, compare>pq;
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        for(int i=0; i<arr.size(); i++)
        {
            Node* temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        vector<int>ans;
        while(pq.size()>0)
        {
          Node* tempAns = pq.top();
          ans.push_back(tempAns->data);
          pq.pop();
          
          int i=tempAns->i;
          int j = tempAns->j;
          
          if(j+1<arr[i].size()){
            Node* next = new Node(arr[i][j+1], i,j+1);
            pq.push(next);
          }
        }
        return ans;
    }
};
