#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int n; cin >> n;
    vector<int> a_above(n); rep(i, n) cin >> a_above[i];
    vector<int> a_below(n); rep(i, n) cin >> a_below[i];

    vector<int> culsum_below(n);
    culsum_below[n-1] = a_below[n-1];
    for (int i = n-2; i >= 0; i--) culsum_below[i] = a_below[i] + culsum_below[i+1];

    vector<int> anss(n);
    int culsum_above = 0;
    for (int i = 0; i < n; i++) {
        culsum_above += a_above[i];
        anss[i] = culsum_above + culsum_below[i];
    }

    int ans = *max_element(anss.begin(), anss.end());
    cout << ans << endl;

    return 0;
}