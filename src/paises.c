#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "paises.h"

int carregar_mapa(const char *arquivo, Pais paises[], int max_paises) {
    FILE *f = fopen(arquivo, "r");
    if (!f) return -1;

    char linha[512];
    int cont = 0;

    while (fgets(linha, sizeof(linha), f) && cont < max_paises) {
        char *p = linha;
        char *nl = strchr(p, '\n');
        if (nl) *nl = '\0';
        if (strlen(p) == 0) continue;

        char *token = strtok(p, ";");
        paises[cont].id = atoi(token);

        token = strtok(NULL, ";");
        strncpy(paises[cont].nome, token, MAX_NOME);

        paises[cont].qtd_vizinhos = 0;
        token = strtok(NULL, ";");

        if (token) {
            char *v = strtok(token, ",");
            while (v) {
                paises[cont].vizinhos[paises[cont].qtd_vizinhos++] = atoi(v);
                v = strtok(NULL, ",");
            }
        }

        paises[cont].dono = 0;
        paises[cont].exercitos = 0;

        cont++;
    }

    fclose(f);
    return cont;
}

void listar_paises(Pais paises[], int qtd) {
    printf("Lista de %d pais(es):\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("ID %d - %s | dono: %d | exércitos: %d | vizinhos:",
            paises[i].id, paises[i].nome, paises[i].dono, paises[i].exercitos
        );

        for (int j = 0; j < paises[i].qtd_vizinhos; j++) {
            printf(" %d", paises[i].vizinhos[j]);
        }

        printf("\n");
    }
}

int encontrar_index_por_id(Pais paises[], int qtd, int id) {
    for (int i = 0; i < qtd; i++) {
        if (paises[i].id == id) return i;
    }
    return -1;
}
