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

    int n; cin >> n;
    vector<string> s(n); rep(i, n) cin >> s[i];

    bool ans = false;
    vector<int> vi = {-1, 0, 1}, vj = {-1, 0, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            for (int k = 0; k < vi.size(); k++) {
                for (int l = 0; l < vj.size(); l++) {
                    if (k == 1 && l == 1) continue; // (0, 0)のとき
                    int di = vi[k], dj = vj[l];
                    if (i < 5 && di == -1 && dj == 0) continue; //縦上
                    if (n - i < 5 && di == 1 && dj == 0) continue; //縦下 
                    if (j < 5 && di == 0 && dj == -1) continue; // 横左
                    if(n - j < 5 && di == 0 && dj == 1) continue; //横右
                    if ((i < 5 && di == -1) || (j < 5 && dj == -1)) continue; //左斜め上
                    if ((n - i < 5 && di == 1) || (j < 5 && dj == -1)) continue; //左斜め下
                    if ((i < 5 && di == -1) || (n - j < 5 && dj == 1)) continue; //右斜め上
                    if ((n - i < 5 && di == 1) || (n - i < 5 && dj == 1)) continue; //右斜め下

                    cout << "debug" << endl;

                    int cnt;
                    if (s[i][j] == '#') cnt = 1;
                    else cnt = 0;
                    int pi = i, pj = j;
                    cout << "i : " << i << " j : " << j << endl;
                    for (int m = 0; m < 5; m++) {
                        pi += di;
                        pj += dj;
                        cout << di << " " << dj << endl;
                        cout << pi << " " << pj << endl;
                        if (s[pi][pj] == '#') cnt ++;
                    }
                    cout << "debug" << endl;
                    if (cnt >= 4) {ans = true;}
                }
            }
        }
    }

    if (ans) {cout << "Yes" << endl;}
    else {cout << "No" << endl;}

    return 0;
}