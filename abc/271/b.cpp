#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q;
    cin >> n >> q;
    vector<int> l(n);
    vector<vector<long long>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        int len = l[i];
        for (int j = 0; j < len; j++) {
            int num;
            cin >> num;
            a[i].push_back(num);
        }
    }
    vector<int> s(q), t(q);
    for (int i = 0; i < q; i++) {
        cin >> s[i] >> t[i];
    }

    for (int i = 0; i < q; i++) {
        cout << a[s[i] - 1][t[i] - 1] << endl;
    }

    return 0;
}