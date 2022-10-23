#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, m, t; cin >> n >> m >> t;
    vector<long long> a(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    map<long long, long long> room;
    for (int i = 0; i < m; i++) {
        long long x, y; cin >> x >> y;
        room[x] = y;
    }

    for (int i = 0; i < n - 1; i++) {
        if (t - a[i] > 0) {
            t -= a[i];
            if (room.count(i + 2)) t += room[i + 2];
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}