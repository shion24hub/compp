#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n; cin >> n;

    int sum = 0;
    rep(i, 10)rep(j, 10) sum += (i * j);
    int rem = sum - n;
    for (int i = 1; i < 10; i++) {
        if (rem % i == 0 && (rem / i) <= 9) {
            cout << i << " x " << rem / i << endl;
        }
    }

    return 0;
}