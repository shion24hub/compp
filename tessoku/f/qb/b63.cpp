#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

vector<char> UPPERCASE = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> LOWERCASE = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << ' ';
  print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << ' ';
  }
  cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}

//binary search (int)
int binsi(int left, int right, int key, vector<int> vec) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key == vec[mid]) return mid;
        else if (key < vec[mid]) right = mid - 1;
        else if (vec[mid] < key) left = mid + 1; 
    }
    return -1;
}

//binary search (long long)
int binsll(int left, int right, long long key, vector<long long> vec) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key == vec[mid]) return mid;
        else if (key < vec[mid]) right = mid - 1;
        else if (vec[mid] < key) left = mid + 1; 
    }
    return -1;
}

int main() {

    int h, w; cin >> h >> w;
    int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
    vector<string> c(h);
    rep(i, h) cin >> c[i];

    int start = sy * w + sx, goal = gy * w + gx;
    map<int, vector<int>> tree;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w-1; j ++) {
            int ind1 = (i + 1) * w + (j + 1);
            int ind2 = (i + 1) * w + (j + 2);
            if (c[i][j] == '.' && c[i][j + 1] == '.') {
                tree[ind1].push_back(ind2);
                tree[ind2].push_back(ind1);
            }
        }
    }
    for (int i = 0; i < h-1; i++) {
        for (int j = 0; j < w; j ++) {
            int ind1 = (i + 1) * w + (j + 1);
            int ind2 = (i + 2) * w + (j + 1);
            if (c[i][j] == '.' && c[i + 1][j] == '.') {
                tree[ind1].push_back(ind2);
                tree[ind2].push_back(ind1);
            }
        }
    }

    vector<int> seen((h + 1) * (w + 1), -1);
    queue<int> q;
    q.push(start); seen[start] = 0;
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        for (auto next : tree[pos]) {
            if (seen[next] == -1) {
                q.push(next);
                seen[next] = seen[pos] + 1;
            }
        }
    }

    cout << seen[goal] << endl;

    return 0;
}