class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                 vector<string>& dictionary) {
        vector<string> ans;

        for (string query : queries) {
            bool found = false;

            for (string word : dictionary) {
                int diff = 0;

                for (int i = 0; i < query.size(); i++) {
                    if (query[i] != word[i])
                        diff++;

                    if (diff > 2)
                        break;
                }

                if (diff <= 2) {
                    found = true;
                    break;
                }
            }

            if (found)
                ans.push_back(query);
        }

        return ans;
    }
};