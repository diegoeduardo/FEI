// Programa para PILHA EM C++
//TAD - TIPO ABSTRATO DE DADOS: INSIRA NO FINAL DO VETOR INDEPENDENTE DO TAMANHO DO VETOR

#include <stdio.h>
#include <stdlib.h>

//CRIANDO UMA PILHA DO TAMANHO 1000
int const MAXTAM = 1000;
 
int Pilha[MAXTAM];
int Topo;

//metodo contrutor
void PilhaConstrutor(){
    //declaro o topo como -1, pilha vazia = -1 , pois o vetor comeca a contar do numero 0
    Topo = -1;
    }

//metodo para checar se a pilha esta vazia    
bool ChecaPilhaVazia(){
    if (Topo==-1)
        return true;
    else 
    return false;
    }    

//metodo para checar se a pilha esta cheia ou nao
bool ChecarPilhaCheia(){
    if (Topo==MAXTAM-1)
    return true;
    else 
    return false;
}

//metodo push - inserir na pilha -- recebendo o valor que quero inserir na pilha
bool InsereNaPilha(int valor){
    //fazer o teste para checar se a pilha estiver cheia
    if(ChecarPilhaCheia()){
        return false;
    }else {
        Topo++;
        Pilha[Topo] = valor;
        return true;
    }
}

//metodo pop - retirar / desempilhar da pilha
bool RemoveDaPilha(int &valor){
    if(ChecaPilhaVazia() ){
        return false;
    }else{
        valor=Pilha[Topo];
        Topo--;
        return true;
    }
    }


bool ConsultaTopoPilha(int &valor){
    if(ChecaPilhaVazia() ){
        return false;
        }else{
            valor=Pilha[Topo];
            return true;
            }
    }
    
int ChecaTamanhoPilha(){
    // Se a pilha tiver um valor (na posicao 0) entao colocamos +1 para ele pegar essa posicao
    return Topo+1;  
    }    
    
int main(){
    int valor;
    
    //chamaando o construtor
    PilhaConstrutor();
    
    //inserindo
    InsereNaPilha(5);
    InsereNaPilha(2);
    InsereNaPilha(4);
    InsereNaPilha(1);
    InsereNaPilha(8);
    
    //quantidade antes de desempilhar
    printf("\n Quantidade de itens na pilha %d \n\n\n", ChecaTamanhoPilha() );
    while(RemoveDaPilha(valor) ) {
        printf("\n %d \n", valor);
    }
    printf("\n Quantidade de itens na pilha %d \n\n\n", ChecaTamanhoPilha() );
    
    InsereNaPilha(2);
    
    ConsultaTopoPilha(valor);
    printf("\n %d \n", valor);
    printf("\n Quantidade de itens na pilha %d \n\n\n", ChecaTamanhoPilha() );
    
    system("pause");
    return 0;
    }    