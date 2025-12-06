#include <iostream>
#include "dsa/RabinKarp.hpp"
using namespace std;

int main() {
    RabinKarp rk;

    string text = "bananabanaba";
    string pattern = "naba";

    auto res = rk.search(text, pattern);

    cout << "Rabin-Karp result: ";
    for (int pos : res) cout << pos << " ";
    cout << endl;

    return 0;
}
