#include <iostream>
#include "dsa/Trie.hpp"
using namespace std;

int main() {
    Trie t;
    t.insert("apple");
    t.insert("app");
    cout << t.search("app") << endl;        // expected: 1 (true)
    cout << t.search("appl") << endl;       // expected: 0 (false)
    return 0;
}
