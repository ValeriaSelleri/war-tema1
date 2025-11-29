c
#include <studio.h>
#include <stdlib.h>
#include <string.h>
#include "paises.h"
#include "jogadores.h"

#define MAX_PAISES 200
#define MAX_JOGADORES 6
#define MAX_NOME_JOG 50

int main () {
  Pais paises[MAX_PAISES];
  Jogador jogadores[MAX_JOGADORES];
  int qtd_paises = 0;
  int  qtd_jogadores = 0;

  printf("=== Desafio War Estruturado - Tema 1 ===\n");
  qtd_paises = carregar_mapa("..mapa.txt",paises,MAX_PAISES);
  if (qtd_paises<0){
    printf("Erro: náo foi possivel abrir mapa.txt. Coloque o arquivo 'mapa.txt"na raiz do projeto.\n");
    return 1;
  }
  printf("Mapa carregado: %d pais(es)\n", qtd_paises);

  printf("Quantos jogadores? (2-%d):", MAX_JOGADORES);
  if(scanf("%d", &qtd_jogadores)!= 1 || qtd_jogadores<2|| qtd_jogadores>MAX_JOGADORES){ 
    printf(Número de jogadores inválido.\n);
    return 1;
  }
  getchar();

  for(int i=0; i< qtd_jogadores; i++) {
    jogadores[i].id=i+1;
    jogadores[i].total_exercitos = 0;
    printf("Nome do jogador %d", i+1);
    fgets(jogadores[i].nome, MAX_NOME_JOG, stdin); 
    char *nl= strchr(jogadores[i].nome,'\n');
    if (nl)*nl='\0';
    if (strlen(jogadores[i].nome)==0)
sprintf(jogadores[i].nome, "Jogador%d", i+1);
  }

  distribuir_paises(paises,qtd_paises,jogadores,qtd_jogadores);

  printf("\n---Estado inicial ---\n");
  listar_paises(paises,qtd_paises);
  printf("\n");
  mostrar_jogadores(jogadores, qtd_jogadores);

  printf("\nFormato de 'mapa.txt: id;Nome;viz1;viz2;viz3\n");
  printf("Exemplo: 1;Brasil;2,3,5\n");

  return 0;
}



