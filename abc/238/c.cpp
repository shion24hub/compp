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

long long f(long long a, long long l, long long mod, long long inv) {
	long long ret = l % mod;
	ret *= (a + l) % mod; ret %= mod;
	ret *= inv % mod; ret %= mod;

	return ret;
}

long long digits (long long n) {
	long long ret = 0;
	while (n != 0) {
		n /= 10;
		ret ++;
	}

	return ret;
}

int main() {

	long long n; cin >> n;
	long long mod = 998244353;
	long long a = 1, l = 9;
	long long inv = modpow(2, mod-2, mod);
	vector<long long> sums;
	for (int i = 1; i <= 18; i++) {
		sums.push_back(f(a, l, mod, inv));
		l *= 10;
	}
	long long dig = digits(n);

	long long ans = 0;
	for (int i = 0; i < dig-1; i++) {ans += sums[i] % mod;}
	long long s = 1;
	for (int i = 0; i < dig-1; i++) {s *= 10;}
	ans += f(a, n-s+1, mod, inv);

	print(sums);
	cout << ans << endl;

	return 0;
}