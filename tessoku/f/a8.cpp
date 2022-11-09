#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    //入力
    int h, w; cin >> h >> w;
    vector<vector<int>> x(h, vector<int>(w)); rep(i, h)rep(j, w) cin >> x[i][j];
    int q; cin >> q;
    vector<int> a(q), b(q), c(q), d(q); rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    //累積和
    vector<vector<int>> cumx(h, vector<int>(w)), cumy(h, vector<int>(w));
    rep(i, h) rep(j, w) {
        if (j == 0) {
            cumx[i][j] = x[i][j];
            continue;
        }
        cumx[i][j] = cumx[i][j-1] + x[i][j];
    }
    rep(j, w) rep(i, h) {
        if (i == 0) {
            cumy[i][j] = cumx[i][j];
            continue;
        }
        cumy[i][j] = cumy[i-1][j] + cumx[i][j];
    }
    
    //処理
    rep(i, q) {
        if (a[i] > 1 && b[i] > 1) {
            cout << cumy[c[i]-1][d[i]-1] - cumy[a[i]-2][d[i]-1] - (cumy[c[i]-1][b[i]-2] - cumy[a[i]-2][b[i]-2]) << endl;
        } else if (a[i] > 1 && b[i] == 1) {
            cout << cumy[c[i]-1][d[i]-1] - cumy[a[i]-2][d[i]-1] << endl;
        } else if (a[i] == 1 && b[i] > 1) {
            cout << cumy[c[i]-1][d[i]-1] - cumy[c[i]-1][b[i]-2] << endl;
        }
        else {
            cout << cumy[c[i]-1][d[i]-1] << endl;
        }
    }

    return 0;
}