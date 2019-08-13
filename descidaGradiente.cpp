/*
Use o m�todo de Descida de Gradiente para encontrar o m�nimo das seguintes fun��es:
a) f(x) = x2, sendo x0 = 2
Derivada = f'(x) = 2 x
*/

//biblioteca para I/O  de dado
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>


//uso do namespace std
using namespace std;

//Metodo para calcular a fun��o derivada
double CalcularFunDerivada(double  x)
{
	//inser��o da fun��o
	return 2 * x;
}

//Metodo para calcular a funcao
double CalcularFuncao(double  x)
{
	//Funcao para potencia de um numero 
	return pow(x, 2);
}

void MetDescidaGradiente(double x0, double vBeta){
	
double  x = x0;
double  f = CalcularFuncao(x);
double  funcaoDerivada = CalcularFunDerivada(x);
 
while (abs(funcaoDerivada) > 0.00001)
{
	double  s = CalcularFunDerivada(x);
	
	x = x - vBeta * s ; 
	f = CalcularFunDerivada(x);
	cout << "X: " << x << " s: " << s << endl;
	funcaoDerivada = CalcularFunDerivada(x); 
} 
	cout << "M�nimo local se encontra em: "<< x << " e a fun��o neste ponto vale: " << CalcularFuncao(x);
	
} 



//metodo principal
int main()
{
	MetDescidaGradiente(2, 0.1);
	cin.get();
}
