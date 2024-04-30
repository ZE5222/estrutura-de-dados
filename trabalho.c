#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int x;
    float y;
} Ponto;


float calcularMediaInt(int *array, int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += array[i];
    }
    return soma / n;
}


float calcularMediaFloat(float *array, int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += array[i];
    }
    return soma / n;
}


float calcularInclinacao(Ponto *pontos, int n) {
  
    float media_x = calcularMediaInt(&(pontos->x), n);
    float media_y = calcularMediaFloat(&(pontos->y), n);

 
    float soma_produtos = 0;
    float soma_quadrados_x = 0;
    for (int i = 0; i < n; i++) {
        soma_produtos += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        soma_quadrados_x += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }

  
    return soma_produtos / soma_quadrados_x;
}


float calcularIntercepcao(float inclinacao, float media_x, float media_y) {
    return media_y - inclinacao * media_x;
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    
    int num_registros = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        num_registros++;
    }
    rewind(arquivo); 

    
    Ponto *pontos = malloc(num_registros * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    
    for (int i = 0; i < num_registros; i++) {
        if (fscanf(arquivo, "%d,%f", &(pontos[i].x), &(pontos[i].y)) != 2) {
            printf("Erro ao ler os pontos do arquivo.\n");
            return 1;
        }
    }

    
    fclose(arquivo);

    
    float inclinacao = calcularInclinacao(pontos, num_registros);

    
    float media_x = calcularMediaInt(&(pontos->x), num_registros);
    float media_y = calcularMediaFloat(&(pontos->y), num_registros);

    
    float intercepcao = calcularIntercepcao(inclinacao, media_x, media_y);

    
    printf("y = %.2fx + %.2f\n", inclinacao, intercepcao);

    
    free(pontos);

    return 0;
}