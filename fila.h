#include <stdio.h>
#include <stdlib.h>

int const MAXTAM=1000;

int Frente, Tras;
int FilaDados[MAXTAM];
//Classe Fila
class Fila{
    public:
    void FilaConstrutor();
    bool ChecaFilaVazia();
    bool ChecaFilaCheia();
    bool EnfileirarFila(int valor);
    bool DesenfileirarFila(int &valor);
    bool ConsultaFrenteFila(int &valor);
    int TamanhoFila();
    
};
//posicao inicial
//quando removemos, removemos do inicio
//quando inserimos vamos inserir no fim
void Fila::FilaConstrutor(){
    Frente=0;
    Tras=-1;
}
//a fila estara vazia quando a frente estara igual a tras
//frente tem que ser maior que tras
bool Fila::ChecaFilaVazia(){
    if(Frente>Tras){
        return true;
    }else{
        return false;
    }

    //return Frente>Tras;
}
//a fila estara cheia quando o tras = MAXTAM-1 e nao pode ser inserido mais nenhum valor
bool Fila::ChecaFilaCheia(){
    if(Tras==MAXTAM-1){
        return true;
    }else{
        return false;
    }
}
//checa se a fila esta cheia, estando nao posso inserir
//se a fila nao estiver cheia, enfilero um novo valor(insiro um novo valor)
bool Fila::EnfileirarFila(int valor){
    if(ChecaFilaCheia()){
        return false;
    }else{
        Tras++;
        FilaDados[Tras]=valor;
        return true;
    }
}
//checa se a fila esta vazia, estando nao posso desenfilerar
//se a fila nao estiver vazia, desenfilero um valor(retiro um valor)
bool Fila::DesenfileirarFila(int &valor){
    if(ChecaFilaVazia()){
        return false;
    }else{
        valor=FilaDados[Frente];
        Frente++;
        return true;
    }
}
//obteremos a frete da fila mas nao incrementaremos ela 
bool Fila::ConsultaFrenteFila(int &valor){
    if(ChecaFilaVazia()){
        return false;
    }else{
        valor=FilaDados[Frente];
        return true;
    }
}
//para buscar o tamanho temos o tras - frete + 1 
// esse mais um é devido a estarmos contando a partir do -1 , posicao do tras
int Fila::TamanhoFila(){
    return (Tras - Frente)+1;
}


int main(){
    int Valor;
    //FilaConstrutor();
    Fila fila;
    fila.FilaConstrutor();
    fila.EnfileirarFila(5);
    fila.EnfileirarFila(2);
    fila.EnfileirarFila(7);

    printf("\n\nTamanho:%d\n\n",fila.TamanhoFila());


    while( fila.DesenfileirarFila(Valor) ){
        printf("\nValor:%d\n",Valor);
    }
    printf("\n\nTamanho:%d\n\n",fila.TamanhoFila());
    
	fila.ConsultaFrenteFila(Valor);
    /*
    if( DesenfileirarFila(Valor) ){
        printf("\n\nValor:%d\n\n",Valor);
    }else{
        printf("\n\nFila Vazia\n\n");
    }*/

    system("pause");
    return 0;
}
