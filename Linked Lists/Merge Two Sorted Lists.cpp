/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //O(M+N) time space 
    /*
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->val < list2->val)
        {
            list1->next = merge(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next = merge(list1, list2->next);
            return list2;
        }
    }
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
           // return merge(list1, list2);
           if(list1==NULL) return list2;
           if(list2==NULL) return list1;

           ListNode* ans, *tail;

           if(list1->val < list2->val)
           {
               ans = list1;
               list1 = list1->next;
               tail= ans;
           }
           else
           {
               ans = list2;
               list2  = list2->next;
               tail = ans;
           }
           while(list1!=NULL && list2!=NULL)
           {
               if(list1->val < list2->val)
               {
                   tail->next=list1;
                   tail = list1;
                   list1=list1->next;
               }
               else
               {
                   tail->next=list2;
                   tail = list2;
                   list2 = list2->next;
               }
           }
        if(list1==NULL) tail->next=list2;
        else tail->next=list1;
        return ans;

    }      
    //The time complexity of this algorithm is O(m + n),where m and n are the lengths of the input lists, since you visit each node of each list once. 
    //The space complexity is O(1), since I only use a constant amount of additional memory to store the ans and tail pointers.
};
