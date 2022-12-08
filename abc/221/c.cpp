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

long long f(vector<long long>vec) {
    int ret = 0;
    for (int i = 0; i < vec.size()-1; i++) {
        long long left = 0;
        long long left_mul = 1;
        for (int j = 0; j < i+1; j++) {
            left += left_mul * vec[j];
            left_mul *= 10;
        }
        long long right = 0;
        long long right_mul = 1;
        for (int k = i+1; k < vec.size(); k++) {
            right += right_mul * vec[k];
            right_mul *= 10;
        }
        long long ans = left * right;
        if (ret < ans) ret = ans;
    }

    return ret;
}

int main() {

    long long n; cin >> n;

    vector<long long> digits;
    while (n >= 1) {
        digits.push_back(n%10);
        n /= 10;
    }

    vector<long long> anss;
    sort(digits.begin(), digits.end());
    do {
        anss.push_back(f(digits));
    } while (next_permutation(digits.begin(), digits.end()));

    cout << *max_element(anss.begin(), anss.end()) << endl;

    return 0;
}