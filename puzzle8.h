//importação das bibliotecas que serao usadas no programa

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#include "dados_puzzle.h"
#include <iostream>

using namespace std;

//  PROGRAMA POSUI CARACTERISTICAS EXIGIDAS: 
//- TEMPLATES
//- HIERARQUIAS DE CLASSES DE OBJETOS
//- POLIMORFISMO
//- TRATAMENTO DE EXCECOES

//PuzzleControlador fazendo hierarquia e polimorfismo da classe LISTA  - BUSCA EM LARGURA E PROFUNDIDADE
template <typename T>
class PuzzleControlador: public AlgLista<T>{                                      
    public:                                                         
		//declaração da classe Puzzle Controlador de modo public e os metodos dessa classe
        PuzzleControlador(int BuscaInicAlgLista);                                         
        ~PuzzleControlador();                                                  
		//Ações: 0 - direita,  1 - esquerda , 2 - para baixo , 3 - para cima
        int P(T dadoValorAlgLista, int actionAux);                                      
		//A funcao Objetivo_Puzzle vai guardar o objetivo final 
		int Objetivo_Puzzle(T dadoValorAlgLista, int statusFinal);                       
         
        //metodo para mostrar vertices
		void MostraVert();                                      
        //metodo para mostrar caminhos
		void MostraCaminho();                                   
        class unitMem<T> *Auxiliar;        
		
		int AcessaVert();                                          
        void InsereVert(T dadoValorAlgLista, class unitMem<T> * baseAlgLista); 		
		
		virtual void expade_node (int PontoStart){printf("\n SEM NOS PARA ABRIR");};
        virtual int equac_Heuristica (T dadoValorAlgLista, int custoTemplate, int custoParcAlgLista){printf("\n SEM NOS PARA ABRIR");};
	//declaracao de metodos protected
    protected:                                                  
        int directionAlgLista;                                  
        int statusFinal;                                        
        int custoParcAlgLista;
};

//Metodo construtor ativando o que sera feito atraves do ponto inicial
template <typename T>
PuzzleControlador<T>::PuzzleControlador(int BuscaInicAlgLista):
    AlgLista<T>::AlgLista(1)
{	//controlador de abertura dos vertices
    int aberturaVert=0;                                                 
    //controlador de custo de caminho das buscas
	int custoParcAlgLista=0;                                                    
    //objetivo esperado 
	statusFinal = 123456789;                                           
    directionAlgLista=1;
};

//Metodo destrutor liberando memoria
template <typename T>
PuzzleControlador<T>::~PuzzleControlador(){printf("\n");}

//Usando buscador de topo de pilha, atraves da herança da classe de pilha
template <typename T>
int PuzzleControlador<T>::AcessaVert(){
    printf("\n Acessando vertice do topo da pilha");
};

//Metodo que vai checar se o valor preenchido em Objetivo_Puzzle esta presente na busca
template <typename T>
int PuzzleControlador<T>::Objetivo_Puzzle(T dadoValorAlgLista, int statusFinal){
    if (dadoValorAlgLista==statusFinal){return 1;}else{return 0;}
};

//Usando metodo de adicionar pilha, atraves de heranca da classe pilha - ou seja pilha adiciona no topo
template <typename T>
void PuzzleControlador<T>::InsereVert(T dadoValorAlgLista, class unitMem<T> * baseAlgLista){
    printf("\nADD Vertice");};

//Usando metodo de mostrar dados da pilha , atraves de heranca da classe pilha - mostraVert
template <typename T>
void PuzzleControlador<T>::MostraVert(){
    try{this->PrintAlgLista(directionAlgLista);}
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }};

// Metodo para demonstrar todo o caminho para o objetivo ser alcançado 
template <typename T>
void PuzzleControlador<T>::MostraCaminho(){
	//mostra o vertice que posterior
    int nextAlgLista=1;                                                         
	//mostra o objetivo final do caminho
    int caminhoObjetivo=0;                                                       
    //Acionamento do metodo para mostar caminho atraves do MostraCaminhoPilha - demonstra o resultado final
	AlgPilha<T> MostraCaminhoPilha(1);                                            
    printf ( "\n  O CAMINHO PARA RESOLUACAO FOI: ");
    //Checando quantos vertices foram necessarios para conseguir chegar ao objetivo
	if ( this->totTemplate > 0 ){                                        
        while (nextAlgLista) {
            MostraCaminhoPilha.AdicionaAlgPilha(this->histAlgLista->ContTemplate, NULL);
            caminhoObjetivo++;
			if (this->histAlgLista->posElo!=NULL){this->histAlgLista=this->histAlgLista->posElo;}
			else{nextAlgLista=0;}}
		//SPOLL demonstrando o caminho usado para solucionar o problema
        printf ( "| %d O CAMINHO PARA O OBJETO FINAL FOI :\n", caminhoObjetivo);
        getch();
        MostraCaminhoPilha.PrintAlgPilha();
    }else{printf ("\nFINAL");}};

