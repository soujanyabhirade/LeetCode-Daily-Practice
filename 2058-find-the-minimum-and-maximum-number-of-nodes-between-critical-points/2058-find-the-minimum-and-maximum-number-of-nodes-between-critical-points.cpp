class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;       // First critical point
        int prev = -1;        // Previous critical point
        int minDist = INT_MAX;

        int index = 1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;

            // Check if current node is a critical point
            bool isCritical =
                (curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val);

            if (isCritical) {

                // First critical point
                if (first == -1) {
                    first = index;
                }

                // We have a previous critical point
                if (prev != -1) {
                    minDist = min(minDist, index - prev);
                }

                prev = index;
            }

            prevNode = curr;
            curr = nextNode;
            index++;
        }

        // Fewer than two critical points
        if (first == -1 || first == prev) {
            return {-1, -1};
        }

        // Maximum distance = last critical - first critical
        int maxDist = prev - first;

        return {minDist, maxDist};
    }
};