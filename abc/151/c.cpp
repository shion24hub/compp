#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int n, m; cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    rep(i, m) cin >> p[i] >> s[i];

    vector<bool> comp(n, false);
    vector<int> wa_count(n, 0);
    int ac = 0, wa = 0;
    rep(i, m) {
        if (!comp[p[i]] && s[i] == "WA") wa_count[p[i]] ++;
        if (!comp[p[i]] && s[i] == "AC") {
            comp[p[i]] = true;
            ac ++;
            wa += wa_count[p[i]];
        }
    }

    cout << ac << " " << wa << endl;

    return 0;
}