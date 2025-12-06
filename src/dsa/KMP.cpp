#include "dsa/KMP.hpp"

KMP::KMP() {}

vector<int> KMP::buildLPS(const string& pattern) {
    vector<int> lps(pattern.size());
    int len = 0, i = 1;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

vector<int> KMP::search(const string& text, const string& pattern) {
    vector<int> positions;
    if (pattern.empty()) return positions;

    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }

        if (j == pattern.size()) {
            positions.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < text.size() && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return positions;
}
