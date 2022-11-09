#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    string n; cin >> n;
    int power = 0;
    int ans = 0;
    for (int i = n.size()-1; i >= 0; i--) {
        int num = n[i] - '0';
        ans += (1 << power) * num;
        power ++;
    }

    cout << ans << endl;

    return 0;
}