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

int janken(char hand1, char hand2) {
    if (hand1 == 'G') {
        if (hand2 == 'G') return 0;
        if (hand2 == 'C') return 1;
        if (hand2 == 'P') return -1;
    }
    else if (hand1 == 'C') {
        if (hand2 == 'G') return -1;
        if (hand2 == 'C') return 0;
        if (hand2 == 'P') return 1;     
    }
    else if (hand1 == 'P') {
        if (hand2 == 'G') return 1;
        if (hand2 == 'C') return -1;
        if (hand2 == 'P') return -0;
    }

    return 3; //avoid warning
}

int main() {

    int n, m; cin >> n >> m;
    vector<vector<char>> a((2 * n) + 1, vector<char>(m + 1));
    for (int i = 1; i <= 2 * n; i++) for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
    }

    vector<pair<int, int>> ranking;
    for (int i = 1; i <= 2 * n; i++) {
        ranking.push_back(make_pair(0, i)); //点数, 人
    }

    // for (auto p : ranking) {
    //     cout << p.first << " " << p.second << endl;
    // }
    // cout << ranking.size() << endl;
 
    for (int round = 1; round <= m; round++) {
        // cout << "ROUND : " << round << endl;
        for (int i = 0; i <= n; i+=2) {
            // cout << ranking[i].second << " vs " << ranking[i+1].second << endl;
            
            char hand1 = a[ranking[i].second][round];
            char hand2 = a[ranking[i+1].second][round];

            int w = janken(hand1, hand2);
            if (w == 1) ranking[i].first += -1;//勝ったらマイナス1
            if (w == -1) ranking[i+1].first += -1;
        }
        sort(ranking.begin(), ranking.end());
    }

    for (int i = 0; i < (2 * n); i++) {
        cout << ranking[i].second << endl;
    }

    return 0;
}