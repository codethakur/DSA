class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
            Node* first = head;
            Node* second = head;
            
            int cnt = 1;
            while(cnt < n && second != NULL)
            {
                second = second->next;
                cnt++;
            }
        
            if(second == NULL) return -1;
        
            while(second->next != NULL)
            {
                first = first->next; 
                second = second->next;
            }
        
            return first->data;
    }
};
