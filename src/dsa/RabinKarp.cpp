#include "dsa/RabinKarp.hpp"


RabinKarp::RabinKarp() {}

vector<int> RabinKarp::search(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.size(), m = pattern.size();
    if (m > n || m == 0) return result;

    long long patternHash = 0, textHash = 0, h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % mod;

    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * base + pattern[i]) % mod;
        textHash = (textHash * base + text[i]) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            if (text.substr(i, m) == pattern)
                result.push_back(i);
        }

        if (i < n - m) {
            textHash = (textHash - text[i] * h) % mod;
            textHash = (textHash * base + text[i + 1]) % mod;
            if (textHash < 0) textHash += mod;
        }
    }
    return result;
}
