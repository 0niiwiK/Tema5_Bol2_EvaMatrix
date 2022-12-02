// Creado por: Israel Sanchez Fuentes, 1o DAM Tarde

#include <stdio.h>
// Importaremos la libreria "stdlib.h" y "time.h" para generar numeros aleatorios
#include <stdlib.h>
#include <time.h>
// Definimos el tamaño de la matriz con constantes
#define TAM1 6
#define TAM2 4

// PROTOTIPOS
void rellenar_matriz(int m[TAM1][TAM2]); // Rellenará la matriz automaticamente siguiendo los requisitos
void imprime_matriz(int m[TAM1][TAM2]); // Imprime la matriz
void ordena_matriz_fila(int m[TAM1][TAM2]); // Ordena la matriz por filas
void ordena_matriz_col(int m[TAM1][TAM2]); // Ordena la matriz por columnas

int main() {
    int mat[TAM1][TAM2]; // Creamos la matriz
    rellenar_matriz(mat); // La rellenamos de numeros aleatorios
    printf("---| MATRIZ DESORDENADA |---");
    imprime_matriz(mat); // Imprimimos la matriz desordenada
    printf("\n\n---| MATRIZ ORDENADA FILA |---");
    ordena_matriz_fila(mat); // Ordenamos la matriz por filas
    imprime_matriz(mat); // Imprimimos la matriz ordenada por filas
    printf("\n\n---| MATRIZ ORDENADA COLUMNA |---");
    ordena_matriz_col(mat); // Ordenamos por columnas la matriz ordenada por filas
    imprime_matriz(mat); // Imprimimos la matriz ordenada por filas y columnas

    /* Al ir trabajando sobre la misma matriz, al pasar la ordenacion por columnas después de por filas
     * Obtendremos la matriz ordenada por filas y columnas, estando los mayores valores en las últimas filas y columnas
     * Y los menores valores en las primeras filas y columnas */

    return 0;
}

void rellenar_matriz(int m[TAM1][TAM2]){
    // Esta funcion rellena una matriz con numeros aleatorios entre 10 y 90
    // Entrada: matriz a rellenar

    srand(time(NULL)); // Generador de semilla de aleatoriedad
    for (int i = 0; i < TAM1; ++i) {
        for (int j = 0; j < TAM2; ++j) {
            m[i][j]=(rand()%81)+10; // Generamos los numeros aleatorios entre 10 y 90
            // (primero van de 0 a 80 (módulo 81) y luego sumamos 10)
        }
    }
}

void imprime_matriz(int m[TAM1][TAM2]){
    // Esta funcion imprime una matriz
    // Entrada: matriz a imprimir

    printf("\n");
    for (int i = 0; i < TAM1; ++i) { // Imprimimos las filas
        printf("   |");
        for (int j = 0; j < TAM2; ++j) { // Imprimimos las columnas
            printf(" %2d |",m[i][j]);
        }
        printf("\n");
    }
}

void ordena_matriz_fila(int m[TAM1][TAM2]){
    // Esta funcion ordena una matriz por filas
    // Entrada: matriz a ordenar por filas

    // Voy a usar el algoritmo de ordenacion por insercion extendido a matrices (añadiendo la componente de las columnas)
    int i,j,x;
    for (int k = 0; k < TAM1; ++k) { // Por cada fila
        for(i=1; i<=TAM2-1; i++){ // Ordena sus columnas
            // Obtendremos cada fila con sus columnas ordenadas, es decir, la matriz estara ordenada por filas
            x=m[k][i];
            j=i-1;
            while(j>=0 && x<m[k][j]) {
                m[k][j+1]=m[k][j];
                j--;
            }
            m[k][j+1]=x;
        }
    }
}

void ordena_matriz_col(int m[TAM1][TAM2]){
    // Esta funcion ordena una matriz por filas
    // Entrada: matriz a ordenar por filas

    // Voy a usar el mismo algoritmo que para ordenar las filas, pero intercambiando filas por columnas
    int i,j,x;
    for (int k = 0; k < TAM2; ++k) { // Por cada columna
        for(i=1; i<=TAM1-1; i++){ // Ordena sus filas
            x=m[i][k];
            j=i-1;
            while(j>=0 && x<m[j][k]) {
                m[j+1][k]=m[j][k];
                j--;
            }
            m[j+1][k]=x;
        }
    }
}