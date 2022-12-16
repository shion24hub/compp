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

    int n, q; cin >> n >> q;
	map<int, int> ball_pos, pos_ball;
	for (int i = 1; i <= n; i++) {
		ball_pos[i] = i;
		pos_ball[i] = i;
	}
	int x;
	for (int i = 0; i < q; i++) {
		cin >> x;
		if (ball_pos[x] != n) {
			//ボールが右端になかった場合
			int xpos = ball_pos[x];
			int rpos = xpos + 1;
			int right_ball = pos_ball[rpos];
			
			ball_pos[x] = rpos;
			ball_pos[right_ball] = xpos;
			pos_ball[rpos] = x;
			pos_ball[xpos] = right_ball;
		}
		else {
			//ボールが右端にあった場合
			int xpos = ball_pos[x];
			int lpos = xpos - 1;
			int left_ball = pos_ball[lpos];

			ball_pos[x] = lpos;
			ball_pos[left_ball] = xpos;
			pos_ball[lpos] = x;
			pos_ball[xpos] = left_ball;
		}
	}

	for (int i = 1; i <= n; i++) cout << pos_ball[i] << " ";
	cout << endl;

    return 0;
}