/*
Use o método de Descida de Gradiente para encontrar o mínimo das seguintes funções
As funções podem ser inseridas nos metodos  CalcularFunDerivada e CalcularFuncao

Conforme podemos ver uma das funções esta comentada, caso desejar utilizar ela como parametro, basta comentar a que esta sendo usada e usa-la

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

//Metodo para calcular a função derivada
double CalcularFunDerivada(double  x)
{
	//inserção da função
 //  	return 2 * x;
     return 3 * pow(x, 2) - 4 * x;
}

//Metodo para calcular a funcao
double CalcularFuncao(double  x)
{
	//Funcao para potencia de um numero 
//	return pow(x, 2);
	return (pow(x, 3) - 2 * pow(x, 2) + 2);
}

//metodo para aplicação do algortimo da Descida  Gradiente
void MetDescidaGradiente(double x0, double varBeta){

//variavel para guardar primeiro resultado de x - primeira execucao
//valor incial	
double x = x0;

//variavel valor de f que sera o resultado da aplicação funcao que calcula a pontencia
//avaliacao de f em x0  
double f = CalcularFuncao(x);

//variavel que guarda o valor do calculo da variavel da funcao derivada em x
double funcaoDerivada = CalcularFunDerivada(x);
 
 
int quantPassos = 0;  
//condicao para execucao enquanto o valor da varievel funcaoDerivada seja maior que a taxa de aprendizado  
while (abs(funcaoDerivada) > 0.00000000000001) // 0.00000000000001 é o erro 
{
	//variavel para guardar o valor do resultado do calculo da derivada sobre X
	//s é igaul a inclinação da função 
	//acionamento do metodo CalcularFunDerivada e guardando valor em s   
	double  s = CalcularFunDerivada(x);
	
	// guarda o valor de x em funcao do calculo 
	//ande em x  
	x = x - varBeta * s ; 
	
	//demonstracao dos valores de X e S ate o fim do loop
	cout << "X: " << x << " s: " << s << endl;
	
	//novo calculo para o novo valor de x
	//ou seja avaliação de f no novo x  i + 1 
	funcaoDerivada = CalcularFunDerivada(x);
	quantPassos = quantPassos +1 ; 
} 
	//output dos dados trabalhados no algortimo e demonstração dos resultados
	cout << "Minimo local se encontra em (x): "<< x << " e a funcao neste ponto vale (y): " << CalcularFuncao(x) <<" Quantidade de passos: "<< quantPassos;
	
} 

//metodo principal com as chamadas para os metodos que deverão ser usados
int main()
{
	MetDescidaGradiente(2, 0.001);
	cin.get();
}
