#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char valor;
    struct No *prox;
} No;

int lista_verificar_existencia(No *L, char valor_busca) {
    for (No *atual = L->prox; atual != NULL; atual = atual->prox)
        if (atual->valor == valor_busca)
            return 1;
    return 0;
}

int lista_verificar_ocorrencias(No *L, char valor_busca) {
    int ocorrencias = 0;
    for (No *atual = L->prox; atual != NULL; atual = atual->prox)
        if (atual->valor == valor_busca)
            ocorrencias++;
    return ocorrencias;
}

void lista_imprimir_inversa(No *L) {
    No *anterior = NULL;
    for (No *atual = L->prox, *proximo; atual != NULL; atual = proximo) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
    }
    for (No *atual = anterior; atual != NULL; atual = atual->prox)
        printf("%c ", atual->valor);
    printf("\n");
}

void lista_inserir_no_i(No *L, int i, char valor) {
    No *novo_no = malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    novo_no->valor = valor;
    No *anterior = L;
    for (int indice_atual = 0; indice_atual < i && anterior->prox != NULL; indice_atual++)
        anterior = anterior->prox;
    novo_no->prox = anterior->prox;
    anterior->prox = novo_no;
}

void lista_remover_no_i(No *L, int i) {
    No *anterior = L;
    for (int indice_atual = 0; indice_atual < i && anterior->prox != NULL; indice_atual++)
        anterior = anterior->prox;
    if (anterior->prox == NULL) {
        printf("Posição inválida.\n");
        return;
    }
    No *temp = anterior->prox;
    anterior->prox = temp->prox;
    free(temp);
}

void lista_remover_no(No *L, char valor_busca) {
    No *anterior = L;
    for (No *atual = L->prox, *proximo; atual != NULL; atual = proximo) {
        proximo = atual->prox;
        if (atual->valor == valor_busca) {
            anterior->prox = proximo;
            free(atual);
        } else {
            anterior = atual;
        }
    }
}

void lista_libera_memoria(No *L) {
    for (No *atual = L->prox, *proximo; atual != NULL; atual = proximo) {
        proximo = atual->prox;
        free(atual);
    }
    free(L);
}

void lista_imprimir(No *L) {
    for (No *atual = L->prox; atual != NULL; atual = atual->prox)
        printf("%c ", atual->valor);
    printf("\n");
}

int main() {
    No *cabeca = malloc(sizeof(No));
    if (cabeca == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }
    cabeca->prox = NULL;

    lista_inserir_no_i(cabeca, 0, 'A');
    lista_inserir_no_i(cabeca, 1, 'B');
    lista_inserir_no_i(cabeca, 2, 'C');
    lista_inserir_no_i(cabeca, 3, 'D');
    lista_inserir_no_i(cabeca, 4, 'B');

    printf("Lista: ");
    lista_imprimir(cabeca);

    printf("Existe 'C' na lista? %s\n", lista_verificar_existencia(cabeca, 'C') ? "Sim" : "Não");
    printf("Quantidade de ocorrências de 'B': %d\n", lista_verificar_ocorrencias(cabeca, 'B'));

    printf("Lista na ordem inversa: ");
    lista_imprimir_inversa(cabeca);

    lista_remover_no_i(cabeca, 2);
    printf("Lista após remover o nó na posição 2: ");
    lista_imprimir(cabeca);

    lista_remover_no(cabeca, 'B');
    printf("Lista após remover os nós com valor 'B': ");
    lista_imprimir(cabeca);

    lista_libera_memoria(cabeca);

    return 0;
}