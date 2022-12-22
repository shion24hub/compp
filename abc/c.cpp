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

long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    for (a %= mod; b; a = a * a % mod, b >>= 1)
    if (b & 1) res = res * a % mod;
    return res;
}

long long n, x; 
long long ans;
vector<vector<long long>> a;
void dfs(long long i, long long s) {
    if (i == n) {
        if (s == x) {ans ++;}
        return;
    }

    for (int j = 0; j < a[i].size(); j++) {
        if (s > x/a[i][j]) {continue;}
        dfs(i+1, s*a[i][j]);
    }
}

int main() {

    cin >> n >> x;
    vector<long long> l(n);
    a = vector<vector<long long>> (n);
    long long ia;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        for (int j = 0; j < l[i]; j++) {
            cin >> ia;
            a[i].push_back(ia);
        }
    }

    dfs(0, 1);
    cout << ans << endl;

    return 0;
}