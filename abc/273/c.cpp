#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    cin >> n;
    vector<long long>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<long long> seta(a.begin(), a.end());
    int len = seta.size();
    vector<long long> mirrora(seta.begin(), seta.end());
    sort(mirrora.begin(), mirrora.end());
    
    map<long long, long long> mp;
    for (int i = 0; i < len; i++) {
        mp[mirrora[i]] = i;
    }

    map<long long, long long> counter;
    for (int i = 0; i < n; i++) {
        counter[len - (mp[a[i]] + 1)] += 1;
    }

    for (int k = 0; k < n; k++) {
        cout << counter[k] << endl;
    }

    return 0;
}