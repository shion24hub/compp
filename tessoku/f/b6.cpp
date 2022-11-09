#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n; cin >> n;
    vector<float> a(n); rep(i, n) cin >> a[i];
    int q; cin >> q;
    vector<float> l(q), r(q); rep(i, q) cin >> l[i] >> r[i];

    vector<float> cum(n); cum[0] = a[0];
    for (int i = 1; i < n; i++) cum[i] = cum[i-1] + a[i];

    rep(i, q) {
        float cw = cum[r[i]-1] - cum[l[i]-2];
        float ro = (r[i] - l[i] + 1) / 2;
        if (cw == ro) cout << "draw" << endl;
        else if (cw > ro) cout << "win" << endl;
        else if (cw < ro) cout << "lose" << endl;
    }

    return 0;
}