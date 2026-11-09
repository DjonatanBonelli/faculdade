#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    
    cin >> n;
    
    ll total = (1ll * n * (1ll * n + 1)) / 2;

    if (total % 2 != 0) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";

        vector<int> set1, set2;
        vector<int> visitados(n + 1, 0);

        ll soma1 = 0;
        ll max = n;

        // enche o set 1
        while (soma1 < total / 2) {
            // calcula o restante pra ser = total/2
            ll restante = total / 2 - soma1;

            // se restante > max add max no set 1
            if (restante > max) {
                set1.push_back(max);
                visitados[max] = 1;
                soma1 += max;
                max--;
            }
            else {
                // a soma vai pro set 1 se restante <= maximo
                set1.push_back(restante);
                visitados[restante] = 1;
                soma1 = total / 2;
            }
        }
        // preenche o set 2 com os restantes
        for (int i = 1; i <= n; i++) {
            if (visitados[i] == 0) {
                set2.push_back(i);
            }
        }
        // tamanho set 1
        cout << set1.size() << "\n";
        for (auto x : set1) {
            cout << x << " ";
        }
        cout << "\n";

        // tamanho set 2
        cout << set2.size() << "\n";
        for (auto x : set2) {
            cout << x << " ";
        }
    }
    return 0;
}
