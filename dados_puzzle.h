//importação das bibliotecas que serao usadas no programa
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#include <iostream>
using namespace std;

//classes para uso de templates t conforme exigido pelo trabalho

template <class T>
//Classe unitMem responsavel pela memoria base para juncao de todos objetos
class unitMem{
    public:
        unitMem();        
		//contTemplate com tipo T - template definido acima
        T ContTemplate;                 
        int statusTemplate;             
        int custoTemplate;              
        int princTemplate;
        class unitMem *posAnterior;     
        class unitMem *posPosterior;    
        class unitMem *posElo ;         
};
// constructor of unitMem,initialize private variable and allocate memory to valor
template <typename T>
unitMem<T>::unitMem(){
    //statusTemplate se 0 aberto , se 1 checando , 2 verificado
    statusTemplate=0;
	//custo para o objetivo do vertice
    custoTemplate=0;
    posAnterior=NULL;
    posPosterior=NULL;
    posElo=NULL;
};
template <typename T>
//inicio  /declaracao do algoritmo de lista - classe lista
class AlgLista{    
	//metodos da classe lista
    public:                                   
        AlgLista(int cap);                    
        ~AlgLista();                          
        int ValorAlgLista();    
		int posPosterior();                       
        int posAnterior();      		
        int BuscaAlgLista( T dadoValorAlgLista);           
        int procuraTemplateAlgLista( T dadoValorAlgLista); 
        int PrintAlgLista(int directionAlgLista);          
        int RemoveValorAlgLista( T  dadoValorAlgLista);       
        int RemoveInicioAlgLista();               
        int RemoveFimAlgLista();                  
        int BuscaEstAlgLista();                   
		void AdicionaAlgListaInicio( T dadoValorAlgLista, class unitMem<T> * baseAlgLista);   
        void AdicionaAlgListaFim(  T dadoValorAlgLista, class unitMem<T> * baseAlgLista);     
        void AddOrdenadoAlgLista(  T dadoValorAlgLista, class unitMem<T> * baseAlgLista, int custoParcAlgLista, int princTemplate);      
                
		void BuscaInicAlgLista();
        int totAlgLista();
    protected:                                    
         class unitMem<T> *apontaBuscaAlgLista;    
		class unitMem<T> *histAlgLista;           
        class unitMem<T> *startAlgLista ;         
        class unitMem<T> *endAlgLista ;           
       
        int totTemplate;                         

};

//Metodos contrutor da classe lista
template <typename T>
AlgLista<T>::AlgLista(int cap){
    totTemplate=0;
    startAlgLista=NULL;
    endAlgLista=NULL;
    histAlgLista=startAlgLista;
};

//Metodos destrutor da classe lista
template <typename T>
AlgLista<T>::~AlgLista(){
    unitMem<T> *nodeAlgLista;
    while (startAlgLista!=NULL){
        nodeAlgLista=startAlgLista->posPosterior;
        freeMemAlgLista(startAlgLista);
        startAlgLista=nodeAlgLista;
    }
}

//metodo para start na lista
template <typename T>
void AlgLista<T>::BuscaInicAlgLista(){
    histAlgLista=startAlgLista;
};

//metodo para ttoalizacao da lista
template <typename T>
int AlgLista<T>::totAlgLista(){
    return totTemplate;
};

//metodo para mostrar o que ha presente no contTemplate - presente na lista
template <typename T>
int AlgLista<T>::ValorAlgLista(){
    if ( totTemplate > 0 ){
        return (histAlgLista->ContTemplate);
    }
}

//metodo para buscar valores na lista
template <typename T>
int AlgLista<T>::BuscaAlgLista( T dadoValorAlgLista){
    int nextAlgLista=1;
    int localizaAlgLista=0;
    int ChecaVlrAlgLista;
    if ( totTemplate > 0 ){
        histAlgLista=startAlgLista;
        while (nextAlgLista) 
		{
            ChecaVlrAlgLista=histAlgLista->ContTemplate;
            if (ChecaVlrAlgLista==dadoValorAlgLista)
			{
                localizaAlgLista++;
                if (localizaAlgLista==1)
				{
					return localizaAlgLista;
                }
            }
            nextAlgLista=posPosterior();
        }
    }
    return localizaAlgLista;
}


