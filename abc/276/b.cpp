#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int main() {

    int n, m; cin >> n >> m;
    map<int, vector<int>> roads;
    rep(i, m) {
        int a, b; cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    rep(i, n) {
        if (roads[i+1].size() == 0) {cout << 0 << endl; continue;}
        cout << roads[i+1].size() << " "; 
        sort(roads[i+1].begin(), roads[i+1].end());
        for (int j = 0; j < roads[i+1].size(); j++) cout << roads[i+1][j] << " ";
        cout << endl;
    }

    return 0;
}