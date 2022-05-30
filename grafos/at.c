#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTICE = 5;
#define DIST_POSTO = 0;

typedef struct node {
    int num_vertices;
    struct node *prox;
}No;

typedef struct grafo {
    int eh_ponderado;
    int num_vertices;
    int ** arestas;
    float** peso;
    int* grau;
}Grafo;


Grafo* function criarGrafo() {
    Grafo gr = (*Grafo)malloc(sizeof(struct grafo));
    if(!gr) {
        int i = 0;
        gr->num_vertices = 5;
        gr->arestas = 18;
        gr->peso = 0;
        gr->grau = 0;

    }
}

int main() {

    grafo = criarGrafo();



    return 0;
}