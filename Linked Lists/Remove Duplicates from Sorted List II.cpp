class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Empty list or a list with a single element, no duplicates to delete
        }

        ListNode* dummy = new ListNode(0); // Dummy node to simplify edge cases
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != nullptr) {
            while (current->next != nullptr && current->val == current->next->val) {
                current = current->next;
            }

            // No duplicates found
            if (prev->next == current) {
                prev = prev->next;
            } else {
                // Remove all instances of the duplicated value
                prev->next = current->next;
            }

            current = current->next;
        }

        return dummy->next;
    }
};
