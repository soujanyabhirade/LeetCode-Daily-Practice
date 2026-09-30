class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer;
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;
                answer.push_back(depth % 2);
            } else {
                answer.push_back(depth % 2);
                depth--;
            }
        }

        return answer;
    }
};