#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int a, b, c, x; cin >> a >> b >> c >> x;

    int counter = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++){
                if (i * 500 + j * 100 + k * 50 == x) counter ++;
            }
        }
    }

    cout << counter << endl;

    return 0;
}