//Funcao para mostrar quais os movimentos dos estados do controlador
template <typename T>
int PuzzleControlador<T>::P(T dadoValorAlgLista, int actionAux){
    char vetorMov[10];
    char saveMov;
    int dimensaoMov=3;
    int localMov, sobLocalMov;
    sprintf(vetorMov,"%d",dadoValorAlgLista);
    for (localMov=0;localMov<=8;localMov++){
        if(vetorMov[localMov]=='9'){break;}    
		}
    switch (actionAux){
        //tentativa de mover o vazio para a direita
		case 0: 
            sobLocalMov=localMov+1;
            if (sobLocalMov%dimensaoMov!=0){
                saveMov=vetorMov[localMov];
                vetorMov[localMov]=vetorMov[sobLocalMov];
                vetorMov[sobLocalMov]=saveMov;
            }else{ sprintf(vetorMov,"%d",0);}
            break;
        //tentativa de mover o vazio para a esquerda
		case 1: 
            sobLocalMov=localMov-1;
            if ((localMov)%dimensaoMov!=0){
                saveMov=vetorMov[localMov];
                vetorMov[localMov]=vetorMov[sobLocalMov];
                vetorMov[sobLocalMov]=saveMov;
            }else{ sprintf(vetorMov,"%d",0);}
            break;
        //tentativa de mover o vazio para baixo
		case 2: 
            sobLocalMov=localMov+3;
            if (localMov<((dimensaoMov*dimensaoMov)-dimensaoMov)){
                saveMov=vetorMov[localMov];
                vetorMov[localMov]=vetorMov[sobLocalMov];
                vetorMov[sobLocalMov]=saveMov;
            }else{ sprintf(vetorMov,"%d",0);}
            break;
        //tentativa de mover o vazio para cima
		case 3:
            sobLocalMov=localMov-3;
            if (((localMov+1)-dimensaoMov)>0){
                saveMov=vetorMov[localMov];
                vetorMov[localMov]=vetorMov[(localMov-3)];
                vetorMov[(localMov-3)]=saveMov;
            }else{ sprintf(vetorMov,"%d",0);}
            break;
        default:
            sprintf(vetorMov,"%d",0);
    }sscanf(vetorMov, "%d", &dadoValorAlgLista);return dadoValorAlgLista;
}

//Objeto PuzzleControlador para BUSCA EM PROFUNDIDADE
template <typename T>
//Declaracao de classe P_dfs 
class P_dfs: public PuzzleControlador<T> {                                        
      public:
        //Metodos usados para Busca em Profundidade 
		P_dfs(int objetivo):PuzzleControlador<T>(objetivo){};                     
        int AcessaVert();                                              
        void InsereVert(T dadoValorAlgLista, class unitMem<T> * baseAlgLista);    
        virtual void expade_node (int PontoStart);
};

