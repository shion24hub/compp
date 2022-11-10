#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n; cin >> n;
    vector<int> x(n), y(n); rep(i, n) cin >> x[i] >> y[i];
    int q; cin >> q;
    vector<int> a(q), b(q), c(q), d(q); rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    int sidemax = max(*max_element(x.begin(), x.end()), *max_element(y.begin(), y.end())) + 2;
    vector<vector<bool>> grid(sidemax, vector<bool>(sidemax, false));
    rep(i, n) grid[y[i]][x[i]] = true;

    rep(i, sidemax) {
        rep(j, sidemax) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}