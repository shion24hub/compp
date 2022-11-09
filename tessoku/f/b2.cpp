#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int a, b; cin >> a >> b;
    bool ans = false;
    for (int i = a; i <= b; i++) {
        if (100 % i == 0) ans = true;
    }   
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}