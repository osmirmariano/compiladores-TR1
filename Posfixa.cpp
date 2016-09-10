#include <iostream>
#include <cstdlib>
#include <string>

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
            int precedenciasPilha(PILHA *topo);
            int precedenciasExpr(string expressao, int x);
            void infixaParaPosfixa(string expressao);
		};
		~Posfixa();

        /*----------------------- FUNÇÃO EMPILHAR-----------------------------*/
        void empilhar(PILHA **topo, string recebe){
            PILHA *novo;
            novo = (PILHA*) malloc (sizeof(PILHA));

            if(novo == NULL)
                cout << "OI 2" << endl;
            else{
                //novo->armazena = recebe;
                if(*topo == NULL){
                    novo->armazena = recebe;
                    novo->prox = NULL;
                }
                else{
                    novo->armazena = recebe;// Erro tá aqui depois que é desempilhado algun item
                    novo->prox = (*topo);
                }
                (*topo) = novo;
                cout << "EMPILHADO COM SUCESSO" << novo->armazena << endl;
            }
        };

        /*----------------------- FUNÇÃO DESEMPILHAR-----------------------------*/
        void desempilhar(PILHA **topo){
            PILHA *aux;
            if(aux == NULL)
                cout << "NÃO EXISTE NENHUM ELEMENTO NA PILHA" << endl;
            else{
                // aux = (*topo)->prox;
                // delete *topo;
                // *topo = aux;
                aux = (*topo);
                (*topo) = (*topo)->prox;
                delete aux;
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
                    cout << " EMPILHADO: " << aux->armazena << endl;
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
                if(expressao[x] == '('){
                    recebe =  expressao[x];
                    empilhar(&topo, recebe);//Empilhar tá OK
                    cout << " -> EMPILHADO: " << topo->armazena << endl;
                }

                else{
                    if(expressao[x] == ')'){
                        while(topo->armazena != "("){
                            posfixa += topo->armazena;
                            cout << "POSFIXA: " << posfixa << endl;
                            desempilhar(&topo);//Desempilha
                        }
                        if(topo->armazena == "("){
                            desempilhar(&topo);
                        }
                    }

                    else{
                        //Testes para as precedências
                        if(expressao[x] == '*' || expressao[x] == '.' || expressao[x] == '+') {
                            if(topo == NULL){
                                recebe = expressao[x];
                                empilhar(&topo, recebe);
                                cout << " 1 EMPILHADO: " << topo->armazena << endl;//DEIXAR PARA TESTE
                            }
                            else{
                                if(topo->armazena == "("){
                                    recebe = expressao[x];
                                    cout << "RECEBE 2 " << recebe << endl;
                                    empilhar(&topo, recebe);
                                    cout << " 2 EMPILHADO: " << topo->armazena << endl;

                                }
                                else{
                                    while(precedenciasPilha(topo) > precedenciasExpr(expressao, x)){
                                        posfixa += topo->armazena;
                                        desempilhar(&topo);
                                    }
                                    if(precedenciasPilha(topo) < precedenciasExpr(expressao, x)){
                                        recebe = expressao[x];
                                        cout << "RECEBE: " << recebe << endl;
                                        cout << "IMPLEMENTAR" << endl;
                                        empilhar(&topo, recebe);
                                        cout << " 3 EMPILHADO: " << topo->armazena << endl;
                                    }
                                }
                            }
                        }
                        else{
                            posfixa += expressao[x];
                            cout << "POSFIXA: " << posfixa << endl;
                        }
                    }
                }
               //Falta verificar a questão de como operação em binário precisa de dois operadores
               //
            }
            //printar
            for(int y = 0; y < expressao.length(); y++){
                cout << "POSFIXA FINAL: " << posfixa[y] << endl;
            }
        };
};

                                    
