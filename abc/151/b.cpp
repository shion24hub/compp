#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int n, k, m; cin >> n >> k >> m;
    vector<int> a(n-1); rep(i, n-1) cin >> a[i];
    int sum = 0; rep(i, n-1) sum += a[i];

    int std = m * n - sum;
    if (k < std) cout << -1 << endl;
    else if (std < 0) cout << 0 << endl;
    else cout << std << endl;

    return 0;
}