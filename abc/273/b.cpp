#include <bits/stdc++.h>
using namespace std;

int main() {

    long long x;
    long long k;

    cin >> x >> k;
    long long mirror = x;
    for (int i = 0; i < k; i++) {
        long long quo = mirror / 10;
        long long rem = mirror % 10;

        if (rem < 5) {
            mirror = quo;
            x = quo * pow(10, i + 1);
        } else {
            mirror = quo + 1;
            x = (quo + 1) * pow(10, i + 1);
        }
    }

    cout << x << endl;

    return 0;
}