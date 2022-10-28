#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

// corner case
// 3 5
// 12 13 14 15 16
// 19 20 21 22 23
// 26 27 28 29 30
// 
// 7の倍数が来たら折り返していなければならない。

int main() {

    int n, m; cin >> n >> m;
    vector<vector<long long>> b(n, vector<long long>(m));
    rep(i, n)rep(j, m) cin >> b[i][j];

    bool yoko = true, tate = true;
    //yoko
    bool complete = false;
    if (m > 1) {
        for (int i = 0; i < n; i++) {
            long long p = b[i][0];
            for (int j = 1; j < m; j++) {
                if (p % 7 == 0) {
                    yoko = false;
                    complete = true;
                    break;
                }
                if (b[i][j] - p == 1) p = b[i][j];
                else {
                    yoko = false;
                    complete = true;
                    break;
                }
            }
            if (complete) break;
        }
    }
    //tate
    if (n > 1) {
        complete = false;
        for (int j = 0; j < m; j++) {
            long long p = b[0][j]; 
            for (int i = 1; i < n; i++) {
                if (b[i][j] - p == 7) p = b[i][j];
                else {
                    tate = false;
                    complete = true;
                    break;
                }
            }
            if (complete) break;
        }
    }

    if (yoko && tate) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}