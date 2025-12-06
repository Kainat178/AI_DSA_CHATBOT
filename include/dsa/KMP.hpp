#pragma once
#include <vector>
#include <string>
using namespace std;

class KMP {
private:
    vector<int> buildLPS(const string& pattern);

public:
    KMP();
    vector<int> search(const string& text, const string& pattern);
};
