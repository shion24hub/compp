#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans(2 * n + 2);
    ans[1] = 0;

    for (int i = 1; i <= n; i++) {
        int parent = a[i - 1];
        int child1 = i * 2;
        int child2 = i * 2 + 1;
        ans[child1] = ans[parent] + 1;
        ans[child2] = ans[parent] + 1;
    }

    for (int i = 1; i <= 2 * n + 1; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}