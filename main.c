#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"


int main(int argc, char *argv[]){

    No* n1 = no('A', NULL);
    No* n2 = no('B', NULL);
    No* n3 = no('C', NULL);
    No* n4 = no('J', NULL);
    No* n5 = no('Y', NULL);

    No* Hc = copiar_lista(H);

   imprimir_lista(H);
   printf("copia");
   imprimir_lista(Hc);

   H->proximo_no->valor = 'X';
   Hc->valor = 'y';

    printf("\n");
    imprimir_lista(H);
    printf("copia");
    imprimir_lista(Hc);

    printf("\n qtd = %d", qtd_nos(H));
    printf("\n copia qtd = %d", qtd_nos(Hc));
    exit(0);
}