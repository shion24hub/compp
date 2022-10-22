#include <bits/stdc++.h>
using namespace std;

int main() {

    int h, w; 
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c[i][j];
        }
    }

    vector<int> ans(w, 0);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (c[i][j] == '#') {
                ans[j] += 1;
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}