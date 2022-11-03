#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n; cin >> n;
    vector<long long> h(n); rep(i, n) cin >> h[i];

    if (n == 1) {cout << "Yes" << endl; return 0;}
    if (n == 2) {
        if (h[0] <= h[1]) {cout << "Yes" << endl; return 0;}
        else if (h[0]-1 <= h[1]) {cout << "Yes" << endl; return 0;}
        else if (h[0] <= h[1]-1) {cout << "Yes" << endl; return 0;}
        else cout << "No" << endl; return 0;
    }
    bool ans = true;
    long long p;
    for (int i = 0; i < n-1; i++) {
        long long std = h[i];
        if (std <= h[i+1]) continue;
        else {
            std -= 1;
            if (i != 0) {
                if(h[i-1] <= std && std <= h[i+1]) continue;
                else {
                    ans = false;
                    break;
                }
            }
            else {
                if (std <= h[i+1]) continue;
                else {
                    ans = false;
                    break;
                }
            }
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}