#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    vector<int> list(5);
    rep(i, 5) cin >> list[i];

    map<int, int> counter;
    for (int num : list) counter[num] += 1;
    
    bool two = false;
    bool three = false;
    for (auto p : counter) {
        if (p.second == 2) two = true;
        if (p.second == 3) three = true;
    }

    if (two && three) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}