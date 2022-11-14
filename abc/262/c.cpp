#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)

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

int main() {

    //input
    int n; cin >> n;
    vector<int> a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];

    //count same
    long long same = 0;
    for (int i = 1; i <= n; i++) {
        if (i == a[i]) same ++;
    }

    //count a[a[i]] == iである場合
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[a[i]] == i) ans ++;
    }

    ans -= same;
    ans /= 2;

    //コンビネーションの計算
    ans += (same * (same - 1)) / 2;

    //output
    cout << ans << endl;

    return 0;
}