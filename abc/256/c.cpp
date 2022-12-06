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

class UnionFind {
   public:
   int par[100009];
   int siz[100009];

   void init(int N) {
       for (int i = 1; i <= N; i++) par[i] = -1;
       for (int i = 1; i <= N; i++) siz[i] = 1;
   }

   int root(int x) {
       while (true) {
           if (par[x] == -1) break;
           x = par[x];
       }
       return x;
   }

   void unite(int u, int v) {
       int rootU = root(u);
       int rootV = root(v);
       if (rootU == rootV) return;
       if (siz[rootU] < siz[rootV]) {
           par[rootU] = rootV;
           siz[rootV] = siz[rootU] + siz[rootV];
       }
       else {
           par[rootV] = rootU;
           siz[rootU] = siz[rootU] + siz[rootV];
       }
   }

   bool same(int u, int v) {
       if (root(u) == root(v)) return true;
       return false;
   }
};

int main() {

    int h1, h2, h3, w1, w2, w3; cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    long long ans = 0;
    for (int a = 1; a <= 30; a++) {
        for (int b = 1; b <= 30; b++) {
            for (int d = 1; d <= 30; d++) {
                for (int e = 1; e <= 30; e++) {
                    if (h1 - (a + b) < 1) continue;
                    if (h2 - (d + e) < 1) continue;
                    if (w1 - (a + d) < 1) continue;
                    if (w2 - (b + e) < 1) continue;
                    int c = h1 - (a + b);
                    int f = h2 - (d + e);
                    int g = w1 - (a + d);
                    int h = w2 - (b + e);
                    int i1 = w3 - (c + f);
                    int i2 = h3 - (g + h);
                    // cout << endl;
                    // cout << "c : " << c << endl;
                    // cout << "f : " << f << endl;
                    // cout << "g : " << g << endl;
                    // cout << "h : " << h << endl;
                    // cout << "i1 : " << i1 << endl;
                    // cout << "i2 : " << i2 << endl;
                    // cout << endl;
                    if (a + b + c != h1) continue;
                    if (d + e + f != h2) continue;
                    if (a + d + g != w1) continue;
                    if (b + e + h != w2) continue;
                    
                    if (i1 != i2) {
                        if (g + h + i1 == h3 && c + f + i1 == w3) ans++;
                        if (g + h + i2 == h3 && c + f + i2 == w3) ans++;
                    }
                    else {
                        if (g + h + i1 == h3 && c + f + i1 == w3) ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}