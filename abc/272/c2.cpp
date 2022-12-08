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
    vector<long long> a(n); rep(i, n) cin >> a[i];

    vector<long long> evens, odds; 
    for (int i = 0; i < n; i++) {
        if (a[i]%2 == 0) evens.push_back(a[i]);
        else odds.push_back(a[i]);
    }

    if (n == 2 && evens.size() == 1 && odds.size() == 1) {
        cout << -1 << endl;
        return 0;
    }

    sort(evens.begin(), evens.end());
    reverse(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());
    reverse(odds.begin(), odds.end());

    if (odds.size() <= 1) {
        cout << evens[0] + evens[1] << endl;
        return 0;
    }
    else if (evens.size() <= 1) {
        cout << odds[0] + odds[1] << endl;
        return 0;
    }

    if (evens[0] + evens[1] > odds[0] + odds[1]) cout << evens[0] + evens[1] << endl;
    else cout << odds[0] + odds[1] << endl;

    return 0;
}