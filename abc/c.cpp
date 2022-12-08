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

    long long n, a, b; cin >> n >> a >> b;
    long long p, q, r, s; cin >> p >> q >> r >> s;
    
    long long k_under1 = max(1-a, 1-b);
    long long k_upper1 = min(n-a, n-b);
    long long k_under2 = max(1-a, b-n);
    long long k_upper2 = min(n-a, b-1);

    //-----------------------------------------------//
    // 1回目の操作。

    long long ki_underlimit1 = p-a;
    long long ki_upperlimit1 = q-a;
    long long kj_underlimit1 = r-b;
    long long kj_upperlimit1 = s-b;

    long long kiintersect_under1 = max(k_under1, ki_underlimit1);
    long long kiintersect_upper1 = min(k_upper1, ki_upperlimit1);
    long long kjintersect_under1 = max(k_under1, kj_underlimit1);
    long long kjintersect_upper1 = min(k_upper1, kj_upperlimit1);

    vector<long long> coloredi1, coloredj1;
    for (int i = kiintersect_under1; i <= kiintersect_upper1; i++) coloredi1.push_back(a+i);
    for (int i = kjintersect_under1; i <= kjintersect_upper1; i++) coloredj1.push_back(b+i);

    print(coloredi1);
    print(coloredj1);

    //-----------------------------------------------//
    //2回目の操作

    long long ki_underlimit2 = p-a;
    long long ki_upperlimit2 = q-a;
    long long kj_underlimit2 = b-s;
    long long kj_upperlimit2 = b-r;

    long long kiintersect_under2 = max(k_under2, ki_underlimit2);
    long long kiintersect_upper2 = min(k_upper2, ki_upperlimit2);
    long long kjintersect_under2 = max(k_under2, kj_underlimit2);
    long long kjintersect_upper2 = min(k_upper2, kj_upperlimit2);

    vector<long long> coloredi2, coloredj2;
    for (int i = kiintersect_under2; i <= kiintersect_upper2; i++) coloredi2.push_back(a+i);
    for (int i = kjintersect_under2; i <= kjintersect_upper2; i++) coloredj2.push_back(b-i);

    print(coloredi2);
    print(coloredj2);



    return 0;
}