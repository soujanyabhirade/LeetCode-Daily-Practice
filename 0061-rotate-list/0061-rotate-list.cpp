class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Remove unnecessary full rotations
        k %= n;

        if (k == 0)
            return head;

        // Make it circular
        tail->next = head;

        // New tail is n-k-1 positions from head
        ListNode* newTail = head;

        for (int i = 1; i < n - k; i++) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};