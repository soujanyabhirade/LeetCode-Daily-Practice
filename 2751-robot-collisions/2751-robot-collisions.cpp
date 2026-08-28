
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                       vector<int>& healths,
                                       string directions) {
        
        int n = positions.size();

        // Store robot indices
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        // Process robots from left to right
        sort(order.begin(), order.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        // Stack contains indices of surviving R robots
        vector<int> st;

        for (int idx : order) {

            // Right-moving robot
            if (directions[idx] == 'R') {
                st.push_back(idx);
                continue;
            }

            // Left-moving robot
            while (!st.empty() && healths[idx] > 0) {

                int rightRobot = st.back();

                // Right robot has lower health -> it dies
                if (healths[rightRobot] < healths[idx]) {
                    healths[idx]--;
                    healths[rightRobot] = 0;
                    st.pop_back();
                }

                // Left robot has lower health -> it dies
                else if (healths[rightRobot] > healths[idx]) {
                    healths[rightRobot]--;
                    healths[idx] = 0;
                    break;
                }

                // Equal health -> both die
                else {
                    healths[rightRobot] = 0;
                    healths[idx] = 0;
                    st.pop_back();
                    break;
                }
            }
        }

        // Return survivors in original input order
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};

