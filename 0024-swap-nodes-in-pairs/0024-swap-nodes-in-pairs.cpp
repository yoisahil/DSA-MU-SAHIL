class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // swap the pair
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // move to the next pair
            prev = first;
        }

        return dummy.next;
    }
};