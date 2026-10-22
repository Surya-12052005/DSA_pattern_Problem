/*
    Problem   : Count Distinct Words Starting With a Given Prefix
    Difficulty: Easy
    Topic     : Trie

    Given a list of words and multiple prefix queries, return the
    count of words that start with each given prefix.

    Example:
    Input : words = ["apple","app","application","banana"], prefix = "app"
    Output: 3

    Approach:
    - Insert all words into a Trie; each node stores a counter for
      how many words pass through it (prefix count).
    - insert: increment prefixCount at every node visited.
    - countWordsWithPrefix: walk to the prefix's node, return its
      prefixCount (0 if the prefix path doesn't exist).

    Time Complexity : O(L) per insert/query, L = word/prefix length
    Space Complexity: O(total characters inserted)
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int prefixCount;
    TrieNode() {
        prefixCount = 0;
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
            node->prefixCount++;
        }
    }

    int countWordsWithPrefix(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return 0;
            node = node->children[idx];
        }
        return node->prefixCount;
    }
};

int main() {
    vector<string> words = {"apple","app","application","banana"};
    Trie trie;
    for (string& w : words) trie.insert(w);

    cout << "Count with prefix 'app': " << trie.countWordsWithPrefix("app") << endl;
    return 0;
}
