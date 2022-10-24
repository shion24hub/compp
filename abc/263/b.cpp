#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) cin >> p[i];

    map<int, int> mp;
    for (int i = 2; i <= n; i++) mp[i] = p[i];

    int person = n;
    int counter = 1;
    for (int i = 1; i <= n; i++) {
        person = mp[person];
        if (person != 1) counter ++;
        else break;
    }
    
    cout << counter << endl;

    return 0;
}