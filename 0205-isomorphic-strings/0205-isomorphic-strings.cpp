class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapST[256] = {};
        int mapTS[256] = {};

        for (int i = 0; i < s.size(); i++) {
            unsigned char a = s[i];
            unsigned char b = t[i];

            // s -> t mapping
            if (mapST[a] != 0 && mapST[a] != b + 1)
                return false;

            // t -> s mapping
            if (mapTS[b] != 0 && mapTS[b] != a + 1)
                return false;

            mapST[a] = b + 1;
            mapTS[b] = a + 1;
        }

        return true;
    }
};