//Metodo adiciona da Pilha atraves da herança do metodo da classe pilha-adiciona no topo da pilha
template <typename T>
void P_dfs<T>::InsereVert(T dadoValorAlgLista, class unitMem<T> * baseAlgLista){
    try{this->AdicionaAlgListaInicio(dadoValorAlgLista, baseAlgLista);}
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

//Metodo para buscar valor do topo da pilha 
template <typename T>
int P_dfs<T>::AcessaVert(){this->histAlgLista=this->startAlgLista;
    if ( this->totTemplate > 0 ){
        try{return this->ValorAlgLista();}
        catch (int errorShow) { cout << "*******Exception variavel int********"; }
        catch (char errorShow) { cout << "*******Exception variavel char********"; }
    }
};

// Metodo para expandir os nos e consequentemente localizando os caminhos possiveis
template <typename T>
void P_dfs<T>::expade_node(int PontoStart){
	
	//Controlando as acoes / vertices novos
    int actionAux;
    int nextAlgLista=1;                                          
    int aberturaVert=0;                                          
    int dadoValorAlgLista=0;                                     
    //inserindo nos vertices atraves do ponto inicial
	try{InsereVert(PontoStart, NULL);}
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
	
	//Auxilia demonstrando o historico/ elos de controle do DFS
	this->Auxiliar=this->histAlgLista;                                     

    while (nextAlgLista){
        if(this->Auxiliar->statusTemplate==0){
                this->Auxiliar->statusTemplate=1;}
        aberturaVert=0;

		//Acoes conforme declaracao acima :  0 - direita,  1 - esquerda , 2 - para baixo , 3 - para cima
        for (actionAux=0;actionAux<4;actionAux++){
			// quando interagir por ultimo é feito a demarcacao que esse vertice esta inacessivel = 2
            if (actionAux==3){                                      
                this->Auxiliar->statusTemplate=2;}

		//conforme a demarcacao do vertice é feito a acao e retorna o valor e a aca
		//se valor é 0 a ação não muda o ambiente
            try{dadoValorAlgLista=this->P(this->Auxiliar->ContTemplate,actionAux);}
            catch (int errorShow) { cout << "*******Exception variavel int********"; }
            catch (char errorShow) { cout << "*******Exception variavel char********"; }

			//Fara a veriicacao se o nó abaixo desse ja foi checado
            if (dadoValorAlgLista>0){
                if (this->procuraTemplateAlgLista(dadoValorAlgLista)==0){                 
                    //Faz a insercao de vertice atraves de herança , chamado o metodo referente a essa acao
					try{InsereVert(dadoValorAlgLista, this->Auxiliar); }
                    catch (int errorShow) { cout << "*******Exception variavel int********"; }
                    catch (char errorShow) { cout << "*******Exception variavel char********"; }

                    if(this->totTemplate%100==0){
                        printf(".");
                    }
                    aberturaVert++;
					//Verifica se o objetivo foi obtido
					try{
                        if (this->Objetivo_Puzzle(dadoValorAlgLista,this->statusFinal)){
                            aberturaVert=-1;break;}                                             
                    }
                    catch (int errorShow) { cout << "*******Exception variavel int********"; }
                    catch (char errorShow) { cout << "*******Exception variavel char********"; }
                    break;
                }
            }

        }
        //setando variaveis conforme expansoes forem sendo localizadas pelo loop 
		nextAlgLista=aberturaVert;                                     
        // caso objetivo seja alcançado , break
		if(nextAlgLista==-1){break;}                                   
		//se nao houve expansao de nos  segue para proximo if
        if (nextAlgLista==0){                                          
            if (this->Auxiliar->posElo!=NULL){
                // Direciona o marcador para o inicio/ raiz buscado 
				this->histAlgLista=this->Auxiliar->posElo;             
                nextAlgLista=1;
                //ENquanto o inicio /raiz estiver  movimenta para o nó explorado e assim renovando as buscas
				while (this->histAlgLista->statusTemplate==2){           
                    try{if(!(this->posPosterior())){break;}}
                    catch (int errorShow) { cout << "*******Exception variavel int********"; }
                    catch (char errorShow) { cout << "*******Exception variavel char********"; }
                }
                this->Auxiliar=this->histAlgLista;
            }
        }else{this->Auxiliar=this->startAlgLista;}
    }
    printf("\n DEMONSTRACAO DE TOTAL DE VERTICES/NÓS CHECADOS %d", this->totTemplate);
	//Demonstra o caminho total
    try{this->MostraCaminho();
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
}

//Declaracao de classe para busac em Largura
template <typename T>
class P_bfs: public PuzzleControlador<T> {                                     
    //metodos publicos
	public:                                                     
        P_bfs(int objetivo):PuzzleControlador<T>(objetivo){};                               
        int AcessaVert();                                      
        void InsereVert(T dadoValorAlgLista, class unitMem<T> * baseAlgLista);      
        virtual void expade_node (int PontoStart);
};

//Acionamento do metodo de adicionar na pilha - herança da classe pilha - Insere topo
template <typename T>
void P_bfs<T>::InsereVert(T dadoValorAlgLista, class unitMem<T> * baseAlgLista){
    try{this->AdicionaAlgListaFim(dadoValorAlgLista, baseAlgLista);}
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

//Acionamento do metodo de capturar o topo pilha - herança da classe pilha
template <typename T>
int P_bfs<T>::AcessaVert(){
    this->histAlgLista=this->endAlgLista;
    if ( this->totTemplate > 0 ){
        try{return this->ValorAlgLista();}
        catch (int errorShow) { cout << "*******Exception variavel int********"; }
        catch (char errorShow) { cout << "*******Exception variavel char********"; }
    }
};

//metodo para expandir os nos do grafo
template <typename T>
void P_bfs<T>::expade_node(int PontoStart){
    int actionAux;
    int nextAlgLista=1;
    int dadoValorAlgLista=0;
    int goal=0;
    //Acinamento do metodo de inserção no vertice/grafo
	try{InsereVert(PontoStart, NULL);}
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
    //Inserindo
	this->Auxiliar=this->histAlgLista;                                         
    while (nextAlgLista>0){
        this->Auxiliar->statusTemplate=1;
        nextAlgLista=0;
		//fazendo loop conforme quantidade de possibilidades de cada posicionamento
        for (actionAux=0;actionAux<4;actionAux++){
            dadoValorAlgLista=this->P(this->Auxiliar->ContTemplate,actionAux);
            if (dadoValorAlgLista==0){
				
            }
            if (dadoValorAlgLista>0){
                // insercao no vertice / grafo
				if (this->BuscaAlgLista(dadoValorAlgLista)==0){
                    InsereVert(dadoValorAlgLista, this->Auxiliar);                 
                    //Checagem se o objetivo foi alcançado
					if (this->Objetivo_Puzzle(dadoValorAlgLista,this->statusFinal)){         
                        goal=1;
                        break;
                    }
                    if(this->totTemplate%100==0){printf(".");}
                    nextAlgLista++;
                }
            }
        }
        if(goal==1){break;}
        this->histAlgLista=this->Auxiliar;
        //retirada do vertice caso objetivo nao alcançado
		if(this->posPosterior()){    
            this->Auxiliar=this->histAlgLista;
            nextAlgLista=1;
        }else{break;}
    }

    printf("\n DEMONSTRACAO DE TOTAL DE VERTICES/NÓS CHECADOS  %d", this->totTemplate);
	//acionameto do metodo de 
    try{this->MostraCaminho();}
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
}


//PuzzleControlador fazendo hierarquia e polimorfismo da classe LISTA  - Busca de Encosta
template <typename T>
//declaracao da classe para Busca de Encosta
class P_encosta: public PuzzleControlador<T> {                                       
      //metodos publicos
	  public:
        P_encosta(int objetivo):PuzzleControlador<T>(objetivo){};                     
        int AcessaVert();                                              
        void InsereVert( T dadoValorAlgLista, class unitMem<T> * baseAlgLista, int custoParcAlgLista, int princTemplate);       
        virtual void expade_node (int PontoStart);
        virtual int equac_Heuristica (T dadoValorAlgLista, int custoTemplate, int custoParcAlgLista);
};

//Usando metodo de adicionar pilha, atraves de heranca da classe pilha - ou seja pilha adiciona no topo
template <typename T>
void P_encosta<T>::InsereVert( T dadoValorAlgLista, class unitMem<T> * baseAlgLista, int custoParcAlgLista, int princTemplate){
    try{
        this->AddOrdenadoAlgLista(dadoValorAlgLista, baseAlgLista, custoParcAlgLista, princTemplate);
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

//Usando metodo de acessar topo da pilha, atraves de heranca da classe pilha - ou seja pilha busca topo
template <typename T>
int P_encosta<T>::AcessaVert(){
    this->histAlgLista=this->endAlgLista;
    if ( this->totTemplate > 0 ){
        try{return this->ValorAlgLista();}
        catch (int errorShow) { cout << "*******Exception variavel int********"; }
        catch (char errorShow) { cout << "*******Exception variavel char********"; }
    }
};

//abrindo todos os nos do grafo de modo que seja feito a busca de Encosta
template <typename T>
//buscando atraves do ponto inicial
void P_encosta<T>::expade_node(int PontoStart){
    int actionAux;
    int nextAlgLista=1;
    int dadoValorAlgLista=0;
    int goal=0;
    //comeca a busca pelo ponto inicial
	try{this->AddOrdenadoAlgLista(PontoStart, NULL,0,equac_Heuristica(PontoStart,0,1));     }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
    //Auxiliar para ter a base para busca
	this->Auxiliar=this->histAlgLista;                                         
    while (nextAlgLista>0){
        this->Auxiliar->statusTemplate=1;
        nextAlgLista=0;
        //checa se objetio final foi alcançado
		if (this->Objetivo_Puzzle(this->Auxiliar->ContTemplate,this->statusFinal)){         
                goal=1;
                break;}
		//faz a checagem atraves das possibilidades de movimentação que existem
        for (actionAux=0;actionAux<4;actionAux++){
            dadoValorAlgLista=this->P(this->Auxiliar->ContTemplate,actionAux);
            if (dadoValorAlgLista==0){
            }
            if (dadoValorAlgLista>0){
                if (this->procuraTemplateAlgLista(dadoValorAlgLista)==0){
                    this->AddOrdenadoAlgLista(dadoValorAlgLista,
					this->Auxiliar,
					(this->Auxiliar->custoTemplate+1),
					equac_Heuristica(dadoValorAlgLista,
					this->Auxiliar->custoTemplate,1));
                    if(this->totTemplate%100==0){
                        printf(".");
                    }
                    nextAlgLista++;
                }
            }
        }
        //remocao atraves do uso da remocao da pilha 
		if(nextAlgLista==0){    
            if(this->posPosterior()){
                    nextAlgLista=1;
                    this->Auxiliar=this->histAlgLista;}
        }else{this->Auxiliar=this->histAlgLista;}
    }

    printf("\n n DEMONSTRACAO DE TOTAL DE VERTICES/NÓS CHECADOS  %d", this->totTemplate);
	//acionameto do metodo de demosntracao dos passos feitos
    try{this->MostraCaminho();    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
}

//Feita a abertura dos nos dos vertices/grafo
template <typename T>
int P_encosta<T>::equac_Heuristica(T dadoValorAlgLista, int custoTemplate, int custoParcAlgLista){
    int heur_inic=0;
    int heur_final=0;
    
    int localMov, Eq_Function, Eq_CustoTot, Eq_ManhattanHeuN;
    char vetorMov[10];
    char strEq_Manhattan[10];

	Eq_CustoTot=custoTemplate;
	int Eq_Manhattan=0;
    int Eq_ManhattanReal=0;
    int Eq_ManhattanFinal=0;
	
    sprintf(vetorMov,"%d",dadoValorAlgLista);
    sprintf(strEq_Manhattan,"%d",this->statusFinal);

    for (localMov=0;localMov<=8;localMov++){
        if(vetorMov[localMov]!=strEq_Manhattan[localMov]&&vetorMov[localMov]!='9'){
            dadoValorAlgLista = (int)vetorMov[localMov] - 48;
            Eq_ManhattanFinal=(dadoValorAlgLista-1)/3;
            Eq_ManhattanReal=localMov/3;
            heur_final=abs(((Eq_ManhattanReal-Eq_ManhattanFinal)*3+dadoValorAlgLista)-(localMov+1))+abs((Eq_ManhattanReal-Eq_ManhattanFinal));
            Eq_Manhattan=Eq_Manhattan+heur_final;
            heur_inic++;
        }
    }
    Eq_ManhattanHeuN= Eq_Manhattan;
    Eq_Function = Eq_CustoTot+ custoParcAlgLista+ Eq_ManhattanHeuN;
    return Eq_Function;

}


//PuzzleControlador fazendo hierarquia e polimorfismo da classe LISTA  - Busca A* - A-Estrela
template <typename T>
//declaracao da classe para A - estrela
class P_astar: public PuzzleControlador<T> {                                       
      //metodos publicos
	  public:
        P_astar(int objetivo):PuzzleControlador<T>(objetivo){};                     
        int AcessaVert();                                              
        void InsereVert( T dadoValorAlgLista, class unitMem<T> * baseAlgLista, int custoParcAlgLista, int princTemplate);       
        virtual void expade_node (int PontoStart);
        virtual int equac_Heuristica (T dadoValorAlgLista, int custoTemplate, int custoParcAlgLista);
};

//Usando metodo de adicionar pilha, atraves de heranca da classe pilha - ou seja pilha adiciona no topo
template <typename T>
void P_astar<T>::InsereVert( T dadoValorAlgLista, class unitMem<T> * baseAlgLista, int custoParcAlgLista, int princTemplate){
    try{
        this->AddOrdenadoAlgLista(dadoValorAlgLista, baseAlgLista, custoParcAlgLista, princTemplate);
    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
};

//Usando metodo de acessar topo da pilha, atraves de heranca da classe pilha - ou seja pilha busca topo
template <typename T>
int P_astar<T>::AcessaVert(){
    this->histAlgLista=this->endAlgLista;
    if ( this->totTemplate > 0 ){
        try{return this->ValorAlgLista();}
        catch (int errorShow) { cout << "*******Exception variavel int********"; }
        catch (char errorShow) { cout << "*******Exception variavel char********"; }
    }
};

//abrindo todos os nos do grafo de modo que seja feito a busca A-Estrela
template <typename T>
//buscando atraves do ponto inicial
void P_astar<T>::expade_node(int PontoStart){
    int actionAux;
    int nextAlgLista=1;
    int dadoValorAlgLista=0;
    int goal=0;
    //comeca a busca pelo ponto inicial
	try{this->AddOrdenadoAlgLista(PontoStart, NULL,0,equac_Heuristica(PontoStart,0,1));     }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
    //Auxiliar para ter a base para busca
	this->Auxiliar=this->histAlgLista;                                         
    while (nextAlgLista>0){
        this->Auxiliar->statusTemplate=1;
        nextAlgLista=0;
        //checa se objetio final foi alcançado
		if (this->Objetivo_Puzzle(this->Auxiliar->ContTemplate,this->statusFinal)){         
                goal=1;
                break;}
		//faz a checagem atraves das possibilidades de movimentação que existem
        for (actionAux=0;actionAux<4;actionAux++){
            dadoValorAlgLista=this->P(this->Auxiliar->ContTemplate,actionAux);
            if (dadoValorAlgLista==0){
            }
            if (dadoValorAlgLista>0){
                if (this->procuraTemplateAlgLista(dadoValorAlgLista)==0){
                    this->AddOrdenadoAlgLista(dadoValorAlgLista,
					this->Auxiliar,
					(this->Auxiliar->custoTemplate+1),
					equac_Heuristica(dadoValorAlgLista,
					this->Auxiliar->custoTemplate,1));
                    if(this->totTemplate%100==0){
                        printf(".");
                    }
                    nextAlgLista++;
                }
            }
        }
        //remocao atraves do uso da remocao da pilha 
		if(nextAlgLista==0){    
            if(this->posPosterior()){
                    nextAlgLista=1;
                    this->Auxiliar=this->histAlgLista;}
        }else{this->Auxiliar=this->histAlgLista;}
    }

    printf("\n n DEMONSTRACAO DE TOTAL DE VERTICES/NÓS CHECADOS  %d", this->totTemplate);
	//acionameto do metodo de demosntracao dos passos feitos
    try{this->MostraCaminho();    }
    catch (int errorShow) { cout << "*******Exception variavel int********"; }
    catch (char errorShow) { cout << "*******Exception variavel char********"; }
}

//Feita a abertura dos nos dos vertices/grafo
template <typename T>
int P_astar<T>::equac_Heuristica(T dadoValorAlgLista, int custoTemplate, int custoParcAlgLista){
    int heur_inic=0;
    int heur_final=0;
    
    int localMov, Eq_Function, Eq_CustoTot, Eq_ManhattanHeuN;
    char vetorMov[10];
    char strEq_Manhattan[10];

	Eq_CustoTot=custoTemplate;
	int Eq_Manhattan=0;
    int Eq_ManhattanReal=0;
    int Eq_ManhattanFinal=0;
	
    sprintf(vetorMov,"%d",dadoValorAlgLista);
    sprintf(strEq_Manhattan,"%d",this->statusFinal);

    for (localMov=0;localMov<=8;localMov++){
        if(vetorMov[localMov]!=strEq_Manhattan[localMov]&&vetorMov[localMov]!='9'){
            dadoValorAlgLista = (int)vetorMov[localMov] - 48;
            Eq_ManhattanFinal=(dadoValorAlgLista-1)/3;
            Eq_ManhattanReal=localMov/3;
            heur_final=abs(((Eq_ManhattanReal-Eq_ManhattanFinal)*3+dadoValorAlgLista)-(localMov+1))+abs((Eq_ManhattanReal-Eq_ManhattanFinal));
            Eq_Manhattan=Eq_Manhattan+heur_final;
            heur_inic++;
        }
    }
    Eq_ManhattanHeuN= Eq_Manhattan;
    Eq_Function = Eq_CustoTot+ custoParcAlgLista+ Eq_ManhattanHeuN;
    return Eq_Function;

}

