#include <iostream>
#include "dsa/KMP.hpp"

int main() {
    KMP k;
    auto res = k.search("ababcabcabababd", "ababd");

    for (int x : res) cout << x << " ";
}
