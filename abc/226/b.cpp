#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n; cin >> n;
    map<int, vector<vector<long long>>> lvec;
    rep(i, n) {
        int l; cin >> l;
        vector<long long> a(l);
        rep(j, l) cin >> a[j];
        lvec[l].push_back(a);
    }

    for (auto p : lvec) {
        for (int i = 0; i < p.first; i++){
            p.second[i];
        }
    }

    return 0;
}