#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>

// cores e seus codigos 

#define COR_PRETO "\x1b[38;5;232m"
#define COR_ROSACHOX "\x1b[38;5;141m"
#define COR_ROSAPINK "\x1b[38;5;165m"
#define COR_RESET "\x1B[0m"
#define COR_VERMELHA "\x1B[31m"
#define COR_VERDE "\x1B[32m"
#define COR_ROSA "\x1b[38;5;201m"
#define COR_AMARELA "\x1B[33m"

// exibir arte do menu
void vapara(int linha, int coluna)
{
  COORD coord;
  coord.X = coluna;
  coord.Y = linha;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void exibirMenu()
{   char matriz[18][50] = {
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','F','P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','F',' ',' ',' ',' ',' ',' ',' ','F',' ',' ',' ','F','P',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','F',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','F',' ','F','P',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ','A','A','A','A','A','A','A',' ',' ',' ',' ',' ',' ',' ','A','A',' ',' ',' ',' ',' ',' ',' ',' ',' ','A','A','A','A',' ',' ','F',' ',' ','A','A','A','A','P',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ','A','A',' ',' ',' ',' ',' ',' ','A','A','A','A',' ',' ',' ',' ',' ',' ',' ','A','E','E','E','E','A',' ','F',' ','A','E','E','E','E','A','P',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ','B','B',' ',' ',' ',' ',' ',' ','B','B',' ',' ','B','B',' ',' ',' ',' ',' ','B','D','D','D','D','D','D','D','F','D','D','D','D','D','D','D','B','P',' '},
    {'F',' ',' ',' ',' ',' ','B','B',' ',' ',' ',' ',' ',' ','B','B',' ',' ',' ',' ','B','B',' ',' ',' ',' ',' ','B','C','C','C','C','C','C','F','C','C','C','C','C','C','B','P',' ',' '},
    {' ',' ',' ',' ',' ','C','C',' ',' ',' ',' ',' ',' ','C','C','C','C','C','C','C','C','C','C',' ',' ',' ',' ',' ','C','B','B','B','B','B','F','B','B','B','B','B','C','P',' ',' ',' '},
    {' ',' ',' ',' ','D','D',' ',' ',' ',' ',' ',' ','D','D',' ',' ',' ',' ',' ',' ',' ',' ','D','D',' ',' ',' ','D','A','A','A','A','A','A','F','A','A','A','A','A','A','D','P',' ',' '},
    {' ',' ',' ','E','E',' ',' ',' ',' ',' ',' ','E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','E','E',' ',' ','E','A','A','A','A','E',' ','F',' ','E','A','A','A','A','E','P',' ',' '},
    {' ',' ',' ','E','E','E','E','E','E',' ','E','E',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','E','E',' ',' ','E','E','E','E',' ',' ',' ',' ',' ','E','E','E','E',' ',' ','F','P'},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','F','P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','B','P'},
    {' ',' ','A','A',' ',' ','A','A',' ',' ','A','A',' ',' ','A','A',' ',' ','A','A',' ',' ','A','A',' ',' ','A','A',' ',' ','A','A',' ',' ','A','A',' ',' ','A','A',' ','A','A','P',' '},
    {'F',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','F','P',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ','F',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','F','P',' ',' ',' '},
};
    int lin, col;
    // um for pra cada parte da matriz
    printf("\n\n\n\n\n\n\n\n\n\n");
    for(lin = 0; lin < 18; lin++){
        printf("\t\t\t\t\t\t\t\t\t\t     ");
        for(col = 0; col < 50; col++){
            if(matriz[lin][col] == ' '){
                printf("%c", matriz[lin][col]);
            } else if(matriz[lin][col] == 'A'){
            	// codigo da cor usada
                printf("\033[38;5;93m\033[48;5;93m%c\033[0m",matriz[lin][col]);
            } else if(matriz[lin][col] == 'B'){
                printf("\033[38;5;129m\033[48;5;129m%c\033[0m",matriz[lin][col]);
   	 	    } else if(matriz[lin][col] == 'P'){
                printf("\033[38;5;232m\033[48;5;232m%c\033[0m",matriz[lin][col]);
			} else if(matriz[lin][col] == 'F'){
                printf("\033[38;5;225m\033[48;5;225m%c\033[0m",matriz[lin][col]);
            } else if(matriz[lin][col] == 'C' && lin < 13){
                printf("\033[38;5;165m\033[48;5;165m%c\033[0m",matriz[lin][col]);
            } else if(matriz[lin][col] == 'D' && lin < 13){
                printf("\033[38;5;201m\033[48;5;201m%c\033[0m",matriz[lin][col]);
            } else if(matriz[lin][col] == 'E' && lin < 13){
                printf("\033[38;5;200m\033[48;5;200m%c\033[0m",matriz[lin][col]);
            } else if(lin > 13 && matriz[lin][col] != '>') {
                printf("%c", matriz[lin][col]);
            } else if(matriz[lin][col] == '>'){
                printf("\033[38;5;21m%c\033[0m",matriz[lin][col]);
            }
        }
        printf("\n");
    }
}

// tabuleiro de 9 posi�oes

void tabuleiro(char casas2[9])
{
    system("cls");
    
    char parede = '|';
    char chao = '-';

     printf("\t\n\n\n\n\n\n                                                                                                  %s%c%s  %s%c%s  %s%c%s  %s%c%s %s%c%s    \n",
           COR_VERMELHA, casas2[0], COR_RESET, COR_ROSACHOX, parede, COR_RESET,
           COR_VERDE, casas2[1], COR_RESET, COR_ROSACHOX, parede, COR_RESET,
           COR_AMARELA, casas2[2], COR_RESET, COR_ROSACHOX, parede, COR_RESET);
    printf("\t                                                                                          %s%c%c%c%c%c%c%c%c%c%c%c%c%c%s\n", COR_ROSAPINK, chao, chao, chao, chao, chao, chao, chao, chao, chao, chao, chao, chao, chao, COR_RESET);
	printf("\t                                                                                          %s%c%s  %s%c%s  %s%c%s  %s%c%s %s%c%s    \n",
           COR_VERMELHA, casas2[3], COR_RESET, COR_ROSACHOX, parede, COR_RESET,
           COR_VERDE, casas2[4], COR_RESET, COR_ROSACHOX, parede, COR_RESET,
           COR_AMARELA, casas2[5], COR_RESET, COR_ROSACHOX, parede, COR_RESET);
    printf("\t                                                                                          %s%c%c%c%c%c%c%c%c%c%c%c%c%c%s\n", COR_ROSAPINK, chao, chao, chao, chao, chao, chao, chao, chao, chao, chao, chao, chao, chao, COR_RESET);
   	printf("\t                                                                                          %s%c%s  %s%c%s  %s%c%s  %s%c%s %s%c%s    \n",
            COR_VERMELHA, casas2[6], COR_RESET, COR_ROSACHOX, parede, COR_RESET,
           COR_VERDE, casas2[7], COR_RESET, COR_ROSACHOX, parede, COR_RESET,
           COR_AMARELA, casas2[8], COR_RESET, COR_ROSACHOX, parede, COR_RESET);
}

void amigos()
{
	// colorir o terminal	
	system("color 5F");
	
    char jogador1_nome[50]; // Nome do jogador X
    char jogador2_nome[50]; // Nome do jogador O

    printf("\n\n\n\n\n\n\n\n\n\n                                                                                       Digite o nome do jogador X: ");
    getchar();
    gets(jogador1_nome);

    printf("\n\n                                                                                       Digite o nome do jogador O: ");
    gets(jogador2_nome);

    // vetor tem 9 posicoes que vai de 0 a 8
    char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char resposta_usuario[50];
    int contador_jogadas;
    int jogada_usuario = 1;
    int vez = 0;
    int i;
    int jogador1 = 0;
    int jogador2 = 0;
    int empate = 0;

	// colorir o terminal	
	system("color 0F");
	
	inicio:
    do
    {
        /*comeca com 1 para usar na logica que 
        quando for 0 a jogada eh invalida*/
        contador_jogadas = 1;
        // limpa o tabuleiro
        for (i = 0; i < 9; i++)
        {
            casas[i] = ' ';
        }

        do
        {
            // mostrar o tabuleiro
            tabuleiro(casas);

            // se for 0 a jogada eh invalida, por isso la em cima comeca com 1
            /* essa condicao fica em cima pois quando for scaneada la em baixo e ja for 0 
            o resto do codigo a baixo do scan nem vai ser executado e voltara pra ca*/
            if (jogada_usuario == 0)
            {
            	// de primeira nao faz nada pq a variavel ja comeca sendo 1
                printf("\n                                                                                         Jogada invalida, tente novamente!\n");
            }

            // Pede a casa para o usuario marcar
            printf("\n                                                                                             Digite uma casa (1 - 9) \n");

            // valido para a primeira jogada 
            if(vez==0){
				// gerar um numero aleatorio que diz quem vai primeiro
				srand(time(NULL));
	   	   	   	vez = rand() % 10;
	   	   	   	// vez igual a um numero aleatorio
	 	  	    if(vez % 2 == 0){
			  		printf("\n                                                                                             A vez eh do jogador: %s%s%s\n\n", COR_ROSA, jogador1_nome, COR_RESET);
	   		   	}else{
				   	printf("\n                                                                                             A vez eh do jogador: %s%s%s\n\n",  COR_VERDE, jogador2_nome, COR_RESET);
	   	   	   	}
			}else{
				// vez igual a o numero alet agora so sendo divido depois da 1 partida
				if(vez % 2 == 0){
			  		printf("\n                                                                                             A vez eh do jogador: %s%s%s\n\n", COR_ROSA, jogador1_nome, COR_RESET);
	   		   	}else{
				   	printf("\n                                                                                             A vez eh do jogador: %s%s%s\n\n",  COR_VERDE, jogador2_nome, COR_RESET);
	   	   	   	}
			}


			int seg = 15, iseg = 15;

		   	while(iseg<=15 && iseg != 0){ //timer de 15 segundos para realizar a jogada

				if(iseg>=10){
			      	vapara(3,102);
			      	printf("00:%d", seg);
		 	     	seg -= 1;
			   	   	Sleep(900);
			   	   	vapara(80,102);
   	   			}
   	   			
			   	else if(iseg>5 && iseg<10){
		  	    	vapara(3,102);
		  	    	printf("00:0%d", seg);
			   	   	seg -= 1;
		 	     	Sleep(900);
			   	   	vapara(80,102);
 	    		}
 	    		
			   	else if(iseg<=5){
			      	vapara(3,102);
		 	     	printf("\x1b[31m00:0%d\x1b[0m", seg);
		 	     	seg -= 1;
		 	     	Sleep(900);
			   	   	vapara(80,102);
 	    		}
		  	    	iseg--;
		    	
				if(kbhit()) {
					vapara(15,102); //ler a jogada do usuario sem parar o timer
					jogada_usuario = 0;
					jogada_usuario = getch();
					
					if(jogada_usuario == 49){
						jogada_usuario = 1;
						iseg = 0;
					}
					else if(jogada_usuario == 50){
						jogada_usuario = 2;
						iseg = 0;
					}
					else if(jogada_usuario == 51){
						jogada_usuario = 3;
						iseg = 0;
					}
					else if(jogada_usuario == 52){
						jogada_usuario = 4;
						iseg = 0;
					}
					else if(jogada_usuario == 53){
						jogada_usuario = 5;
						iseg = 0;
					}
					else if(jogada_usuario == 54){
						jogada_usuario = 6;
						iseg = 0;
					}
					else if(jogada_usuario == 55){
						jogada_usuario = 7;
						iseg = 0;
					}
					else if(jogada_usuario == 56){
						jogada_usuario = 8;
						iseg = 0;
					}
					else if(jogada_usuario == 57){
						jogada_usuario = 9;
						iseg = 0;
					}
					else if (jogada_usuario == 0 || jogada_usuario == 48){
  	   					denovo:
						jogada_usuario = rand() % 9 + 1; 
					 
						 if(jogada_usuario == 1 && casas[0] != ' '){
							 goto denovo;
						 }
						 else if(jogada_usuario == 2 && casas[1] != ' '){
							 goto denovo;
						 }
						 else if(jogada_usuario == 3 && casas[2] != ' '){
							 goto denovo;
						 }
						 else if(jogada_usuario == 4 && casas[3] != ' '){
							 goto denovo;
						 }
						 else if(jogada_usuario == 5 && casas[4] != ' '){
							 goto denovo;
						 }
						 else if(jogada_usuario == 6 && casas[5] != ' '){
							 goto denovo;
						 }
						 else if(jogada_usuario == 7 && casas[6] != ' '){
							 goto denovo;
						 }
						 else if(jogada_usuario == 8 && casas[7] != ' '){
							 goto denovo;
						 }
						 else if(jogada_usuario == 9 && casas[8] != ' '){
							 goto denovo;
						 }
						 printf("%d", jogada_usuario);
						 Sleep(10000);
  	   			}
  	   				
						 
					 }	 
  	   			
			}

	 	     	

            // Verifica se a jogada eh valida
            if (jogada_usuario < 1 || jogada_usuario > 9)
            {
                jogada_usuario = 0;
            }
            // verificar se a casa esta ocupada ou nao
            /* casas na posicao jogada_usuario - 1 for diferente de um caractere
            em branco, x -1 pq o vetor � de 0 - 8
            quando o usuario digitar 1 ele na verdade vai digitar um 0*/
            else if (casas[jogada_usuario - 1] != ' ')
            {
                jogada_usuario = 0;
            }
            // entao e uma jogada valida 
            else
            {
                if (vez % 2 == 0)
                {
                    casas[jogada_usuario - 1] = 'X';
                }
                else
                {
                    casas[jogada_usuario - 1] = 'O';
                }

                contador_jogadas++;
                // soma na vez pois se for par agora sera impar e visvers
                vez++;
            }

            // horizontal - x - vitorias 
            if (casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X')
            {
                contador_jogadas = 11;
            }

            // vertical - x - vitorias 
            if (casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X')
            {
                contador_jogadas = 11;
            }

            // diagonais - x - vitorias
            if (casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X')
            {
                contador_jogadas = 11;
            }

            // vitorias - hroizontal - O

            if (casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O')
            {
                contador_jogadas = 12;
            }

            // vitorias - vertical - O
            if (casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O')
            {
                contador_jogadas = 12;
            }

            // diagonais - vitorias - O
            if (casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[2] == 'O' && casas[4] == 'O' && casas[6] == 'O')
            {
                contador_jogadas = 12;
            }

        }while (contador_jogadas <= 9);
	

        tabuleiro(casas);

        if (contador_jogadas == 10)
        {
            empate++;
        }
        else if (contador_jogadas == 11)
        {
            printf("\n                                                                                                  %s%s%s VENCEU!!!\n\n", COR_ROSA, jogador1_nome, COR_RESET);
            jogador1++;
        }
        else if (contador_jogadas == 12)
        {
            printf("\n                                                                                                  %s%s%s VENCEU!!!\n\n", COR_VERDE, jogador2_nome, COR_RESET);
            jogador2++;
        }
        
        char n = 'n';
   	    char s = 's';
   	    char placar[50];
        
        // pega as variaveis de cima e soma a vitoria ou empate
        printf("\n                                           | Pontos do jogador %s%s%s: %d |\n", COR_ROSA, jogador1_nome, COR_RESET, jogador1);
        printf("\n                                           | Pontos do jogador %s%s%s: %d |\n", COR_VERDE, jogador2_nome, COR_RESET, jogador2);
        printf("\n                                           | Empates: %d                  |\n\n", empate);
        printf("\n                                            Deseja jogar novamente? (%s%c%s/%s%c%s): ", COR_VERDE, s, COR_RESET, COR_VERMELHA, n, COR_RESET);
        scanf(" %s", &resposta_usuario);
        
		if(resposta_usuario[0] == 'n'){
			principio();
		}else if(resposta_usuario[0] == 's'){
			// reiniciar o placar
			printf("\n                                            Deseja reiniciar o placar? (%s%c%s/%s%c%s): ", COR_VERDE, s, COR_RESET, COR_VERMELHA, n, COR_RESET);
        	scanf(" %s", &placar);
        	if(placar[0]=='s'){
			   	jogador1=0;
			   	jogador2=0;
	  	    }	
		}
		
    }
	while(resposta_usuario[0] == 's');
}


void computador()
{
	// colorir o terminal	
	system("color DF");
	
    char jogador1_nome[50] = {"NEWJEANS"}; // Nome do jogador X
    char jogador2_nome[50]; // Nome do jogador O

    printf("\n\n\n\n\n\n\n\n\n\n                                                                                       Digite o nome do jogador O: ");
    getchar();
    gets(jogador2_nome);


    // vetor tem 9 posicoes que vai de 0 a 8
    char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char resposta_usuario[50];
    int contador_jogadas;
    int jogada_usuario = 1;
    int vez = 0;
    int i;
    int jogador1 = 0;
    int jogador2 = 0;
    int empate = 0;
    
    // colorir o terminal
	system("color 0F");

    do
    {
        /*comeca com 1 para usar na logica que 
        quando for 0 a jogada eh invalida*/
        contador_jogadas = 1;
        // limpa o tabuleiro
        for (i = 0; i < 9; i++)
        {
            casas[i] = ' ';
        }

        do
        {
            // mostrar o tabuleiro
            tabuleiro(casas);

            // se for 0 a jogada eh invalida, por isso la em cima comeca com 1
            if (jogada_usuario == 0)
            {
                printf("\n                                                                                         Jogada invalida, tente novamente!\n");
            }

            // Pede a casa para o usuario marcar
            printf("\n                                                                                             Digite uma casa (1 - 9) \n");

            // valido para a primeira jogada 
            if(vez==0){
				// gerar um numero aleatorio que diz quem vai primeiro
				srand(time(NULL));
	   	   	   	vez = rand() % 10;
	 	  	    if(vez % 2 == 0){
			  		printf("\n                                                                                             A vez eh do jogador %s%s%s\n\n", COR_ROSA, jogador1_nome, COR_RESET);
	   		   	}else{
				   	printf("\n                                                                                             A vez eh do jogador %s%s%s\n\n",  COR_VERDE, jogador2_nome, COR_RESET);
	   	   	   	}
			}else{
				if(vez % 2 == 0){
			  		printf("\n                                                                                             A vez eh do jogador %s%s%s\n\n", COR_ROSA, jogador1_nome, COR_RESET);
	   		   	}else{
				   	printf("\n                                                                                             A vez eh do jogador %s%s%s\n\n",  COR_VERDE, jogador2_nome, COR_RESET);
	   	   	   	}
			}

            if(vez % 2 == 0){
			    srand(time(NULL));
				jogada_usuario = rand() % 10;
			}else{
				printf("%s-------------------------------------------------------------------------------------------------------%s", COR_PRETO, COR_RESET);
      	  	    scanf("%d", &jogada_usuario);
			}	

            // Verifica se a jogada eh valida
            if (jogada_usuario < 1 || jogada_usuario > 9)
            {
                jogada_usuario = 0;
            }
            // verificar se a casa esta ocupada ou nao
            /* casas na posicao jogada_usuario - 1 for diferente de um caractere
            em branco, x -1 pq o vetor � de 0 - 8
            quando o usuario digitar 1 ele na verdade vai digitar um 0*/
            else if (casas[jogada_usuario - 1] != ' ')
            {
                jogada_usuario = 0;
            }
            // entao e uma jogada valida 
            else
            {
                if (vez % 2 == 0)
                {
                    casas[jogada_usuario - 1] = 'X';
                }
                else
                {
                    casas[jogada_usuario - 1] = 'O';
                }

                contador_jogadas++;
                vez++;
            }

            // horizontal - x - vitorias 
            if (casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X')
            {
            	// quando for isso ja sai da condicao por ser maior que 9
                contador_jogadas = 11;
            }
            if (casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X')
            {
                contador_jogadas = 11;
            }

            // vertical - x - vitorias 
            if (casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X')
            {
                contador_jogadas = 11;
            }

            // diagonais - x - vitorias
            if (casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X')
            {
                contador_jogadas = 11;
            }
            if (casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X')
            {
                contador_jogadas = 11;
            }

            // vitorias - hroizontal - O

            if (casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O')
            {
                contador_jogadas = 12;
            }

            // vitorias - vertical - O
            if (casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O')
            {
                contador_jogadas = 12;
            }

            // diagonais - vitorias - O
            if (casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O')
            {
                contador_jogadas = 12;
            }
            if (casas[2] == 'O' && casas[4] == 'O' && casas[6] == 'O')
            {
                contador_jogadas = 12;
            }
		// roda 10 vezes e na numero 10 ele sai	
        }while (contador_jogadas <= 9);
	

        tabuleiro(casas);

        if (contador_jogadas == 10)
        {
            printf("\n Empate\n");
            empate++;
        }
       else if (contador_jogadas == 11)
        {
            printf("\n                                                                                                  %s%s%s VENCEU!!!\n\n", COR_ROSA, jogador1_nome, COR_RESET);
            jogador1++;
        }
        else if (contador_jogadas == 12)
        {
            printf("\n                                                                                                  %s%s%s VENCEU!!!\n\n", COR_VERDE, jogador2_nome, COR_RESET);
            jogador2++;
        }
        
        char n = 'n';
   	    char s = 's';
   	    char placar[50];
        
        // pega as variaveis de cima e soma a vitoria ou empate
        printf("\n                                           | Pontos do jogador %s%s%s: %d |\n", COR_ROSA, jogador1_nome, COR_RESET, jogador1);
        printf("\n                                           | Pontos do jogador %s%s%s: %d |\n", COR_VERDE, jogador2_nome, COR_RESET, jogador2);
        printf("\n                                           | Empates: %d                  |\n\n", empate);
        printf("\n                                            Deseja jogar novamente? (%s%c%s/%s%c%s): ", COR_VERDE, s, COR_RESET, COR_VERMELHA, n, COR_RESET);
        scanf(" %s", &resposta_usuario);
        
		if(resposta_usuario[0] == 'n'){
			principio();
		}else if(resposta_usuario[0] == 's'){
			// reiniciar o placar
			printf("\n                                            Deseja reiniciar o placar? (%s%c%s/%s%c%s): ", COR_VERDE, s, COR_RESET, COR_VERMELHA, n, COR_RESET);
        	scanf(" %s", &placar);
        	if(placar[0]=='s'){
			   	jogador1=0;
			   	jogador2=0;
	  	    }	
		}

    }while(resposta_usuario[0] == 's');
}

void principio()
{
	
	system("cls");
	
	// acentos
	setlocale(LC_ALL, "Portuguese");
	
	// usando isso para atribuir cor ao texto da variavel
	char amigoscor[50] = "    1 - COM AMIGOS";
	char computadorcor[50] = "    2 - COM COMPUTADOR";
	char saircor[50] = "    3 - SAIR DO JOGO";
	char opcao;
	
	do{ 
	    exibirMenu();
		printf("                                                                                              EM QUAL MODO DESEJA JOGAR?\n\n");
		printf("                                                                                                %s%s%s\n\n", COR_ROSAPINK, amigoscor, COR_RESET);
		printf("                                                                                                %s%s%s\n\n", COR_ROSACHOX, computadorcor, COR_RESET);
		printf("                                                                                                %s%s%s\n\n", COR_ROSA, saircor, COR_RESET);
		printf("                                                                                              DIGITE SUA ESCOLHA: ");
		scanf("%c", &opcao);
	    if(opcao < '1' || opcao > '3' || isalpha(opcao)==0){
			system("cls");
		}
    }while(opcao < '1' || opcao > '3');
    
    if(opcao == '1'){
    	system("cls");
		amigos(opcao);
	}
	if(opcao == '2'){
		system("cls");
		computador(opcao);
	}
	if(opcao == '3'){
    	return 0;
	}
}

int main(){
	Sleep(1000);
	// TELA CHEIA
    keybd_event(VK_MENU,0x36,0,0);
    keybd_event(VK_RETURN,0x1C,0,0);
    keybd_event(VK_RETURN,0x1C,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
	principio();
}