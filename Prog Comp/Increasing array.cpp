#include <bits/stdc++.h>
using namespace std;

int main() {

    long long a, b, x = 0;

    cin >> a;

    long long v[a];

    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }

    for (int i = 1; i < a; i++) {

        if (v[i] < v[i - 1]) {

            x += (v[i - 1] - v[i]);
            v[i] = v[i - 1];
        
        }

    }

    cout << x;
}