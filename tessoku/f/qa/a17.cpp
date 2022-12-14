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
    vector<int> a(n); for (int i = 1; i < n; i++) cin >> a[i];
    vector<int> b(n); for (int i = 2; i < n; i++) cin >> b[i];

    vector<int> dp(n); dp[0] = 0; dp[1] = a[1];
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1] + a[i], dp[i-2] + b[i]);
    }

    vector<int> ans; ans.push_back(n);
    int place = n-1;
    while(true) {
        if (place == 0) break;
        if (dp[place-1] + a[place] == dp[place]) {
            ans.push_back(place);
            place = place-1;
        }
        else if (dp[place-2] + b[place] == dp[place]) {
            ans.push_back(place-1);
            place = place-2;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;

    return 0;
}