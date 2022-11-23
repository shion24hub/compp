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

//binary search (int)
int binsi(int left, int right, int key, vector<int> vec) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key == vec[mid]) return mid;
        else if (key < vec[mid]) right = mid - 1;
        else if (vec[mid] < key) left = mid + 1; 
    }
    return -1;
}

//binary search (long long)
int binsll(int left, int right, long long key, vector<long long> vec) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (key == vec[mid]) return mid;
        else if (key < vec[mid]) right = mid - 1;
        else if (vec[mid] < key) left = mid + 1; 
    }
    return -1;
}

long long getup(set<long long> s, long long x) {
	auto itr = s.lower_bound(x);
	if (itr == s.end()) return 10000000000000LL;
	else return (*itr);
}

long long getdown(set<long long> s, long long x) {
	auto itr = s.lower_bound(-x);
	if (itr == s.end()) return 10000000000000LL;
	else return -(*itr);
}

int main() {

    int q; cin >> q;
    long long t, x;
	set<long long> s1, s2;
	for (int i = 0; i < q; i++) {
		cin >> t >> x;
		if (t == 1) {
			s1.insert(x);
			s2.insert(-x);
		}
		else {
			if (s1.empty()) {cout << -1 << endl; continue;}
			long long v1 = getup(s1, x);
			long long v2 = getdown(s2, x);
			long long ans = min(x - v2, v1 - x);
			cout << ans << endl;
		}
	}

    return 0;
}