//metodo para buscar valores na lista e numero interacoes na lista
template <typename T>
int AlgLista<T>::procuraTemplateAlgLista( T dadoValorAlgLista){
    int nextAlgLista=1;
    int localizaAlgLista=0;
    int ChecaVlrAlgLista;
    if ( totTemplate > 0 ){
        apontaBuscaAlgLista=startAlgLista;
        while (nextAlgLista) {
            ChecaVlrAlgLista=apontaBuscaAlgLista->ContTemplate;
            if (ChecaVlrAlgLista==dadoValorAlgLista){
                localizaAlgLista++;
                if (localizaAlgLista==1){
                }
            }
            if (apontaBuscaAlgLista->posPosterior==NULL){
                nextAlgLista=0;
            }else{
                apontaBuscaAlgLista=apontaBuscaAlgLista->posPosterior;
            }
        }
    }
    return localizaAlgLista;
}

//metodo para listar inciio - valores na lista
template <typename T>
void AlgLista<T>::AdicionaAlgListaInicio(T dadoValorAlgLista, class unitMem<T> * baseAlgLista){
    unitMem<T> *nodeAlgLista=new unitMem<T> ;
    nodeAlgLista->posAnterior=NULL;
    nodeAlgLista->posPosterior=startAlgLista;
    nodeAlgLista->ContTemplate=dadoValorAlgLista;
    nodeAlgLista->posElo=baseAlgLista;
    nodeAlgLista->statusTemplate=0;
    if (totTemplate>0)
	{
        startAlgLista->posAnterior=nodeAlgLista;
    }else
	{
        endAlgLista=nodeAlgLista;
    }
    startAlgLista=nodeAlgLista;
    histAlgLista=startAlgLista;
    totTemplate++;
    return;
}

//metodo para demosntrar dados da lista
template <typename T>
int AlgLista<T>::PrintAlgLista(int directionAlgLista){
    int nextAlgLista=1;
    int dadoValorAlgLista;
    if ( totTemplate > 0 ){
        if (directionAlgLista==1){
            histAlgLista=startAlgLista;
        } else{
            histAlgLista=endAlgLista;
        }
        printf ( "\nExistem %d elementos da lista AlgLista:|",totTemplate);
        while (nextAlgLista) {
            dadoValorAlgLista=ValorAlgLista();
            printf ( "%d|", dadoValorAlgLista);
            if (directionAlgLista ==1){
                nextAlgLista=posPosterior();
            }else{
                nextAlgLista=posAnterior();
            }
        }
        printf ( "\n");
    }else{
        printf ("\nA LISTA SEM DADOS - VAZIA ");
    }

}

//metodo para adicionar no fim da lista
template <typename T>
void AlgLista<T>::AdicionaAlgListaFim( T dadoValorAlgLista, class unitMem<T> * baseAlgLista){
    unitMem<T> *nodeAlgLista=new unitMem<T> ;
    nodeAlgLista->posAnterior=endAlgLista;
    nodeAlgLista->posPosterior=NULL;
    nodeAlgLista->ContTemplate=dadoValorAlgLista;
    nodeAlgLista->posElo=baseAlgLista;
    nodeAlgLista->statusTemplate=0;
    if (totTemplate>0){
        endAlgLista->posPosterior=nodeAlgLista;
    }else{
        startAlgLista=nodeAlgLista;
    }
    endAlgLista=nodeAlgLista;
    histAlgLista=endAlgLista;
    totTemplate++;
    return;
}


//metodo para remover no inicio da lista
template <typename T>
int AlgLista<T>::RemoveInicioAlgLista(){
    unitMem<T> *nodeAlgListaVerificar;
    unitMem<T> *nodeAlgListaTmpposPosterior;
    if (totTemplate>0){
        nodeAlgListaVerificar=startAlgLista;
        if(nodeAlgListaVerificar->posPosterior==NULL){
            startAlgLista=NULL;
            endAlgLista=NULL;
        }else{
            nodeAlgListaTmpposPosterior=nodeAlgListaVerificar->posPosterior;
            startAlgLista=nodeAlgListaTmpposPosterior;
            nodeAlgListaTmpposPosterior->posAnterior=NULL;
        }
        delete nodeAlgListaVerificar;
        totTemplate--;
        return 1;
    }else{
        return 0;
    }
}

//metodo para remover no fim  da lista
template <typename T>
int AlgLista<T>::RemoveFimAlgLista(){
    unitMem<T> *nodeAlgListaVerificar;
    unitMem<T> *nodeAlgListaTmpposAnterior;
    if (totTemplate>0){
        nodeAlgListaVerificar=endAlgLista;
        if(nodeAlgListaVerificar->posAnterior==NULL)
		{
            startAlgLista=NULL;
            endAlgLista=NULL;
        }else{
            nodeAlgListaTmpposAnterior=nodeAlgListaVerificar->posAnterior;
            endAlgLista=nodeAlgListaTmpposAnterior;
            nodeAlgListaTmpposAnterior->posPosterior=NULL;
        }
        delete nodeAlgListaVerificar;
        totTemplate--;
        return 1;
    }else{
        return 0;
    }
}

