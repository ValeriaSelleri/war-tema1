#include <stdio.h>
#include <string.h>
#include "jogadores.h"
#include "paises.h"

void distribuir_paises(Pais paises[], int qtd_paises, Jogador jogadores[], int qtd_jogadores) {
    for (int i = 0; i < qtd_paises; i++) {
        int owner = (i % qtd_jogadores) + 1;
        paises[i].dono = owner;
        paises[i].exercitos = 1;
        jogadores[owner-1].total_exercitos++;
    }
}

void mostrar_jogadores(Jogador jogadores[], int qtd) {
    printf("Jogadores (%d):\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("ID %d - %s | exércitos totais: %d\n",
            jogadores[i].id, jogadores[i].nome, jogadores[i].total_exercitos
        );
    }
}
