class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters;
        vector<string> digits;

        // Separate letter-logs and digit-logs
        for (string log : logs) {
            int pos = log.find(' ');

            if (isdigit(log[pos + 1])) {
                digits.push_back(log);
            } else {
                letters.push_back(log);
            }
        }

        // Sort letter-logs
        sort(letters.begin(), letters.end(), [](const string& a, const string& b) {
            int posA = a.find(' ');
            int posB = b.find(' ');

            string contentA = a.substr(posA + 1);
            string contentB = b.substr(posB + 1);

            if (contentA == contentB) {
                // If contents are same, compare identifiers
                return a.substr(0, posA) < b.substr(0, posB);
            }

            return contentA < contentB;
        });

        // Letter logs first, digit logs afterwards
        letters.insert(letters.end(), digits.begin(), digits.end());

        return letters;
    }
};