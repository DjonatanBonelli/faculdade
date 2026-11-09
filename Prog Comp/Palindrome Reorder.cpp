#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int N = S.length();
    string x(N, ' ');

    // frequência de caracteres
    int f[26] = {};
    for (int i = 0; i < N; i++) {
        f[S[i] - 'A'] += 1;
    }

    // Conta frequência ímpar
    int c = 0;
    for (int i = 0; i < 26; i++) {
        if (f[i] % 2 != 0) {
            c += 1;
        }
    }

    int dir = 0, esq = N - 1;
    for (int i = 0; i < N; i++) {
        if (f[S[i] - 'A'] % 2 == 1) {
            x[N / 2] = S[i];
            f[S[i] - 'A'] -= 1;
        }
        while (f[S[i] - 'A'] > 0) {
            x[dir++] = x[esq--] = S[i];
            f[S[i] - 'A'] -= 2;
        }
    }
    // se mais de um com freq ímpar, não existe
    if (c > 1){
        cout << "NO SOLUTION";
    }else{
        cout << x << "\n";
    }
    return 0;
}

