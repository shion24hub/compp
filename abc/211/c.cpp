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

    string s; cin >> s;

    vector<char> chokudai = {'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};
    map<char, vector<int>> counter;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'c' || s[i] == 'h' || s[i] == 'o' || s[i] == 'k' || s[i] == 'u' || s[i] == 'd' || s[i] == 'a' || s[i] == 'i') counter[s[i]].push_back(i);
    }

    // for (auto p : counter) {
    //     cout << p.first << " : ";
    //     print(p.second);
    // }

    long long mod = 1000000007;
    vector<vector<long long>> cums(8, vector<long long> (100005, 0));
    for (int i = 0; i < counter['c'].size(); i++) cums[0][counter['c'][i]] = 1;
    for (int i = 1; i < cums[0].size(); i++) cums[0][i] += cums[0][i-1] % mod;
    
    for (int i = 1; i < chokudai.size(); i++) {
        char ic = chokudai[i];
        for (int j = 0; j < counter[ic].size(); j++) {
            if (counter[ic][j] - 1 >= 0) {
                cums[i][counter[ic][j]] = cums[i-1][counter[ic][j] - 1]; 
            }
        }
        for (int k = 1; k < cums[i].size(); k++) cums[i][k] += cums[i][k-1] % mod;
    }

    cout << cums[7][100000] << endl;

    return 0;
}