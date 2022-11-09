#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n, x; cin >> n >> x;
    vector<int> a(n);rep(i, n) cin >> a[i];
    bool ans = false;
    rep(i, n) {
        if (a[i] == x) ans = true;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}