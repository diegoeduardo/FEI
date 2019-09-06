//biblioteca para I/O  de dado
#include <mpi.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>
#include <math.h>

//uso do namespace std
using namespace std;

//MPI - DEFINICAO DO MASTER
#define MASTER 0

//MPI - metodo principal com parametros para o MPI funcionar
int main(int argc, char *argv[])
{
	//inicialização do metodo random
	srand (time(NULL));

	//declaracação das variaceis
	// numero de vezes que será executado o programa
	double n, j;

	//valor da densidade
	double den;

	//variaveis para as coordenadas de x, y e  z
	double x, y, z;
	
	/*variavel sw que irao guardar a somatario para 
	os resultados que entrarem na area do toroide*/ 
	double sw;

	/*variavel para os valores dentro do if para posterior 
	 uso no calculo do erro para area do toroide*/ 
    double varw;

	//variavel para guardar o resultado final do volume do toroide
	double w;
    
	//variavel para guardar o resultado final do erro para a area do toroide
    double dw;
		
	//variavel para os valores de acordo com as coordenadas do toroide
    double vol;

    //variaveis para somataria dos valores de x, y e z
	double somax, somay, somaz;

	/*variaveis para media dos valores de x, y e z pelo numero de vezes 
	que tivermos a entrada na area do toroide*/	
	double mediax, mediay, mediaz;
	
	//MPI - variaveis usadas no MPI;
	int   numtasks, taskid, rc;
	
	
	double swTotal, varwTotal, nTotal, somaxTotal, somayTotal, somazTotal;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
	
	
    //setando variaveis para executação numero de execuções
	//MPI -  fazendo a quantidade de vezes receber a quantidade dividido por NUMTASKS 
	n = 1000000/numtasks;

	
	//variaveis para guardar o tempo de execução
	double startime, stoptime, time;
	
	//start de do tempo
	startime = MPI_Wtime();
	

	//densidade
	den = 1.0 ;

	//setando em zero a variavel que sera somada conforme acumulado
	sw =  0.0;

	//volume da regiao do toroide de acordo com imagem proposta por PRESS
	vol = 3.0 * 7.0 * 2.0;
	
	//loop para realizacao das operacoes de acordo com a
	//quantidade de vezes definido na variavel N N
	for(int j=1; j<=n; j++ )
	{
		//executação do calculo para o valor de X
		//Multiplicado pela variavel que sera gerada randomicamente
		x = 1.0 + 3.0 *  rand() / (RAND_MAX);

		//executação do calculo para o valor de y 
		//Multiplicado pela variavel que sera gerada randomicamente
		y = (-3.0) + 7.0 * rand() / (RAND_MAX);

		//executação do calculo para o valor de z 
		//Multiplicado pela variavel que sera gerada randomicamente
		z = (-1.0) + 2.0 * rand() / (RAND_MAX);

		/*
		De acordo com cada execução no loop sera feito o if para definição se o valor aleatorio
		acertou o toroide ou nao, se ele tiver acertado entraremos no if abaixo 		
		*/
		if ( pow(z, 2.0) + pow(((sqrt(pow(x, 2.0) + pow(y, 2.0))) - 3.0), 2.0) < 1.0 	&& x >= 1.0 && y >= -3.0)
		{	
			//acumaladores dos valores de de x, y e z que estiverem na area do toroide
			somax += x;
		    somay += y;
			somaz += z;    
			
			/* sw ira guardar o valor da somataria dos valores 
        	   que acertarem a area do toroide	 */
			sw += den;
			
			//varw ira guardar o valor que sera usado para calculo do erro
           varw += pow(den, 2.0);
		}
	}

   //MPI - MPI REDUCE DAS VARIAVEIS
   rc = MPI_Reduce(&sw, &swTotal, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   rc = MPI_Reduce(&varw, &varwTotal, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   rc = MPI_Reduce(&n, &nTotal, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);   
   rc = MPI_Reduce(&somax, &somaxTotal, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   rc = MPI_Reduce(&somay, &somayTotal, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);
   rc = MPI_Reduce(&somaz, &somazTotal, 1, MPI_DOUBLE, MPI_SUM, MASTER, MPI_COMM_WORLD);   
   
   
   //MPI - mostando apenas os taskid do MASTER
   if (taskid == MASTER)
   {
	
	//CALCULOS FINAIS COM AS VARIAVEIS SOMATARIAS RETORNADAS NO MPI_REDUCE
	//calculo da media dos valores de x, y e z
	mediax = somaxTotal / swTotal ; 
	mediay = somayTotal / swTotal ;
	mediaz = somazTotal / swTotal ;
	
	//calculo do valor do volume
	w = vol * swTotal / nTotal;
	 
    //calculo do valor do erro
	dw = vol * sqrt(varwTotal / nTotal - (pow((swTotal / nTotal), 2)) / nTotal);
	
	//final de execucao da variavel do tempo
	stoptime = MPI_Wtime();
	
	//calculo para verificar o tempo de execucao
	time = stoptime - startime;
	
	cout << " -------------------------------"<< endl;
	cout << " -----RESULTADOS----------------"<< endl;
    cout << " -------------------------------"<< endl;		
	cout << " VALOR TOTAL DE X = " << somaxTotal << endl;
	cout << " VALOR TOTAL DE Y = " << somayTotal << endl;
	cout << " VALOR TOTAL DE Z = " << somazTotal << endl;
	
	cout << " -------------------------------"  << endl;
	
    cout << " VALOR DA MEDIA DE X = " << mediax << endl;
	cout << " VALOR DA MEDIA DE Y = " << mediay << endl;
	cout << " VALOR DA MEDIA DE Z = " << mediaz << endl;
	
    cout << " -------------------------------"  << endl;	
	
	//demonstracao dos resultados de volume e erro do toroide
	cout << " VOLUME DO TOROIDE SERA = " << w << endl;
	cout << " O ERRO PARA O TOROIDE SERA = " << dw << endl;
    cout << " -------------------------------"  << endl;	
	
	cout<< "NUMERO DE VEZES DE EXECUCAO: "<< nTotal<<endl;
	cout<< "TEMPO DE EXECUCAO: "<< time<<endl;
		
   }
	    
	//MPI - Finalizando o MPI 
	MPI_Finalize();
}