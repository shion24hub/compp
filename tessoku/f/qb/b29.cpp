#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

vector<char> UPPERCASE = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> LOWERCASE = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

//print 2d vector<int>
void p2dveci(vector<vector<int>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
}

//print 2d vector<long long>
void p2dvecll(vector<vector<long long>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
}

//print 2d vector<char>
void p2dvecc(vector<vector<char>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
    }
}

//print 2d vector<string>
void p2dvecs(vector<vector<string>> vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << ' ';
        }
        cout << endl;
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

long long power (long long a, long long b, long long mod) {
    long long p = a, ans = 1;
    for (int i = 0; i < 60; i++){
        long long div = (1LL << i);
        if ((b / div) % 2 == 1) {
            ans = (ans * p) % mod;
        }
        p = (p * p) % mod;
    }

    return ans;
}

int main() {

    long long a, b; cin >> a >> b;
    long long mod = 1000000007;
    
    cout << power(a, b, mod) << endl;

    return 0;
}