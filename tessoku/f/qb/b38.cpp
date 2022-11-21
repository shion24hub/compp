#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

int N;
string S;

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

int main() {
    cin >> N >> S;

    vector<int> ret1(N), ret2(N);
 
	// 答えを求める
	int streak1 = 1; ret1[0] = 1; // streak1 は「何個 A が連続したか」+ 1
    print(ret1);
	for (int i = 0; i < N - 1; i++) {
		if (S[i] == 'A') streak1 += 1;
		if (S[i] == 'B') streak1 = 1;
		ret1[i + 1] = streak1;
	}
    print(ret1);
	int streak2 = 1; ret2[N - 1] = 1; // streak2 は「何個 B が連続したか」+ 1
    print(ret2);
	for (int i = N - 2; i >= 0; i--) {
		if (S[i] == 'B') streak2 += 1;
		if (S[i] == 'A') streak2 = 1;
		ret2[i] = streak2;
	}
    print(ret2);
 
	// 出力
	long long Answer = 0;
	for (int i = 0; i < N; i++) Answer += max(ret1[i], ret2[i]);
	cout << Answer << endl;

    return 0;
}