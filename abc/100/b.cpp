#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int d, n; cin >> d >> n;
    if (n < 100) {
        long long ans = pow(100, d) * n;
        cout << ans << endl;
    } 
    else {
        long long ans = 101 * pow(100, d);
        cout << ans << endl;
    }
    return 0;
}