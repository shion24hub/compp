#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {

    int s, t; cin >> s >> t;
    
    int counter = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                if (i + j + k <= s && i * j * k <= t) counter ++;
            }
        }
    }

    cout << counter << endl;

    return 0;
}