#include <iostream>
#include <vector>

using namespace std;

#define ll long long

unsigned ll fat(unsigned ll n) {
    return (n == 0) ? 1 : n * fat(n - 1);
}

int calculateRepresentation(ll n, vector<ll>& fats) {
    int terms = 0;
    while (n > 0) {
        int index = 0;
        while (fats[index] <= n) ++index; // Encontra o maior fatorial que é menor ou igual a n
        n -= fats[index - 1]; // Subtrai o fatorial encontrado de n
        ++terms; // Incrementa o número de termos na representação
    }
    return terms;
}

int main() {
    ll n;
    cin >> n;

    // Cálculo da representação de n como uma soma de fatoriais
    vector<ll> fats = {1, 2, 6, 24, 120, 720, 5040, 40320};
    int terms = calculateRepresentation(n, fats);

    // Imprime a quantidade de termos na representação
    cout << terms << endl;

    return 0;
}
