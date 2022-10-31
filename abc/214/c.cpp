#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int n; cin >> n;
    vector<long long> s(n); rep(i, n) cin >> s[i];
    vector<long long> t(n); rep(i, n) cin >> t[i];

    vector<bool> is_first(n, false);
    long long minn = *min_element(t.begin(), t.end());
    rep(i, n) {
        if (t[i] == minn) is_first[i] = true;
    }
    //1周目
    vector<long long> ans(n, 0);
    rep(i, n) {
        if (is_first[i]) ans[i] = t[i];
        else {
            if (i != 0 && ans[i-1] != 0) ans[i] = min(t[i], ans[i-1] + s[i-1]);
            else if (i != 0 && ans[i-1] == 0) continue;
            else if (i == 0 && ans[i-1] != 0) ans[i] = min(t[i], ans[n-1] + s[n-1]);
            else continue;
        }
    }
    //2周目
    rep(i, n) {
        if (i != 0) ans[i] = min(t[i], ans[i-1] + s[i-1]);
        else if (i == 0) ans[i] = min(t[i], ans[n-1] + s[n-1]);
    }

    rep(i, n) cout << ans[i] << endl;

    return 0;
}