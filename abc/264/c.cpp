#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int h1, w1; cin >> h1 >> w1;
    vector<vector<int>> a(h1, vector<int>(w1));
    rep(i, h1)rep(j, w1) cin >> a[i][j];
    int h2, w2; cin >> h2 >> w2;
    vector<vector<int>> b(h2, vector<int>(w2));
    rep(i, h2) rep(j, w2) cin >> b[i][j];

    

    return 0;
}