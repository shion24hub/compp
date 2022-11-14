#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

void p2dveci(vector<vector<int>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
}

void p2dvecll(vector<vector<long long>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
}

void p2dvecc(vector<vector<char>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
}

void p2dvecs(vector<vector<string>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {

    //input
    int n; cin >> n;
    vector<int> a(n); rep(i, n) cin >> a[i];
    int d; cin >> d;
    vector<int> l(d), r(d);
    rep(i, d) {
        int il, ir; cin >> il >> ir;
        l[i] = il-1; r[i] = ir-1;
    }

    vector<set<int>> ranking(n); ranking[0].insert(a[0]);
    for (int i = 1; i < n; i++) {
        ranking[i] = ranking[i-1];
        ranking[i].insert(a[i]);
    }

    for (int i = 0; i < d; i++) {
        set<int> diff;
        set<int> anss;
        set_difference(ranking[r[i]].begin(), ranking[r[i]].end(), ranking[l[i]-1].begin(), ranking[l[i]-1].end(), inserter(diff, end(diff)));
        set_difference(ranking[n-1].begin(), ranking[n-1].end(), diff.begin(), diff.end(), inserter(anss, end(anss)));
        cout << *rbegin(anss) << endl;
    }

    return 0;
}