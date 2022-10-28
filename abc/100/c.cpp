#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int n; cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = a[i];
        int counter = 0;
        while (true) {
            if (num % 2 == 0) {
                num /= 2;
                counter ++;
            }
            else break;
        }
        sum += counter;
    }

    cout << sum << endl;

    return 0;
}