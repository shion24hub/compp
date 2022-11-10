#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

void p2dveci(vector<vector<int>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
}

void p2dvecll(vector<vector<long long>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

void p2dvecc(vector<vector<char>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

void p2dvecs(vector<vector<string>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    //input
    int h, w, n; cin >> h >> w >> n;
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) {
        // convert to 0-indexed.
        int ia, ib, ic, id; cin >> ia >> ib >> ic >> id;
        a[i] = ia-1; b[i] = ib-1; c[i] = ic-1; d[i] = id-1;
    }

    //cum
    vector<vector<int>> grid(h, vector<int>(w, 0));
    rep(i, n) {
        grid[a[i]][b[i]] += 1;
        if (d[i]+1 < w) grid[a[i]][d[i]+1] += -1;
        if (c[i]+1 < h) grid[c[i]+1][b[i]] += -1;
        if (c[i]+1 < h && d[i]+1 < w) grid[c[i]+1][d[i]+1] += 1;
    }
    for (int i = 0; i < h; i++) for (int j = 1; j < w; j++) grid[i][j] += grid[i][j-1];
    for (int j = 0; j < w; j++) for (int i = 1; i < h; i++) grid[i][j] += grid[i-1][j];

    //output
    p2dveci(grid);

    return 0;
}