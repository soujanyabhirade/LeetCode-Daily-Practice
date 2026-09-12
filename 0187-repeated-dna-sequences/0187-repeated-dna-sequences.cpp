class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq;
        vector<string> ans;

        for (int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10);

            freq[sub]++;

            // Add only when it becomes repeated for the first time
            if (freq[sub] == 2)
                ans.push_back(sub);
        }

        return ans;
    }
};