class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        // Sort cards because they must be revealed in increasing order
        sort(deck.begin(), deck.end());

        queue<int> q;

        // Store the positions in the order they will be revealed
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        vector<int> ans(n);

        for (int card : deck) {
            // Current front position gets the smallest remaining card
            int pos = q.front();
            q.pop();

            ans[pos] = card;

            // Move the next position to the back
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};