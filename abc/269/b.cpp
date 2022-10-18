#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<string>s;
    for (int i = 0; i < 10; i++) {
        string dots;
        cin >> dots;
        s.push_back(dots);
    }

    vector<int> ilen;
    int is, ie, js, je;
    for (int i = 0; i < 10; i++) {
        vector<int> jlen;
        bool bi = false;
        for (int j = 0; j < 10; j++) {
            if (s[i][j] == '#') {
                bi = true;
                jlen.push_back(j);
            }
        }
        if (bi) {
            ilen.push_back(i);
            js = jlen[0];
            je = jlen[jlen.size() - 1];
        }
    }
    is = ilen[0];
    ie = ilen[ilen.size() - 1];

    cout << is + 1 << " " << ie + 1 << endl;
    cout << js + 1 << " " << je + 1 << endl;

    return 0;
}