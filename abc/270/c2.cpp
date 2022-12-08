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

    int n, x, y; cin >> n >> x >> y;
    map<int, vector<int>> tree;
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> seen(n+1, -2); seen[x] = -1;
    stack<int> st; st.push(x);
    while (!st.empty()) {
        int pos = st.top();
        st.pop();
        for (auto next : tree[pos]) {
            if (seen[next] == -2) {
                seen[next] = pos;
                st.push(next);
            }
        }
    }
    
    vector<int> ans;
    int pos = y;
    while (seen[pos] != -1) {
        ans.push_back(pos);
        pos = seen[pos];
    }
    ans.push_back(x);
    reverse(ans.begin(), ans.end());

    print(ans);

    return 0;
}