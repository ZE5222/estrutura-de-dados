#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    
    int qtd_v    = argc - 1, soma_v   = 0, menor_v  = atoi(argv[1]), maior_v  = atoi(argv[1]), vetor_ord_v[qtd_v];;
    float med_v  = 0;
    

    for(int i = 1; i <= qtd_v; i++){
        int v = atoi(argv[i]);
        vetor_ord_v[i-1] = v;
        soma_v += v;

        if(menor_v > v){
            menor_v = v;
        }

        if(v > maior_v){
            maior_v = v;
        }

        }

    med_v = (float) soma_v / qtd_v;

    printf("Quantidade de valores recebidos: %d\n", qtd_v);
    printf("medio dos valores: %.2f\n", med_v);
    printf("Menor valor: %d\n", menor_v);
    printf("Maior valor: %d\n", maior_v);

    for(int i = 0; i < qtd_v-1; i++){
        for(int j = i; j < qtd_v; j++){
            if(vetor_ord_v[i] > vetor_ord_v[j]){
                int aux = vetor_ord_n[j];
                vetor_ord_v[j] = vetor_ord_v[i];
                vetor_ord_v[i] = aux;
        }
        }
        }
    

    for(int i = 0; i < qtd_v; i++){
        printf("%d ", vetor_ord_v[i]);
        }


    exit(0);
}