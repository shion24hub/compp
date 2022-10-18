#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m; cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> sum = {a[0]};
    for (int i = 1; i < n; i++) sum.push_back(sum[i - 1] + a[i]);

    long long max = 0;
    for (int i = 0; i < n - m + 1; i++) {
        if (i == 0) {
            for (int j = 0; j < m; j++) {
                max += a[j] * (j + 1);
            }
        }
        else {
            long long sub;
        }
    }

    return 0;
}