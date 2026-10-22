/*
    Problem   : Implement Trie (Prefix Tree)
    Difficulty: Medium
    Topic     : Trie

    Implement a Trie with insert, search, and startsWith methods.

    Example:
    insert("apple")
    search("apple")     -> true
    search("app")       -> false
    startsWith("app")   -> true

    Approach:
    - Each Trie node has an array/map of children (one per character)
      and a boolean flag marking the end of a word.
    - insert: walk down the trie, creating nodes as needed.
    - search: walk down the trie; return true only if we reach a node
      that is marked as end-of-word.
    - startsWith: same walk, but don't check the end-of-word flag.

    Time Complexity : O(L) per operation, L = length of word
    Space Complexity: O(total characters inserted)
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;     // 1 (true)
    cout << trie.search("app") << endl;       // 0 (false)
    cout << trie.startsWith("app") << endl;   // 1 (true)
    trie.insert("app");
    cout << trie.search("app") << endl;       // 1 (true)
    return 0;
}
