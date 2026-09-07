class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";

        vector<string> ans;

        for (string word : words) {
            string w = word;

            // Convert to lowercase
            for (char &c : w) {
                c = tolower(c);
            }

            int row;

            if (row1.find(w[0]) != string::npos)
                row = 1;
            else if (row2.find(w[0]) != string::npos)
                row = 2;
            else
                row = 3;

            bool valid = true;

            for (char c : w) {
                if (row == 1 && row1.find(c) == string::npos) {
                    valid = false;
                    break;
                }

                if (row == 2 && row2.find(c) == string::npos) {
                    valid = false;
                    break;
                }

                if (row == 3 && row3.find(c) == string::npos) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};