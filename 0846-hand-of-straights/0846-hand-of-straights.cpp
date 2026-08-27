class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        // Total cards must be divisible by groupSize
        if (n % groupSize != 0)
            return false;

        map<int, int> freq;

        // Count frequency of every card
        for (int card : hand) {
            freq[card]++;
        }

        // Always start with the smallest available card
        while (!freq.empty()) {
            int start = freq.begin()->first;

            // Try to create a group:
            // start, start+1, ..., start+groupSize-1
            for (int card = start; card < start + groupSize; card++) {

                // Required card doesn't exist
                if (freq.find(card) == freq.end())
                    return false;

                // Use one copy
                freq[card]--;

                // Remove when no copies remain
                if (freq[card] == 0)
                    freq.erase(card);
            }
        }

        return true;
    }
};