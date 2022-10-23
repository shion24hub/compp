#include <bits/stdc++.h>
using namespace std;

int main() {

    int h, w; cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> g[i][j];

    vector<int> pos = {0, 0};
    vector<vector<bool>> visited(h, vector<bool>(w));
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) visited[i][j] = false;
    while (true) {
        if (g[pos[0]][pos[1]] == 'U' && pos[0] != 0) {
            if (visited[pos[0]][pos[1]]) {
                cout << -1 << endl;
                return 0;
            }
            visited[pos[0]][pos[1]] = true;
            pos[0] -= 1;
        }
        else if (g[pos[0]][pos[1]] == 'D' && pos[0] != h - 1) {
            if (visited[pos[0]][pos[1]]) {
                cout << -1 << endl;
                return 0;
            }
            visited[pos[0]][pos[1]] = true;
            pos[0] += 1;
        }
        else if (g[pos[0]][pos[1]] == 'L' && pos[1] != 0) {
            if (visited[pos[0]][pos[1]]) {
                cout << -1 << endl;
                return 0;
            }
            visited[pos[0]][pos[1]] = true;
            pos[1] -= 1;
        }
        else if (g[pos[0]][pos[1]] == 'R' && pos[1] != w - 1) {
            if (visited[pos[0]][pos[1]]) {
                cout << -1 << endl;
                return 0;
            }
            visited[pos[0]][pos[1]] = true;
            pos[1] += 1;
        }
        else break;
    }

    cout << pos[0] + 1 << " " << pos[1] + 1 << endl;

    return 0;
}