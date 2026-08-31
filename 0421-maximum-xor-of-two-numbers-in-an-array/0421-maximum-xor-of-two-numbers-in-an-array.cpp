class Solution {
public:
    struct Node {
        Node* child[2];

        Node() {
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(int num) {
        Node* curr = root;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (curr->child[bit] == nullptr) {
                curr->child[bit] = new Node();
            }

            curr = curr->child[bit];
        }
    }

    int getMaxXor(int num) {
        Node* curr = root;
        int result = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            // We want the opposite bit to maximize XOR
            int opposite = 1 - bit;

            if (curr->child[opposite] != nullptr) {
                result |= (1 << i);
                curr = curr->child[opposite];
            } 
            else {
                curr = curr->child[bit];
            }
        }

        return result;
    }

    int findMaximumXOR(vector<int>& nums) {

        // Put all numbers into the Trie
        for (int num : nums) {
            insert(num);
        }

        int ans = 0;

        // Find the best partner for every number
        for (int num : nums) {
            ans = max(ans, getMaxXor(num));
        }

        return ans;
    }
};