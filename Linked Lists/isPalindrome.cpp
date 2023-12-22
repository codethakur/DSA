class Solution{
  private:
    Node* getMid(Node* head ) {
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        Node* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->data != head1->data) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
    }
}; /*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
#include<vector>

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool cheackPalindrome(std::vector<int> arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            if (arr[start] != arr[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int>array;
        Node* temp = head;
        while(temp!=NULL)
        {
            array.push_back(temp->data);
            temp=temp->next;
        }
        return cheackPalindrome(array);
        
    }
};*/
