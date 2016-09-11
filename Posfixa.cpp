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

        /*----------------------- FUNÇÃO EMPILHAR-----------------------------*/
        void empilhar(PILHA **topo, string recebe){
            PILHA *novo;
            //novo = (PILHA*) malloc (sizeof(PILHA));
            novo = new PILHA;
            if(novo == NULL)
                cout << "NÃO ALOCADO" << endl;
            else{
                novo->armazena = recebe;
                novo->prox = (*topo);
                (*topo) = novo;
            }
        };

        /*----------------------- FUNÇÃO DESEMPILHAR-----------------------------*/
        void desempilhar(PILHA **topo){
            PILHA *aux;
            
            if(aux == NULL)
                cout << "NÃO EXISTE NENHUM ELEMENTO NA PILHA" << endl;
            else{ 
                aux = (*topo); 
                free (aux); 
                (*topo) = (*topo)->prox; 
            }
        };

        void liberaPilha (PILHA **topo){
            PILHA *aux = (*topo);
            if (aux == NULL)
                cout << " NÃO EXISTE ELEMENTO PARA REMOVER!" << endl;
            else{
                do{
                    aux = (*topo)->prox;
                    free (*topo);
                    (*topo) = aux;
                    cout << "TODOS ELEMENTOS REMOVIDOS COM SUCESSO" << endl;
                }while (aux != NULL);
            }
        }

        /*--------------------- FUNÇÃO PRECENDENCIA PILHA------------------------*/
        int precedenciasPilha(PILHA *topo){
            if(topo == NULL){
                opction = 0;
            }
            else{
                if(topo->armazena == "*"){
                    opction = 4;
                }
                else if(topo->armazena == "."){
                    opction = 3;
                }
                else if(topo->armazena == "+"){
                    opction = 2;
                }
                else if(topo->armazena == "(")
                    opction = 1;
            }            
            return opction;
        };

        /*--------------------- FUNÇÃO PRECENDENCIA EXPRESSAO-----------------------*/
        int precedenciasExpr(string novaExpressao, int x){
            
            if(novaExpressao[x] == '*')
                opcao = 4;
            else if(novaExpressao[x] == '.')
                opcao = 3;
            else if(novaExpressao[x] == '+')
                opcao = 2;
            else if(novaExpressao[x] == '(')
                opcao = 1;
            return opcao;
        };

        string preencherExpressao(string expressao){
            string novaExpr;
            for(int x = 0; x < expressao.length(); x++){
                novaExpr += expressao[x];
                if((expressao[x] == '*' && expressao[x+1] != ')') || (expressao[x] == '*' && expressao[x+1] != '+')){
                    if(x+1 == expressao.length()){
                        break;
                    }
                    else{
                        novaExpr += '.';
                    }
                }
                else{
                    if((expressao[x] != '+' && expressao[x+1] != '*') && 
                        (expressao[x] != '+' && expressao[x+1] != ' ') &&
                        (expressao[x] != '+' && expressao[x+1] != ')') &&
                        (expressao[x] != '+' && expressao[x+1] != '(') &&

                        (expressao[x] != '(' && expressao[x+1] != '+') && 
                        (expressao[x] != '(' && expressao[x+1] != ' ') &&
                        (expressao[x] != '(' && expressao[x+1] != '*') &&
                        (expressao[x] != '(' && expressao[x+1] != ')') &&

                        (expressao[x] != ')' && expressao[x+1] != '+') && 
                        (expressao[x] != ')' && expressao[x+1] != ' ') &&
                        (expressao[x] != ')' && expressao[x+1] != '*') &&
                        (expressao[x] != ')' && expressao[x+1] != '(')){

                        if(x+1 == expressao.length()){
                            break;
                        }
                        else{
                            novaExpr += '.';
                        }
                    }
                    else{
                        if((expressao[x] != '+' && expressao[x+1] == '(') &&
                            (expressao[x] != '*' && expressao[x+1] == '(') &&
                            (expressao[x] != ')' && expressao[x+1] == '(') &&
                            (expressao[x] != '(' && expressao[x+1] == '(')){
                            novaExpr += '.';
                        }
                        else{
                            if((expressao[x] == ')' && expressao[x+1] != '*') &&
                                (expressao[x] == ')' && expressao[x+1] != '+') &&
                                (expressao[x] == ')' && expressao[x+1] != '(')){
                                if(x+1 == expressao.length()){
                                    break;
                                }
                                else{
                                    novaExpr += '.';
                                }
                            }
                            else{
                                if((expressao[x] == ')' && expressao[x+1] == '(')){
                                    novaExpr += '.';
                                }
                            }
                        }
                    }
                }
            }
            return novaExpr;
        };

        /*-----------------------FUNÇÃO INFIXAPARAPOSFIXA---------------------*/
        void infixaParaPosfixa(string expressao){
            string posfixa, recebe, novaExpressao;
            PILHA *topo = NULL;
            
            preencherExpressao(expressao);
            novaExpressao = preencherExpressao(expressao);
            cout << "novaExpressao: " << novaExpressao << endl;

            for(int x = 0; x < novaExpressao.length(); x++){
                //Tratamento de ser "(", então empilha -> SITUAÇÃO OK
                if(novaExpressao[x] == '('){
                    cout << "------------------------------------------" << endl;
                    recebe =  novaExpressao[x];
                    cout << "É ( - VAI SER EMPILHADO: " << recebe << endl;
                    empilhar(&topo, recebe);//Empilhar tá OK
                    cout << "FOI EMPILHADO: " << recebe << endl;
                    cout << "LISTA DOS QUE TÁ NA PILHA" << endl;
                    listar(topo);
                    cout << "------------------------------------------" << endl << endl;
                }

                else{
                    //Tratamento para caso seja ")", então enquanto o topo = "(" desempilha -> SITUAÇÃO OK
                    if(novaExpressao[x] == ')'){ 
                        while(topo->armazena != "(" && topo != NULL){
                            cout << "------------------------------------------" << endl;
                            cout << "ACHOU UM ) - DESEMPILHAR" << endl;
                            posfixa += topo->armazena;
                            cout << "POSFIXA: " << posfixa << endl;
                            cout << "VAI SER DESEMPILHADO, QUANDO O ITEM TOPO FOR != ')' -> " << topo->armazena << endl;
                            desempilhar(&topo);//Desempilha
                            cout << "AGORA O TEMOS NO TOPO " << topo->armazena << endl; 
                            cout << "------------------------------------------" << endl << endl;
                        }
                        //Desempilhar e descartar o "(" -> SITUAÇÃO OK
                        if(topo->armazena == "("){
                            cout << "------------------------------------------" <<  endl;
                            cout << "ACHOU UM ) - E PAROU O LAÇO VAI DESEMPILHAR" << topo->armazena << endl;
                            desempilhar(&topo);
                            cout << "------------------------------------------" << endl << endl;
                        }
                    }
                    else{
                        //Para caso de ser operador
                        if(novaExpressao[x] == '*' || novaExpressao[x] == '.' || novaExpressao[x] == '+') {
                            cout << "===============================================" << endl;
                            cout << "PRECENDENCIA PILHA: " << precedenciasPilha(topo) << endl;
                            cout << "PRECENDENCIA EXPRE: " << precedenciasExpr(novaExpressao, x) << endl << endl; 
                            cout << "LISTAR PARA VER" << endl;
                            listar(topo);
                            cout << "===============================================" << endl;
                                
                            while(precedenciasPilha(topo) >= precedenciasExpr(novaExpressao, x)){
                                posfixa += topo->armazena;
                                cout << "TOPO QUE SERÁ DESEMPILHADO: " << topo->armazena << endl;
                                desempilhar(&topo); //Erro ta aqui ------------>
                                cout << "POSFIXA: " << posfixa << endl;
                                if(topo == NULL)
                                    cout << "VAZIA" << endl;
                            }
                            cout << "------------------------------------------" << endl;
                            recebe = novaExpressao[x];
                            cout << "VAI SER EMPILHADO: " << recebe << endl;
                            empilhar(&topo, recebe);
                            cout << "EMPILHADO: " << topo->armazena << endl;
                            cout << "LISTA DOS QUE TÁ NA PILHA" << endl;
                            listar(topo);
                            cout << "------------------------------------------" << endl  << endl;
                        }
                            //Falta Fazer o teste para caso a expressão acabe e ainda reste elementos na pilha e esvaziar
                        else{
                            posfixa += novaExpressao[x];
                            cout << "------------------------------------------" << endl;
                            cout << " VAI DIRETO PARA POSFIXA: " << novaExpressao[x] << endl;
                            cout << "POSFIXA RECEBEU -> " << posfixa << endl;
                            cout << "------------------------------------------" << endl  << endl;
                        }
                    }
                }
                //Quando novaExpressao não tiver mais elementos e topo tiver
                if(x+1 == novaExpressao.length()){
                    while(topo != NULL){
                        posfixa += topo->armazena;
                        desempilhar(&topo);
                    }
                }
            }
            //printar
            cout << "POSFIXA GERADA: ";
            for(int y = 0; y < novaExpressao.length(); y++){
                cout << "" << posfixa[y];
            }
            cout << endl;
            //return posfixa;
        };

        // void verificarPosfixa (){
        //     //Falta fazer o tratamento da pilha
        //     string verificarPos, simbolo, op1, op2, valor;
        //     verificarPos = infixaParaPosfixa(expressao);
        //     for(int y = 0; y < verificarPos.length(); y++){
        //         simbolo = verificarPos[x];
        //         //Verificando se é operando
        //         if(simbolo[x] != '(' || simbolo[x] != ')' || simbolo[x] != '*' || simbolo[x] != '+' || simbolo[x] != '.'){
        //             //Empilhar o operando
        //             empilhar(&topo, simbolo);
        //         }
        //         else{
        //             //Verificando se é operador binário
        //             if(topo != NULL){
        //                 //Falta Declarar o tipos das variáveis op1, op2 e valor, não sei
        //                 op2 = topo->armazena;
        //                 desempilhar(&topo);
        //                 if(topo != NULL){
        //                     op1 = topo->armazena;
        //                     desempilhar(&topo);
        //                 }
        //             }
        //         }
        //     }
        // }
};

                                    
