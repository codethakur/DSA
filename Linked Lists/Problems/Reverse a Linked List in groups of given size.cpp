struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        // Complete this method
        node* prevNode = NULL;
        node* currNode = head;
        node* NextNode = NULL;
        
        int count = 0;
        
        while(currNode!=NULL && count < k)
        {
            NextNode= currNode->next;
            currNode->next=prevNode;
            prevNode = currNode;
            currNode= NextNode;
            count++;
        }
        
        if (NextNode != NULL)
        {
            head->next = reverseIt(NextNode, k);
        }
        return prevNode;
    }
};
