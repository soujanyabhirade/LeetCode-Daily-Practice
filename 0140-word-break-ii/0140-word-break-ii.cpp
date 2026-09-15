class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> solve(string& s, int start) {
        if (start == s.size())
            return {""};

        if (memo.count(start))
            return memo[start];

        vector<string> ans;

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);

            if (dict.find(word) == dict.end())
                continue;

            vector<string> rest = solve(s, end);

            for (string sentence : rest) {
                if (sentence.empty())
                    ans.push_back(word);
                else
                    ans.push_back(word + " " + sentence);
            }
        }

        return memo[start] = ans;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict)
            dict.insert(word);

        return solve(s, 0);
    }
};