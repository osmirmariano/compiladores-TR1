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
            novo = (PILHA*) malloc (sizeof(PILHA));
            listar(*topo);
            if(novo == NULL)
                cout << "OI 2" << endl;
            else{
                cout << "NOVO antes" << novo->armazena << endl;
                novo->armazena = recebe;
                cout << "NOVO depois" << novo->armazena << endl;
                if(*topo == NULL){
                    novo->prox = NULL;
                }
                else{
                    novo->prox = (*topo);
                }
                (*topo) = novo;
            }
        };

        /*----------------------- FUNÇÃO DESEMPILHAR-----------------------------*/
        void desempilhar(PILHA **topo){
            PILHA *aux;
            
            if(aux == NULL)
                cout << "NÃO EXISTE NENHUM ELEMENTO NA PILHA" << endl;
            else{

                cout << "ALGO 1" << endl;
                aux = (*topo);
                cout << "AUX: " << aux->armazena << endl;
                cout << "ALGO 2" << endl;
                free (aux);
                // if(*topo == NULL)
                //     topo->armazena = '1';
                cout << "ALGO 3" << endl;
                (*topo) = (*topo)->prox;
                cout << "ALGO 4" << endl;
                //aux = (*topo);

                /*cout << "ALGO 2 " << endl;
                aux = (*topo)->prox;
                cout << "ALGO 3 " << endl;
                delete (*topo);
                cout << "ALGO 4 " << endl;
                cout << "TOPO DELETE: " << (*topo)->armazena << endl;
                (*topo) = aux;
                cout << "ALGO 5 " << endl;*/
            }
        };

       

        /*--------------------- FUNÇÃO PRECENDENCIA PILHA------------------------*/
        int precedenciasPilha(PILHA *topo){
            if(topo == NULL){
                opction = 0;
            }
            else{
                if(topo->armazena == "*"){
                    opction = 3;
                }
                else if(topo->armazena == "."){
                    opction = 2;
                }
                else if(topo->armazena == "+"){
                    opction = 1;
                }
            }            
            return opction;
        };

        /*--------------------- FUNÇÃO PRECENDENCIA EXPRESSAO-----------------------*/
        int precedenciasExpr(string novaExpressao, int x){
            
            if(novaExpressao[x] == '*')
                opcao = 3;
            else if(novaExpressao[x] == '.')
                opcao = 2;
            else if(novaExpressao[x] == '+')
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
                    recebe =  novaExpressao[x];
                    cout << "RECEBE: " << recebe << endl;
                    empilhar(&topo, recebe);//Empilhar tá OK
                    cout << "SAIU" << endl;
                    cout << "EMPILHADO, QUANDO O ITEM FOR '(' -> " << topo->armazena << endl;
                }

                else{
                    //Tratamento para caso seja ")", então enquanto o topo = "(" desempilha -> SITUAÇÃO OK
                    if(novaExpressao[x] == ')'){
                        //cout << "ITEM CORRESPONDE AO ')' -> " << topo->armazena << endl;
                        while(topo->armazena != "(" && topo != NULL){
                            posfixa += topo->armazena;
                            cout << "POSFIXA: " << posfixa << endl;
                            cout << "VAI SER DESEMPILHADO, QUANDO O ITEM TOPO FOR != ')' -> " << topo->armazena << endl;
                            desempilhar(&topo);//Desempilha
                            cout << "AGORA O TEMOS NO TOPO " << topo->armazena << endl;
                            
                            //cout << "PROCURANDO ERRO 2" << endl;
                        }
                        //Desempilhar e descartar o "(" -> SITUAÇÃO OK
                        if(topo->armazena == "("){
                            cout << "VAI SER DESEMPILHADO, QUANDO O ITEM TOPO FOR == '(' -> " << topo->armazena << endl;
                            desempilhar(&topo);
                            //cout << "VAI SER DESEMPILHADO, TESTE -> " << topo->armazena << endl;
                            //cout << "PROCURANDO ERRO 3" << endl;
                        }
                    }

                    else{
                        //Para caso de ser operador
                        if(novaExpressao[x] == '*' || novaExpressao[x] == '.' || novaExpressao[x] == '+') {
                            //cout << "PROCURANDO ERRO 4" << endl;
                            if(topo == NULL){
                                recebe = novaExpressao[x];
                                cout << "TOPO TÁ VAZIO, VAI EMPILHAR NO 2º EMPILHAR * -> " << recebe << endl;
                                empilhar(&topo, recebe);
                                cout << "EMPILHADO: " << topo->armazena << endl;
                                //cout << "PROCURANDO ERRO 5" << endl;
                            }
                            else{
                                //cout << "PROCURANDO ERRO 6" << endl;
                                if(topo->armazena == "("){
                                    recebe = novaExpressao[x];
                                    empilhar(&topo, recebe);
                                    cout << "EMPILHADO, QUANDO O ITEM TOPO FOR '(' -> " << topo->armazena << endl;
                                }
                                else{
                                    //Verifica se a precedencia do topo é > que a da expressão (operador) -> SITUAÇÃO OK
                                    //cout << "PROCURANDO ERRO 8" << endl;
                                    cout << "* = " << precedenciasPilha(topo) << " É > QUE . = " << precedenciasExpr(novaExpressao, x) << endl;

                                    while(precedenciasPilha(topo) >= precedenciasExpr(novaExpressao, x)){
                                        cout << "NOVAEXPRESSAO: " << novaExpressao[x] << endl;
                                        //cout << "PROCURANDO ERRO 9" << endl;
                                        posfixa += topo->armazena;
                                        //cout << "PROCURANDO ERRO 00" << endl;
                                        cout << "TOPO: " << topo->armazena << endl;
                                        desempilhar(&topo); //Erro ta aqui ------------>
                                        cout << "POSFIXA: " << posfixa << endl;
                                        cout << "PRECENDENCIA PILHA: " << precedenciasPilha(topo) << endl;

                                        cout << "PRECENDENCIA EXPRE: " << precedenciasExpr(novaExpressao, x) << endl << endl;
                                    
                                    }
                                    //cout << "VALOR" << endl;
                                    cout << "RECEBE: " << recebe << endl;
                                    recebe = novaExpressao[x];
                                    empilhar(&topo, recebe);
                                    //cout << "PROCURANDO ERRO 10" << endl;
                                }
                            }
                        }
                        //Falta Fazer o teste para caso a expressão acabe e ainda reste elementos na pilha e esvaziar
                        else{
                            posfixa += novaExpressao[x];
                            cout << "POSFIXA RECEBEU -> " << posfixa << endl;
                        }
                    }
                }
                //Quando novaExpressao não tiver mais elementos e topo tiver
                cout << "VALOR X: " << x << endl; 
                cout << "VALOR N: " << novaExpressao.length() << endl;
                if(x+1 == novaExpressao.length()){
                    while(topo != NULL){
                        posfixa += topo->armazena;
                        desempilhar(&topo);
                        cout << "PROCURANDO ERRO 12" << endl;
                    }
                }
            }
            //printar
            cout << endl;
            for(int y = 0; y < novaExpressao.length(); y++){
                cout << " " << posfixa[y];
            }
            cout << endl;
        };
};

                                    
