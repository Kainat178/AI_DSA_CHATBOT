#include <iostream>
#include "dsa/Stack.hpp"
using namespace std;

int main() {
    StackDS s;

    s.push(5);
    s.push(15);
    s.push(25);

    cout << "Top: " << s.top() << endl;

    s.pop();
    cout << "After pop, top: " << s.top() << endl;

    vector<int> all = s.getAll();
    cout << "Stack contents: ";
    for (int x : all) cout << x << " ";
    cout << endl;

    return 0;
}
