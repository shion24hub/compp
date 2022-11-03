#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n; cin >> n;
    vector<string> s(n);
    vector<int> p(n);
    rep(i, n) cin >> s[i] >> p[i];

    int sum = 0;
    rep(i, n) sum += p[i];
    
    rep(i, n) {
        if (p[i] > sum / 2) {cout << s[i] << endl; return 0;}
    }

    cout << "atcoder" << endl;

    return 0;
}