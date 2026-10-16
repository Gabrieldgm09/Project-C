#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NFACES 6
#define NSOMAS (NFACES + NFACES + 1) // Soma máxima (6+6=12) + 1 para índice
#define NROLLS 36000 

// 1. Matrizes em C exigem a dimensão das colunas no parâmetro da função
void zeraMatriz(int M[NFACES][NFACES]) {
    for (int i = 0; i < NFACES; i++) {
        for (int j = 0; j < NFACES; j++) {
            M[i][j] = 0;
        }
    }
}

void imprimeMatriz(int M[NFACES][NFACES]) {
    for (int i = 0; i < NFACES; i++) {
        for (int j = 0; j < NFACES; j++) {
            printf("%6d", M[i][j]);
        }
        printf("\n");
    }
}

// 2. Um dado de 6 faces deve retornar valores entre 0 e 5 (índices da matriz) ou 1 e 6
int rolaDado() {
    return rand() % NFACES; // Gera de 0 a 5 para usar diretamente na matriz
}

void zeraVetor(int v[], int n) { 
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}

void imprimeVetor(int v[], int n) { 
    // Imprime as somas possíveis (de 2 a 12 no caso de NFACES = 6)
    for (int i = 2; i < n; i++) {
        printf("%6d", v[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int M[NFACES][NFACES];
    int somas[NSOMAS];
    
    zeraMatriz(M);
    zeraVetor(somas, NSOMAS);

    for (int i = 0; i < NROLLS; i++) {
        int d1 = rolaDado(); // Índice de 0 a 5
        int d2 = rolaDado(); // Índice de 0 a 5
        
        M[d1][d2]++;
        
        // As faces reais são (d1+1) e (d2+1), logo a soma varia de 2 a 12
        int soma = (d1 + 1) + (d2 + 1);
        somas[soma]++;
    }    

    printf("Matriz de Ocorrencias (Linhas x Colunas = Dado 1 x Dado 2):\n");
    imprimeMatriz(M);
    
    printf("\nVetor de Somas (de 2 a %d):\n", 2 * NFACES);
    imprimeVetor(somas, NSOMAS);

    // Identificar a soma mais frequente (índices válidos: 2 a 12)
    int maior_soma_i = 2;
    for (int i = 3; i < NSOMAS; i++) {
        if (somas[i] > somas[maior_soma_i]) {
            maior_soma_i = i;
        }
    }

    printf("\nFrequencia de cada soma:\n");
    for (int i = 2; i < NSOMAS; i++) {
        printf("Soma %2d: %d vezes\n", i, somas[i]);
    }

    // Identificar o par/arranjo (linha, coluna) mais frequente na matriz
    int maior_i = 0;
    int maior_j = 0;
    for (int i = 0; i < NFACES; i++) {
        for (int j = 0; j < NFACES; j++) {
            if (M[i][j] > M[maior_i][maior_j]) {
                maior_i = i;
                maior_j = j;
            }                
        }
    }
    
    printf("\nSoma mais frequente: %d (%d vezes)\n", maior_soma_i, somas[maior_soma_i]);
    printf("Arranjo mais frequente (Face %d, Face %d): %d vezes\n", maior_i + 1, maior_j + 1, M[maior_i][maior_j]);
    
    return 0;
}