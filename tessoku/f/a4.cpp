#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n; cin >> n;
    for (int i = 9; i >= 0; i--) {
        int div = (1 << i);
        cout << (n / div) % 2;
    }
    cout << endl;

    return 0;
}