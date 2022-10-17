#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> x(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i];
        int len = k[i];
        for (int j = 0; j < len; j++) {
            int person;
            cin >> person;
            x[i].push_back(person);
        }
    }

    map<int, set<int>> counter;
    for (int i = 0; i < m; i++) {
        int len = k[i];
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len; k++) {
                if (j == k) continue;
                counter[x[i][j]].insert(x[i][k]);
                counter[x[i][j]].insert(x[i][j]);
            }
        }
    }

    // cout << "debug" << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << "i = " << i << endl;
    //     for (auto x : counter[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "debug" << endl;

    for (int i = 1; i <= n; i++) {
        if (counter[i].size() == n) {
            continue;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}