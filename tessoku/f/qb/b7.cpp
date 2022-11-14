#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int t, n; cin >> t >> n;
    vector<int> l(n), r(n); rep(i, n) cin >> l[i] >> r[i];

    vector<int> change(t+1);
    rep(i, n) {
        change[l[i]] += 1;
        change[r[i]] -= 1;
    }
    int cum = 0;
    rep(i, t) {
        cout << change[i] + cum << endl;
        cum += change[i];
    }

    return 0;
}