#ifndef PAISES_H
#define PAISES_H

#define MAX_VIZINHOS 20
#define MAX_NOME 64

typedef struct {
    int id;
    char nome[MAX_NOME];
    int dono;
    int exercitos;
    int vizinhos[MAX_VIZINHOS];
    int qtd_vizinhos;
} Pais;

int carregar_mapa(const char *arquivo, Pais paises[], int max_paises);
void listar_paises(Pais paises[], int qtd);
int encontrar_index_por_id(Pais paises[], int qtd, int id);

#endif
