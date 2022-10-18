#include <bits/stdc++.h>
using namespace std;

vector<bool> f(string s) {

    vector<bool> ret;
    
    if (s[6] == '0') ret.push_back(true);
    else ret.push_back(false);

    if (s[3] == '0') ret.push_back(true);
    else ret.push_back(false);

    if (s[1] == '0' && s[7] == '0') ret.push_back(true);
    else ret.push_back(false);

    if (s[0] == '0' && s[4] == '0') ret.push_back(true);
    else ret.push_back(false);

    if (s[2] == '0' && s[8] == '0') ret.push_back(true);
    else ret.push_back(false);

    if (s[5] == '0') ret.push_back(true);
    else ret.push_back(false);

    if (s[9] == '0') ret.push_back(true);
    else ret.push_back(false);

    return ret;
}

int main() {

    string s; cin >> s;

    if (s[0] == '1') {
        cout << "No" << endl;
        return 0;
    }

    vector<bool> bl;
    bl = f(s);

    bool sw = false;
    int interval = 0;
    for (int i = 0; i < 7; i++) {
        if (sw && !bl[i] && interval > 0) {
            cout << "Yes" << endl;
            return 0;
        }
        if (!bl[i]) {
            interval = 0;
            sw = true;
            continue;
        }
        if (sw && bl[i]) interval ++;
    }

    cout << "No" << endl;

    return 0;
}