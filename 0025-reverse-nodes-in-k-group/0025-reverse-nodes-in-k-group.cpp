class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            // find the k-th node from groupPrev
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;  // fewer than k nodes left

            ListNode* groupNext = kth->next;

            // reverse the group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            // reconnect with the previous part
            ListNode* newGroupTail = groupPrev->next;  // old first node, now the tail
            groupPrev->next = kth;                     // kth is the new head of the group
            groupPrev = newGroupTail;
        }

        return dummy.next;
    }
};