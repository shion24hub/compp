#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n; cin >> n;
    vector<long long> a(n+1), b(n);
    rep(i, n+1) cin >> a[i];
    rep(i, n) cin >> b[i];

    long long rem = 0, counter = 0;
    for (int i = 0; i < n; i++){
        if (a[i] <= rem) {
            counter += a[i];
            rem = b[i];
        } else {
            counter += rem;
            int nnm = a[i] - rem;
            if (nnm <= b[i]) {
                counter += nnm;
                rem = b[i] - nnm;
            } else {
                counter += b[i];
                rem = 0;
            }
        }
    }
    if (a[n] <= rem) counter += a[n];
    else counter += rem;
    cout << counter << endl;
    return 0;
}