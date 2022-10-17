#include <bits/stdc++.h>
using namespace std;

int rec(int x) {
    if (x == 0) {
        return 1;
    } else {
        return x * rec(x - 1);
    }
}

int main() {

    int n;
    cin >> n;

    int ans = rec(n);

    cout << ans << endl;

    return 0;
}