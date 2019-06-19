// Programa para PILHA EM C++
//TAD - TIPO ABSTRATO DE DADOS: INSIRA NO FINAL DO VETOR INDEPENDENTE DO TAMANHO DO VETOR

#include <stdio.h>
#include <stdlib.h>

//CRIANDO UMA PILHA DO TAMANHO 1000
int const MAXTAM = 1000;
 
int PilhaDados[MAXTAM];
int Topo;
//classe Pilha
class Pilha{
    public:
    void PilhaConstrutor();
    bool ChecaPilhaVazia();
    bool ChecarPilhaCheia();
    bool InsereNaPilha(int valor);
    bool RemoveDaPilha(int &valor);
    bool ConsultaTopoPilha(int &valor);
    int ChecaTamanhoPilha();
    
};

//metodo contrutor
void Pilha::PilhaConstrutor(){
    //declaro o topo como -1, pilha vazia = -1 , pois o vetor comeca a contar do numero 0
    Topo = -1;
    }

//metodo para checar se a pilha esta vazia    
bool Pilha::ChecaPilhaVazia(){
    if (Topo==-1)
        return true;
    else 
    return false;
    }    

//metodo para checar se a pilha esta cheia ou nao
bool Pilha::ChecarPilhaCheia(){
    if (Topo==MAXTAM-1)
    return true;
    else 
    return false;
}

//metodo push - inserir na pilha -- recebendo o valor que quero inserir na pilha
bool Pilha::InsereNaPilha(int valor){
    //fazer o teste para checar se a pilha estiver cheia
    if(ChecarPilhaCheia()){
        return false;
    }else {
        Topo++;
        PilhaDados[Topo] = valor;
        return true;
    }
}

//metodo pop - retirar / desempilhar da pilha
bool Pilha::RemoveDaPilha(int &valor){
    if(ChecaPilhaVazia() ){
        return false;
    }else{
        valor=PilhaDados[Topo];
        Topo--;
        return true;
    }
    }


bool Pilha::ConsultaTopoPilha(int &valor){
    if(ChecaPilhaVazia() ){
        return false;
        }else{
            valor=PilhaDados[Topo];
            return true;
            }
    }
    
int Pilha::ChecaTamanhoPilha(){
    // Se a pilha tiver um valor (na posicao 0) entao colocamos +1 para ele pegar essa posicao
    return Topo+1;  
    }    
    
int main(){
    int valor;
    
    //chamaando o construtor
    //PilhaConstrutor();
    Pilha pilha;
    
    
    //inserindo
    pilha.InsereNaPilha(5);
    pilha.InsereNaPilha(2);
    pilha.InsereNaPilha(4);
    pilha.InsereNaPilha(1);
    pilha.InsereNaPilha(8);
    
    //quantidade antes de desempilhar
    printf("\n Quantidade de itens na pilha %d \n\n\n", pilha.ChecaTamanhoPilha() );
    while(pilha.RemoveDaPilha(valor) ) {
        printf("\n %d \n", valor);
    }
    printf("\n Quantidade de itens na pilha %d \n\n\n", pilha.ChecaTamanhoPilha() );
    
    pilha.InsereNaPilha(2);
    
    pilha.ConsultaTopoPilha(valor);
    printf("\n %d \n", valor);
    printf("\n Quantidade de itens na pilha %d \n\n\n", pilha.ChecaTamanhoPilha() );
    
    system("pause");
    return 0;
    }    