//metodo para ordenar de forma crescente na lista 
template <typename T>
void AlgLista<T>::AddOrdenadoAlgLista(  T dadoValorAlgLista, class unitMem<T> * baseAlgLista, int custoParcAlgLista, int princTemplate){
    int i, j;
    T chaveAlgLista;
    unitMem<T> *nodeAlgLista=new unitMem<T> ;
    nodeAlgLista->ContTemplate=dadoValorAlgLista;
    nodeAlgLista->posElo=baseAlgLista;
    nodeAlgLista->custoTemplate=custoParcAlgLista;
    nodeAlgLista->princTemplate=princTemplate;
    nodeAlgLista->statusTemplate=0;
    if (totTemplate>0){
        histAlgLista=startAlgLista;
        while (1){
            chaveAlgLista=histAlgLista->princTemplate;
            if (chaveAlgLista >princTemplate){
                    nodeAlgLista->posPosterior=histAlgLista;
                    if (histAlgLista->posAnterior==NULL)
					{
                        nodeAlgLista->posAnterior=NULL;
                        startAlgLista=nodeAlgLista;
                    }else{
                        histAlgLista->posAnterior->posPosterior=nodeAlgLista;
                        nodeAlgLista->posAnterior=histAlgLista->posAnterior;
                    }
                    histAlgLista->posAnterior=nodeAlgLista;
                    histAlgLista=startAlgLista;
                    totTemplate++;
                    return;
            }
            if(!(posPosterior())){break;}
        }

        nodeAlgLista->posAnterior=endAlgLista;
        nodeAlgLista->posPosterior=NULL;
        endAlgLista->posPosterior=nodeAlgLista;
        endAlgLista=nodeAlgLista;

    }else{
        nodeAlgLista->posAnterior=NULL;
        nodeAlgLista->posPosterior=startAlgLista;
        startAlgLista=nodeAlgLista;
        endAlgLista=nodeAlgLista;
    }
    histAlgLista=startAlgLista;
    totTemplate++;
    return;
}


//metodo para remover da lista  e mostrar quantidade de dados na lista
template <typename T>
int AlgLista<T>::RemoveValorAlgLista( T dadoValorAlgLista){
    int excluidosAlgLista=0;
    unitMem<T> *nodeAlgListaVerificar;
    unitMem<T> *nodeAlgListaTmpposAnterior;
    unitMem<T> *nodeAlgListaTmpposPosterior;
    nodeAlgListaVerificar=startAlgLista;
    while (1){
        nodeAlgListaTmpposPosterior=nodeAlgListaVerificar->posPosterior;
        if (nodeAlgListaVerificar->ContTemplate==dadoValorAlgLista){
                if (nodeAlgListaVerificar->posAnterior==NULL){
                    if(nodeAlgListaVerificar->posPosterior==NULL){
                            startAlgLista=NULL;
                            endAlgLista=NULL;
                    }else{
                        startAlgLista=nodeAlgListaTmpposPosterior;
                        if (nodeAlgListaTmpposPosterior != NULL){
                            nodeAlgListaTmpposPosterior->posAnterior=NULL;
                        }
                    }
                }else if (nodeAlgListaVerificar->posPosterior==NULL){
                    if(nodeAlgListaVerificar->posAnterior==NULL){
                            startAlgLista=NULL;
                            endAlgLista=NULL;
                    }else{
                        nodeAlgListaTmpposAnterior=nodeAlgListaVerificar->posAnterior;
                        endAlgLista=nodeAlgListaTmpposAnterior;
                        if (nodeAlgListaTmpposAnterior != NULL){
                            nodeAlgListaTmpposAnterior->posPosterior=NULL;
                        }
                    }
                }else{
                    nodeAlgListaTmpposAnterior=nodeAlgListaVerificar->posAnterior;
                    nodeAlgListaTmpposAnterior->posPosterior=nodeAlgListaTmpposPosterior;
                    if (nodeAlgListaTmpposPosterior != NULL){
                        nodeAlgListaTmpposPosterior->posAnterior=nodeAlgListaTmpposAnterior;
                    }
                }
                delete nodeAlgListaVerificar;
                totTemplate--;
                excluidosAlgLista++;
        }
        if(nodeAlgListaTmpposPosterior == NULL){break;}
        nodeAlgListaVerificar=nodeAlgListaTmpposPosterior;
    }
    return excluidosAlgLista;

}


//metodo para busca  na lista  e checagem se esta vazia ou nao 
template <typename T>
int AlgLista<T>::BuscaEstAlgLista(){
    if (totTemplate==0) {
        return 0; 
    }
    return 1; 
}

