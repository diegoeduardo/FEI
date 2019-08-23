//biblioteca para I/O  de dado
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

//uso do namespace std
using namespace std;

//metodo que ira realizar o calculo da funcão
float MetCalculaFuncao(float var1)
{
	//retornando a raiz quadrada de um número atraves de sqrt 
	//retornando a potencia atraves de pow
	return sqrt(1 - pow(var1, 2)); //raiz de 1 - x² dx
}

//metodo que ira realizar o calculo da derivada 
float MetCalculaDvd2(float var1)
{
	//inserção da função a ser calculada
	return 1 / pow((1 - pow(var1, 2)), 3 / 2); 
}

//metodo que ira realizar o calculo da derivada 
float MetCalculaDvd4(float var1)
{
	//inserção da função a ser calculada
	return (12 * pow(var1, 2)) + 3 / pow((1 - pow(var1, 2)), 7 / 2);
}

//metodo que ira realizar o calculo atraves da formula do Retangulo ou Ponto Medio
float MetCalcPontoMedio(float varCalc1, float varCalc2)
{
	//inserção da formula para calulo do valor estimado conforme essa regra
	return (varCalc2 - varCalc1) * MetCalculaFuncao((varCalc1 + varCalc2) / 2);	
}

//metodo que ira realizar o calculo atraves da formula do Trapezio
float MetCalcTrapezio(float varCalc1, float varCalc2)
{
	//inserção da formula para calulo do valor estimado conforme essa regra
	return (varCalc2 - varCalc1) * ((MetCalculaFuncao(varCalc1) + MetCalculaFuncao(varCalc2)) / 2);
}

//metodo que ira realizar o calculo atraves da formula do Simpson
float MetCalcSimpson(float varCalc1, float varCalc2)
{
	//inserção da formula para calulo do valor estimado conforme essa regra
	return (varCalc2 - varCalc1) * ((MetCalculaFuncao(varCalc1) + (4 * MetCalculaFuncao((varCalc1 + varCalc2) / 2)) + MetCalculaFuncao(varCalc2)) / 6);
}

//Abaixo metodos para calculo da formula de Erro 

//metodo que ira realizar o calculo do Erro atraves da formula do Erro da Regra de Retangulo ou Ponto Medio
float MetCalcErroPontoMedio(float varCalc1, float varCalc2)
{	
	//inserção da formula do erro para essa regra
	return -((pow((varCalc2 - varCalc1), 3) / 24) * MetCalculaDvd2(varCalc1 + ((varCalc2 - varCalc1) / 2)));
}

//metodo que ira realizar o calculo do Erro atraves da formula do Erro da Regra de Trapezio
float MetCalcErroTrapezio(float varCalc1, float varCalc2)
{
	//inserção da formula do erro para essa regra
	return -((pow((varCalc2 - varCalc1), 3) / 12) * MetCalculaDvd2(varCalc1 + ((varCalc2 - varCalc1) / 2)));
}

//metodo que ira realizar o calculo do Erro atraves da formula do Erro da Regra de Simpson
float MetCalcErroSimpson(float varCalc1, float varCalc2)
{
	//inserção da formula do erro para essa regra
	return -((pow((varCalc2 - varCalc1), 5) / 2880) * MetCalculaDvd4(varCalc1 + ((varCalc2 - varCalc1) / 2)));
}


// metodo principal, onde teremos a chamada para os outros metodos que serao usados no algortimo
int main()
{
	//declaracoes de variaveis
	//variaveis que sera usadas para calculo nas Regras
	float varCalc1 = 0;
	float varCalc2 = 1;

	//variaveis que receberão valores de aproximação calculados pelos suas respectivas regras
	float varMetRegraPontoMedio = MetCalcPontoMedio(varCalc1, varCalc2);
	float varMetRegraTrapezio = MetCalcTrapezio(varCalc1, varCalc2);
	float varMetRegraSimpson = MetCalcSimpson(varCalc1, varCalc2);

	//variaveis que receberão valores de erros calculados pelos suas respectivas regras de erros
	float varErroRegraPontoMedio = MetCalcErroPontoMedio(varCalc1, varCalc2);
	float varErroRegraTrapezio = MetCalcErroTrapezio(varCalc1, varCalc2);
	float varErroRegraSimpson = MetCalcErroSimpson(varCalc1, varCalc2);

	//output que mostrara o resultado para o usuario de cada uma das regras
	cout << "O VALOR PARA A REGRA DE PONTO MEDIO SERA: " << varMetRegraPontoMedio << endl;
	cout << "O VALOR PARA A REGRA DE TRAPEZIO SERA: " << varMetRegraTrapezio << endl;
	cout << "O VALOR PARA A REGRA DE SIMPSON SERA: " << varMetRegraSimpson << endl;
	
	//output que mostrara o resultado para o usuario o valor de cada erro para as regras	
	cout << "O VALOR DE ERRO PARA A REGRA DE PONTO MEDIO SERA: " << varErroRegraPontoMedio << endl;
	cout << "O VALOR DE ERRO PARA A REGRA DE TRAPEZIO SERA: " << varErroRegraTrapezio << endl;
	cout << "O VALOR DE ERRO PARA A REGRA DE SIMPSON SERA: " << varErroRegraSimpson << endl;
	
	cin.get();
}