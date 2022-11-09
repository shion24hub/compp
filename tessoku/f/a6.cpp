#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n, q; cin >> n >> q;
    vector<int> a(n); rep(i, n) cin >> a[i];
    vector<int> l(q), r(q); rep(i, q) cin >> l[i] >> r[i];

    vector<int> cum(n);
    cum[0] = a[0];
    for (int i = 1; i < n; i++) cum[i] += cum[i-1] + a[i];
    rep(i, q) cout << cum[r[i]-1] - cum[l[i]-2] << endl;

    return 0;
}