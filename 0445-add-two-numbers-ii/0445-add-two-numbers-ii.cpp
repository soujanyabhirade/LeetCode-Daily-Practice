class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1;
        stack<int> s2;

        // Put first list into stack
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        // Put second list into stack
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;

        // Add from right to left
        while (!s1.empty() || !s2.empty() || carry != 0) {

            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            int digit = sum % 10;
            carry = sum / 10;

            // Create node
            ListNode* node = new ListNode(digit);

            // Insert at beginning
            node->next = head;
            head = node;
        }

        return head;
    }
};