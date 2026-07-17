class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        endOfWord = false;

        // Initially every child is NULL
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        // Create an empty root
        root = new TrieNode();
    }

    void insert(string word) {

        // Start from root
        TrieNode* curr = root;

        // Go through every character
        for (char ch : word) {

            int index = ch - 'a';

            // If child doesn't exist, create it
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            // Move to that child
            curr = curr->children[index];
        }

        // Last character marks end of word
        curr->endOfWord = true;
    }

    bool search(string word) {

        TrieNode* curr = root;

        for (char ch : word) {

            int index = ch - 'a';

            // Character missing
            if (curr->children[index] == nullptr) {
                return false;
            }

            curr = curr->children[index];
        }

        // Word exists only if this node is marked
        return curr->endOfWord;
    }

    bool startsWith(string prefix) {

        TrieNode* curr = root;

        for (char ch : prefix) {

            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                return false;
            }

            curr = curr->children[index];
        }

        // Prefix exists
        return true;
    }
};