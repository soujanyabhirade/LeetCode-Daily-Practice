class WordDictionary {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->child[index] == nullptr)
                curr->child[index] = new Node();

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    bool dfs(Node* curr, string& word, int index) {
        if (index == word.size())
            return curr->isEnd;

        char c = word[index];

        // Normal character
        if (c != '.') {
            int x = c - 'a';

            if (curr->child[x] == nullptr)
                return false;

            return dfs(curr->child[x], word, index + 1);
        }

        // '.' can match any character
        for (int i = 0; i < 26; i++) {
            if (curr->child[i] != nullptr) {
                if (dfs(curr->child[i], word, index + 1))
                    return true;
            }
        }

        return false;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};