#include "dsa/Trie.hpp"
#include <iostream>

// Constructor
Trie::Trie() {
    root = new Node();
}

// Destructor → free all nodes
void Trie::freeMemory(Node* node) {
    if (!node) return;
    for (int i = 0; i < 26; i++)
        freeMemory(node->children[i]);
    delete node;
}

Trie::~Trie() {
    freeMemory(root);
}

// ---------------- INSERT ----------------
void Trie::insert(const string& word) {
    Node* current = root;

    for (char ch : word) {
        int index = ch - 'a';
        if (index < 0 || index > 25) continue; // ignore invalid characters

        if (!current->children[index])
            current->children[index] = new Node();

        current = current->children[index];
    }
    current->isEnd = true;
}

// ---------------- SEARCH ----------------
bool Trie::search(const string& word) const {
    Node* current = root;

    for (char ch : word) {
        int index = ch - 'a';
        if (index < 0 || index > 25) return false;

        if (!current->children[index])
            return false;

        current = current->children[index];
    }

    return current->isEnd;
}

// ---------------- STARTS WITH ----------------
bool Trie::startsWith(const string& prefix) const {
    Node* current = root;

    for (char ch : prefix) {
        int index = ch - 'a';
        if (index < 0 || index > 25) return false;

        if (!current->children[index])
            return false;

        current = current->children[index];
    }

    return true;
}