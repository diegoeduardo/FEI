//biblioteca para I/O  de dado
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

//uso do namespace std
using namespace std;

//metodo principal
int main()
{
	//inicialização do metodo random
	srand (time(NULL));

	//declaracação das variaceis
	// numero de vezes que será executado o programa
	int n, j;

	//valor da densidade
	float den;

	//variaveis para as coordenadas de x, y e  z
	float x, y, z;
	
	/*variavel sw que irao guardar a somatario para 
	os resultados que entrarem na area do toroide*/ 
	float sw;

	/*variavel para os valores dentro do if para posterior 
	 uso no calculo do erro para area do toroide*/ 
    float varw;

	//variavel para guardar o resultado final do volume do toroide
	float w;
    
	//variavel para guardar o resultado final do erro para a area do toroide
    float dw;
		
	//variavel para os valores de acordo com as coordenadas do toroide
    float vol;

    //variaveis para somataria dos valores de x, y e z
	float somax, somay, somaz;

	/*variaveis para media dos valores de x, y e z pelo numero de vezes 
	que tivermos a entrada na area do toroide*/	
	float mediax, mediay, mediaz;
	
	//setando variaveis para executação
	// numero de execuções
	n = 1000000;

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

	//calculo da media dos valores de x, y e z
	mediax = somax / sw ; 
	mediay = somay / sw ;
	mediaz = somaz / sw ;
	
	//calculo do valor do volume
	w = vol * sw / n;
	 
    //calculo do valor do erro
	dw = vol * sqrt(varw / n - (pow((sw / n), 2)) / n);
	
    cout << " -------------------------------"<< endl;
	cout << " -----RESULTADOS----------------"<< endl;
    cout << " -------------------------------"<< endl;		
	cout << " VALOR TOTAL DE X = " << somax << endl;
	cout << " VALOR TOTAL DE Y = " << somay << endl;
	cout << " VALOR TOTAL DE Z = " << somaz << endl;
	
	cout << " -------------------------------"  << endl;
	
    cout << " VALOR DA MEDIA DE X = " << mediax << endl;
	cout << " VALOR DA MEDIA DE Y = " << mediay << endl;
	cout << " VALOR DA MEDIA DE Z = " << mediaz << endl;
	
    cout << " -------------------------------"  << endl;	
	
	//demonstracao dos resultados de volume e erro do toroide
	cout << " VOLUME DO TOROIDE SERA = " << w << endl;
	cout << " O ERRO PARA O TOROIDE SERA = " << dw << endl;
    cout << " -------------------------------"  << endl;	
}