//metodo para checar ponto posterior e consequentemente ser usado na busca do PUZZLE
template <typename T>
int AlgLista<T>::posPosterior(){
    if (histAlgLista->posPosterior==NULL){
//            printf("\n NAO");
            return 0;
    }else{
        histAlgLista=histAlgLista->posPosterior;
//        printf("\n SIM");
        return 1;
    }
}

//metodo para checar ponto ANTERIOR e consequentemente ser usado na busca do PUZZLE
template <typename T>
int AlgLista<T>::posAnterior(){
    if (histAlgLista->posAnterior==NULL){
            return 0;
    }else{
        histAlgLista=histAlgLista->posAnterior;
        return 1;
    }
}

//Abaixo algoritomo de pilha e fila sendo reusados atraves de heranca / hierarquia de classes
template <typename T>
class AlgFila : public AlgLista<T>{             // begin declaration of the class;
    public:                            // begin public section
        AlgFila(int direct);              // constructor
        ~AlgFila();                       // destructor
        T* CapturaSaidaAlgFila();               // accessor function
        void AdicionaAlgFila(T dadoValorAlgLista, class unitMem<T> * baseAlgLista);  // accessor function
        int RemoveAlgFila();              // accessor function
        void PrintAlgFila();              // accessor function
    private:                           // begin private section
        int directionAlgLista;                 // member variable
};
//metodo construtor da fila
template <typename T>
AlgFila<T>::AlgFila(int direct):
    AlgLista<T>::AlgLista (1)
{
    directionAlgLista=direct;
};
//metodo destrutor da fila
template <typename T>
AlgFila<T>::~AlgFila(){
    AlgLista<T>::~AlgLista();
    printf("\n\n");
};

//mostra a sauda da fila - seus valores 
template <typename T>
T* AlgFila<T>::CapturaSaidaAlgFila(){
    this->histAlgLista=this->startAlgLista;
    if ( this->totTemplate > 0 ){
        try{
            return this->ValorAlgLista();
        }
        catch (int errorShow) { cout << "*******Exception variavel int********"; }
        catch (char errorShow) { cout << "*******Exception variavel char********"; }
    }
};

//metodo adiciona valores na fila
template <typename T>
void AlgFila<T>::AdicionaAlgFila(T dadoValorAlgLista, class unitMem<T> * baseAlgLista){
    try{
        this->AdicionaAlgListaFim(dadoValorAlgLista, baseAlgLista);
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

//metodo remove valores da  fila
template <typename T>
int AlgFila<T>::RemoveAlgFila(){
    try{
        return this->RemoveInicioAlgLista();
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

//metodo mostra valores da  fila
template <typename T>
void AlgFila<T>::PrintAlgFila(){
    try{
        this->PrintAlgLista(directionAlgLista);
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};


//Abaixo algoritomo de pilha e fila sendo reusados atraves de heranca / hierarquia de classes
template <typename T>
class AlgPilha : public AlgLista<T>{        
    public:                                 
        AlgPilha(int direct);               
        ~AlgPilha();                        
        T* PegaTopoAlgPilha();              
        void AdicionaAlgPilha(  T dadoValorAlgLista, class unitMem<T> * baseAlgLista);  
        int RemoveAlgPilha();              
        void PrintAlgPilha();              
    private:                               
        int directionAlgLista;             
};
//metodo construtor da pilha 
template <typename T>
AlgPilha<T>::AlgPilha(int direct):
    AlgLista<T>::AlgLista(1)
{
    directionAlgLista=direct;
};
//metodo destrutor da pilha 
template <typename T>
AlgPilha<T>::~AlgPilha(){
    AlgLista<T>::~AlgLista();
    printf("\n\n");
};

//metodo para buscar topo da pilha 
template <typename T>
T* AlgPilha<T>::PegaTopoAlgPilha(){
    this->histAlgLista=this->startAlgLista;
    if ( this->totTemplate > 0 ){
        try{
            return this->ValorAlgLista();
        }
        catch (int errorShow) { cout << "*******Exception variavel int********"; }
        catch (char errorShow) { cout << "*******Exception variavel char********"; }
    }
};

//metodo apra adicionar no topo da pilha 
template <typename T>
void AlgPilha<T>::AdicionaAlgPilha( T dadoValorAlgLista, class unitMem<T> * baseAlgLista){
    try{
        this->AdicionaAlgListaInicio(dadoValorAlgLista, baseAlgLista);
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

//metodo remover do topo da pilha 
template <typename T>
int AlgPilha<T>::RemoveAlgPilha(){
    try{
        return this->RemoveInicioAlgLista();
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

//metodo mostrar dados da pilha 
template <typename T>
void AlgPilha<T>::PrintAlgPilha(){
    try{
        this->PrintAlgLista(directionAlgLista);
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

