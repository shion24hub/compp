#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    string s; cin >> s;
    map<char, int> counter;
    for (char alpha : s) counter[alpha] += 1;
    int kind = 0;
    for (auto p : counter) kind ++;
    if (kind == 1) cout << 1 << endl;
    else if (kind == 2) cout << 3 << endl;
    else cout << 6 << endl;

    return 0;
}