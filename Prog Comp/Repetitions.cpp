#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string n;
    char i;
    int a = 1, p = 1; 
    
    cin >> n;
    
    i = n[0]; 
    
    for (size_t j = 1; j < n.size(); ++j) {
        if (i == n[j]) {
            a++; 
            if (a > p) {
                p = a; 
            }
        } else {
            a = 1; 
            i = n[j]; 
        }
    }
    
    cout << p << "\n";

    return 0;
}