class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;

        for (int i = 0; i < word.size(); i++) {
            int alphabet_idx = word[i] - 'a';
            if (!cur->children[alphabet_idx]) cur->children[alphabet_idx] = new TrieNode();
            cur = cur->children[alphabet_idx];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;

        for (int i = 0; i < word.size(); i++) {
            int alphabet_idx = word[i] - 'a';
            if (!cur->children[alphabet_idx]) return false;
            cur = cur->children[alphabet_idx];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;

        for (int i = 0; i < prefix.size(); i++) {
            int alphabet_idx = prefix[i] - 'a';
            if (!cur->children[alphabet_idx]) return false;
            cur = cur->children[alphabet_idx];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */