class Solution {
public:
    set<string> parseUnion(string& s, int& i) {
        set<string> result = parseConcat(s, i);

        while (i < s.size() && s[i] == ',') {
            i++;  // skip ','

            set<string> next = parseConcat(s, i);
            result.insert(next.begin(), next.end());
        }

        return result;
    }

    set<string> parseConcat(string& s, int& i) {
        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {

            set<string> cur;

            if (s[i] == '{') {
                i++;  // skip '{'

                cur = parseUnion(s, i);

                i++;  // skip '}'
            }
            else {
                cur.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (string a : result) {
                for (string b : cur) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> result = parseUnion(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};