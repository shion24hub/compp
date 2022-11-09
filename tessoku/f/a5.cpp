#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n, k; cin >> n >> k;
    int counter = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (1 <= k - (i + j) && k - (i + j) <= n) counter ++;
        }
    }

    cout << counter << endl;

    return 0;
}