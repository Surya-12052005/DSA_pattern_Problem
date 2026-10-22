/*
    Problem   : Longest Word with All Prefixes Present
    Difficulty: Medium
    Topic     : Trie

    Given a list of words, find the longest word such that every
    prefix of it is also present in the list. If there is a tie,
    return the lexicographically smallest one.

    Example:
    Input : words = ["w","wo","wor","worl","world"]
    Output: "world"

    Approach:
    - Insert all words into a Trie, marking end-of-word nodes.
    - DFS through the Trie; only continue into a child if it is
      marked as end-of-word (i.e., that prefix is a valid word).
    - Track the longest valid word found (smallest lexicographically
      on ties, achieved naturally since we iterate children a-z in order).

    Time Complexity : O(sum of word lengths)
    Space Complexity: O(sum of word lengths)
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
};

void dfs(TrieNode* node, string& current, string& best) {
    if (current.size() > best.size()) best = current;

    for (int i = 0; i < 26; i++) {
        if (node->children[i] && node->children[i]->isEndOfWord) {
            current.push_back('a' + i);
            dfs(node->children[i], current, best);
            current.pop_back();
        }
    }
}

string longestWord(vector<string>& words) {
    Trie trie;
    for (string& w : words) trie.insert(w);

    string current = "", best = "";
    dfs(trie.root, current, best);
    return best;
}

int main() {
    vector<string> words = {"w","wo","wor","worl","world"};
    cout << "Longest word: " << longestWord(words) << endl;
    return 0;
}
