#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int n; cin >> n;
    vector<vector<char>> s(n, vector<char>(n));
    rep(i, n)rep(j, n) cin >> s[i][j];

    for (int j = 0; j < n; j++) {
        for (int i = n-1; i >= 0; i--) {
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}