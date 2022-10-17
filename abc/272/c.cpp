#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //0, 奇数のときは-1
    bool bzero = false;
    bool bodd = false;
    if ((n == 2)) {
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) bzero = true;
            else if (a[i] % 2 != 0) bodd = true;
        }
    }
    if (bzero && bodd) {
        cout << -1 << endl;
        return 0;
    }

    //偶数、奇数だけのときは-1
    bodd = false;
    bool beven = false;
    if (n == 2) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0) bodd = true;
            else beven = true;
        }
    }
    if (bodd && beven) {
        cout << -1 << endl;
        return 0;
    }

    long long maxodd = 0, nmaxodd = 0, maxeven = 0, nmaxeven = 0;
    int maxoddind = 0, maxevenind = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 != 0) && (a[i] > maxodd)) {
            maxodd = a[i];
            maxoddind = i;
        } else if ((a[i] % 2 == 0) && (a[i] > maxeven)) {
            maxeven = a[i];
            maxevenind = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((a[i] % 2 != 0) && (a[i] > nmaxodd) && (i != maxoddind)) {
            nmaxodd = a[i];
        } else if ((a[i] % 2 == 0) && (a[i] > nmaxeven) && (i != maxevenind)) {
            nmaxeven = a[i];
        }
    }

    // cout << maxodd << " " << nmaxodd << endl;
    // cout << maxeven << " " << nmaxeven << endl;

    int odd = maxodd + nmaxodd;
    int even = maxeven + nmaxeven;

    if (odd > even) cout << odd << endl;
    else cout << even << endl;

    return 0;
}