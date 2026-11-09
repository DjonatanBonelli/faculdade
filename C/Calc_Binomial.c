#include <stdio.h>
#include <math.h>

//formula da combinacao
float formula_combinacao(n, x){

float resultado_combinacao = fatorial(n) / (fatorial(x)*fatorial((n-x)));
return resultado_combinacao;
};

//formula fatorial
int fatorial(n){
    int fat;
    for(fat = 1; n > 1; n--)
  {      
      fat = fat * n;
  }
    return fat;
};

//formula binomial
int formula_binomial(){    
int n, x, b, z;
float p, q;

printf("\nDigite o numero de casos possiveis (n): ");
scanf("%d", &n);
printf("Digite o numero de casos favoraveis (x): ");
scanf("%d", &x);
printf("Digite a probabilidade (%%): ");
scanf("%f", &p);
b = x;
z = n;
p = p / 100;
float resultado_binomial = (formula_combinacao(n, x)*pow(p, x)*pow((1-p), (n-x))) * 100;
float binomial_menor = 0;
for(x; x >= 0; x--){
    binomial_menor = (binomial_menor + formula_combinacao(n, x)*pow(p, x)*pow((1-p), (n-x)));
}
    binomial_menor = binomial_menor * 100;
    float binomial_maior = 100 - binomial_menor;

printf("\nProbabilidade para casos iguais a %d em %d: %.2f%%\nProbabilidade para casos iguais ou menores que %d em %d: %.2f%%\nProbabilidade para casos iguais ou maiores que %d em %d: %.2f%%\n", b, z, resultado_binomial, b, z, binomial_menor, b, z, binomial_maior);
main();
return 0;
};

//inicio
int main(){
    printf("\nCalculadora Binomial\n\n-----------------------------------------\n");
formula_binomial();
return 0;
};