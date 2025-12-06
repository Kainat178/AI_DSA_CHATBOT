#pragma once
#include <string>
using namespace std;

class Trie {
private:
    struct Node {
        bool isEnd;
        Node* children[26];

        Node() : isEnd(false) {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    Node* root;

    void freeMemory(Node* node);        // Helper to delete all nodes

public:
    Trie();
    ~Trie();

    void insert(const string& word);
    bool search(const string& word) const;
    bool startsWith(const string& prefix) const;
};
