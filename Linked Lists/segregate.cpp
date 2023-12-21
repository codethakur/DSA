/* struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    void insertAtTail(Node* &tail, Node* curr ) {
        tail -> next = curr;
        tail = curr;
    }

    Node* segregate(Node *head) {
        
        // Add code here
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead = new Node(-1);
        Node* oneTail = oneHead;
        Node* twoHead = new Node(-1);
        Node* twoTail = twoHead;
        
        Node* curr = head;
        
        // create separate list 0s, 1s and 2s
        while(curr != NULL) {
            
            int value = curr -> data;
            
            if(value == 0) {
                insertAtTail(zeroTail, curr);
            }
            else if(value == 1) {
                insertAtTail(oneTail, curr);
            }
            else if(value == 2) {
                insertAtTail(twoTail, curr);
            }       
            curr = curr -> next;
        }
        
        //merge 3 sublist
        
        // 1s list not empty
        if(oneHead -> next != NULL) {
            zeroTail -> next = oneHead -> next;
        }
        else {
            //1s list -> empty
            zeroTail -> next = twoHead -> next;
        }
        
        oneTail -> next = twoHead -> next;
        twoTail -> next = NULL;
        
    	//setup head 
        head = zeroHead -> next;
        
        //delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
        
    }
};
///////////// Another Way ///////////////////////

/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
     int zeroCount = 0;
     int oneCount = 0;
     int twoCount = 0;
 
     Node* temp = head;
 
     // Count the occurrences of 0s, 1s, and 2s
     while (temp != NULL) {
         if (temp->data == 0)
             zeroCount++;
         else if (temp->data == 1)
             oneCount++;
         else if (temp->data == 2)
             twoCount++;
 
         temp = temp->next;
     }
 
     temp = head;
 
     // Update the linked list based on the counts
     while (temp != NULL) {
         if (zeroCount != 0) {
             temp->data = 0;
             zeroCount--;
         } else if (oneCount != 0) {
             temp->data = 1;
             oneCount--;
         } else if (twoCount != 0) {
             temp->data = 2;
             twoCount--;
         }
 
         temp = temp->next;
     }
 
     return head;
        
    }
};
