//importação das bibliotecas que serao usadas no programa

#include <stdio.h>
#include <stdlib.h>
#include "puzzle8.h"
#include<conio.h>
#include <time.h>
#include <iostream>
using namespace std;

//metodo principal, onde teremos o menu principal e apos isso o acionamento dos metodos que sera acionados conforme escolha do usuario
int main()
{
    //variaveis usadas pelo programa 
	// opMenu sera variavel para guardar a opção do menu que sera escolhida e posterior direcionada para o CASE 
	// statusInicial sera variavel para guardar o status inicial do Puzzle, conforme informado como start para o problema
    int opMenu, statusInicial;
    PuzzleControlador<int> *P_Cont;
    PuzzleDfs<int> *P_dfs;
    PuzzleBfs<int> *P_bfs;
	PuzzleEncosta<int> *P_encosta;
    PuzzleAstar<int> *P_astar;
	statusInicial = 416328795;
	
	printf("PROGRAMA PARA RESOLVER PUZZLE - 8 CELULAS \n");
    printf( "\n PROBLEMA INICIAL A SER RESOLVIDO: \n| 4 | 1 | 6 |\n| 3 | 2 | 8 |\n| 7 | - | 5 |\n\n\n" );

    //Menu de escolha para direcionamento para metodo escolhido
		printf("***************DIGITE UMA OPCAO*************** \n");
		printf("OPCAO 1: RESOLVER POR BUSCA POR LARGURA (BFS)\n");
		printf("OPCAO 2: RESOLVER POR BUSCA POR PROFUNDIDADE (DFS)\n");
		printf("OPCAO 3: RESOLVER POR BUSCA POR SUBIDA DE ENCOSTA \n");
		printf("OPCAO 4- RESOLVER POR BUSCA POR A-ESTRELA \n");
		printf("OPCAO 5- SAIR \n");
    	printf("***************OPCAO ESCOLHIDA: ");
        scanf("%d", &opMenu);

		// A escolha da opção chamara o metodo referente a opção escolhida
		// Há contudo o uso de polimorfismo e metodos virtuais para opter os modos de resolução:
		// BFS, DFS, A*, Subida de encosta
		switch (opMenu){
			// Escolhendo a opçao 1 teremos a resolucao por busca em largura-BFS
			case 1:  
			    printf( "\n COMECANDO A SOLUCAO ATRAVES DE BUSCA EM LARGURA " );
                P_bfs=new PuzzleBfs<int>(1);
			    P_Cont=P_bfs;
                P_Cont->expanding_node(problema);
                P_Cont->~PuzzleControlador();
                break;
			// Escolhendo a opçao 2 teremos a resolucao por busca em profundidade-DFS
			case 2: 
                printf( "\n COMECANDO A SOLUCAO ATRAVES DE BUSCA EM PROFUNDIDADE " );
                P_dfs=new PuzzleDfs<int>(1);
                P_Cont=P_dfs;
                P_Cont->expanding_node(problema);
                P_Cont->~PuzzleControlador();
				break;
			// Escolhendo a opçao 3 teremos a resolucao por Subida de Encosta
			case 3: 
                printf( "\n COMECANDO A SOLUCAO ATRAVES DE BUSCA SUBIDA DE ENCOSTA " );
				P_encosta=new PuzzleEncosta<int>(1);
                P_Cont=P_encosta;
                P_Cont->expanding_node(problema);
                P_Cont->~PuzzleControlador();
				break;
			// Escolhendo a opçao 4 teremos a resolucao por A-ESTRELA
			case 4: 
			    printf( "\n COMECANDO A SOLUCAO ATRAVES DE A-ESTRELA " );
			    P_astar=new PuzzleAstar<int>(1);
                P_Cont=P_astar;
                P_Cont->expanding_node(problema);
                P_Cont->~PuzzleControlador();
				break;
			case 5: 
				exit(0);
				default: printf( "\n FINALIZANDO PROGRAMA \n" );
		}
	getch();
    exit(0);
}

