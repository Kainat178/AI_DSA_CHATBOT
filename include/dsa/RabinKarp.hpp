#pragma once
#include <vector>
#include <string>
using namespace std;

class RabinKarp {
private:
    const long long base = 256;     // ASCII base
    const long long mod = 1e9 + 7;  // Large prime

public:
    RabinKarp();
    vector<int> search(const string& text, const string& pattern);
};
