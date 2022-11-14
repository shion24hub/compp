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

    int n; cin >> n;
    vector<long long> a(n); rep(i, n) cin >> a[i];

    vector<long long> ind = a;
    sort(ind.begin(), ind.end());
    ind.erase(unique(ind.begin(), ind.end()), ind.end());

    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(ind.begin(), ind.end(), a[i]);
        long long ans = pos - ind.begin();
        cout << ans + 1 << " ";
    }
    cout << endl;
    
    return 0;
}