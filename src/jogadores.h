#ifndef JOGADORES_H
#define JOGADORES_H

#define MAX_JOG 6
#define MAX_NOME_JOG 50

typedef struct {
    int id;
    char nome[MAX_NOME_JOG];
    int total_exercitos;
} Jogador;

void distribuir_paises(struct Pais paises[], int qtd_paises, Jogador jogadores[], int qtd_jogadores);
void mostrar_jogadores(Jogador jogadores[], int qtd);

#endif
