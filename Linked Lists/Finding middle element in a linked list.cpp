/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
class Solution{
    public:
    /* Should return data of middle node. If linked list is empty, then  -1*/
    int getlength(Node* head)
    {
        int length=0;
        while(head!=NULL)
        {
            length++;
            head=head->next;
        }
        return length;
    }
    int getMiddle(Node *head)
    {
        // Your code here
        int length = getlength(head);
        int ans = (length / 2);
        int cnt = 0;
        Node *temp = head;
        while (cnt < ans)
        {
            temp = temp->next;
            cnt++;
        }
        return temp->data;  // Return the data of the middle node, not the pointer
    }
};

/*``````````````````Approch 2``````````````````````````````*/
int getMiddle(Node *head)
    {
        // Your code here
        if (head == NULL)
        {
            return -1; // Return -1 for an empty list
        }
    
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    
        return slow->data;
    }
