#include <bits/stdc++.h>
using namespace std;

int main() {
    int g, w, h;
    cin >> g >> w >> h;

    if (g < 0 && w > 0) {
        cout << abs(g) << endl;
    } 
    else if (g > 0 && w < 0) {
        cout << abs(g) << endl;
    }
    else if (g > 0 && w > 0 && w - g > 0) {
        cout << abs(g) << endl;
    } 
    else if (g < 0 && w < 0 && g - w > 0) {
        cout << abs(g) << endl;
    } 
    else if (g > 0 && w > 0 && w - h > 0) {
        if (h > 0) {
            cout << abs(g) << endl;
        } else {
            cout << (2 * abs(h)) + abs(g) << endl;
        }
    }
    else if (g < 0 && w < 0 && h - w > 0) {
        if (h < 0) {
            cout << abs(g) << endl;
        } else {
            cout << (2 * abs(h)) + abs(g) << endl;
        }
    } 
    else {
        cout << -1 << endl;
    }

    return 0;
}