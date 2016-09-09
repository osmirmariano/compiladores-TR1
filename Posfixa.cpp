#include <iostream>
#include <cstdlib>

using namespace std;
/*----------------------- DECLARAÇÃO DA ESTRUTURA-------------------------*/
typedef struct PILHA{
	string armazena;
    struct PILHA *prox;
}PILHA;

/*----------------------- DECLARAÇÃO DA CLASSE POSFIXA---------------------*/
class Posfixa{
	public:
        int opcao, opction;
	public:
        //CONSTRUTOR
		Posfixa(){
            void empilhar(PILHA **topo);
            void desempilhar(PILHA **topo);
            void listar(PILHA *topo);
		};
		~Posfixa();
        /*----------------------- FUNÇÃO EMPILHAR-----------------------------*/
        void empilhar(PILHA **topo, string recebe){
            cout << "OI 1" << endl;
            PILHA *novo;
            novo = (PILHA*) malloc (sizeof(PILHA));
            cout << "OI 1" << endl;
            if(novo != NULL){
                cout << "NOVO ANTES: " << novo->armazena << endl;
                novo->armazena = recebe;
                cout << "NOVO DEPOIS: " << novo->armazena << endl;
                if(*topo == NULL)
                    novo->prox = NULL;
                else
                    novo->prox = *topo;
                *topo = novo;
            }
        };

        /*----------------------- FUNÇÃO DESEMPILHAR-----------------------------*/
        void desempilhar(PILHA **topo){
            PILHA *aux;
            if(aux == NULL)
                cout << "NÃO EXISTE NENHUM ELEMENTO NA PILHA" << endl;
            else{
                aux = (*topo)->prox;
                delete *topo;
                *topo = aux;
                cout << "ITEM REMOVIDO COM SUCESSO" << endl;
            }
        };

        /*----------------------- FUNÇÃO LISTAR-------------------------------*/
        void listar(PILHA *topo){
            PILHA *aux;
            if(topo == NULL)
                cout << "PILHA VAZIA" << endl;
            else{
                aux = topo;
                while(aux != NULL){
                    cout << "EMPILHADO: " << aux->armazena << endl;
                    aux = aux->prox;
                }
           }
        };

        /*--------------------- FUNÇÃO PRECENDENCIA PILHA------------------------*/
        int precedenciasPilha(PILHA *topo){
            if(topo->armazena == "*")
                opction = 3;
            else if(topo->armazena == ".")
                opction = 2;
            else if(topo->armazena == "+")
                    opction = 1;
            else
                opction = 0;
            return opction;
        };

        /*--------------------- FUNÇÃO PRECENDENCIA EXPRESSAO-----------------------*/
        int precedenciasExpr(string expressao, int x){
            if(expressao[x] == '*')
                opcao = 3;
            else if(expressao[x] == '.')
                opcao = 2;
            else if(expressao[x] == '+')
                opcao = 1;
            return opcao;
        }

        /*-----------------------FUNÇÃO INFIXAPARAPOSFIXA---------------------*/
        void infixaParaPosfixa(string expressao){
            string posfixa, recebe;
            PILHA *topo = NULL;
            
            for(int x = 0; x < expressao.length(); x++){
                //Tratamento de ser "(" -> SITUAÇÃO OK
                cout << "TESTE 1: " << endl;
                if(expressao[x] == '('){
                    recebe =  expressao[x];
                    empilhar(&topo, recebe);//Empilhar tá OK
                    cout << "EMPILHADO: " << topo->armazena << endl;
                }

                else{
                    cout << "TESTE 2: " << endl;
                    if(expressao[x] == ')'){
                        while(topo->armazena != "("){
                            posfixa += topo->armazena;
                            cout << "POSFIXA: " << posfixa << endl;
                            desempilhar(&topo);//Desempilha
                        }
                        // if(topo->armazena == "("){
                        //     desempilhar(&topo);
                        // }
                    }

                    else{
                        cout << "TESTE 3: " << endl;
                        //Testes para as precedências
                        if(expressao[x] == '*' || expressao[x] == '.' || expressao[x] == '+') {
                            //Aqui os testes 
                            //Criei duas funções


                            if(topo == NULL){
                                recebe = expressao[x];
                                empilhar(&topo, recebe);
                                cout << "EMPILHADO: " << topo->armazena << endl;//DEIXAR PARA TESTE
                            }
                            else{
                                while(precedenciasPilha(topo) > precedenciasExpr(expressao, x)){
                                    posfixa += topo->armazena;
                                    desempilhar(&topo);
                                }
                                if(precedenciasPilha(topo) < precedenciasExpr(expressao, x)){
                                    recebe = expressao[x];
                                    empilhar(&topo, recebe);
                                    cout << "EMPILHADO: " << topo->armazena << endl;
                                }
                            }
                           
                        }
                        else{
                            posfixa += expressao[x];
                            cout << "POSFIXA: " << posfixa << endl;
                        }
                    }
               }
            }
            //printar
            for(int y = 0; y < expressao.length(); y++){
                cout << "POSFIXA FINAL: " << posfixa[y] << endl;
            }
        };
};

