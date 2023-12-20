/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/
/*`````````````````````Approch 1St T.C. O(N) S.P. O(1)```````````````````````````*/
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* prevNode = NULL;
        Node* currNode = head;
        Node* NextNode=NULL;
        while(currNode!=NULL)
        {
            NextNode = currNode->next;
            currNode->next=prevNode;
            prevNode= currNode;
            currNode=NextNode;
            
        }
        return prevNode;
    }
    
};
