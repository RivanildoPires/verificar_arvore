#include <iostream>

using namespace std;

struct NoArvore{

    int dados;
    NoArvore* esquerda;
    NoArvore* direita;
};

int altura(NoArvore *raiz){
    if(raiz == NULL){
        return 0;
    }
    
	return 1+max(altura(raiz->esquerda), altura(raiz->direita));
	
	}

int contarNo(NoArvore* raiz){
    if (raiz == NULL){
        return (0);}
    return (1 + contarNo(raiz->esquerda) + contarNo(raiz->direita));
}

NoArvore* inserirNo(int value) {
    NoArvore* novoNo = new NoArvore;
    novoNo->dados = value;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void listar(NoArvore* raiz){

    if(raiz != NULL){

        cout << raiz->dados << " " ;
        listar(raiz->esquerda);
        listar(raiz->direita);
        
    }
}
bool verificarCompleta ( NoArvore* raiz,int indices,int numNo)
{
   
    if (raiz == NULL)
        return(true);
 
    if (indices >= numNo)
        return(false);
 
    return (verificarCompleta(raiz->esquerda, 2*indices + 1, numNo) &&
            verificarCompleta(raiz->direita, 2*indices + 2, numNo));
}

bool verificarPerfeita(NoArvore *raiz){
    if(raiz == NULL){
        return true;
    }

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    if(alturaEsquerda == alturaDireita){
        return verificarPerfeita(raiz->esquerda) && verificarPerfeita(raiz->direita);
    }
    return false;
}

bool verificarBalanceada(NoArvore *raiz){ 
    if (raiz == NULL)
        return 1;
 

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);
 
    if (alturaEsquerda - alturaDireita <= 1 && verificarBalanceada(raiz->esquerda)&& verificarBalanceada(raiz->direita))
        return 1;
 
    return 0;
}

void verificarCheia(NoArvore* raiz){

    if(raiz != NULL){

        if(raiz->esquerda == NULL && raiz->direita == NULL){

            return;
        }

        if(raiz->esquerda != NULL && raiz->direita != NULL){

            verificarCheia(raiz->esquerda);
            verificarCheia(raiz->direita);
        }

        else{
			cout << "\nNao e uma raiz cheia!";
            return ;
        }
    }
};
bool verificarDegenerada(NoArvore* raiz) {
    
    if (raiz == NULL) {
        return true;
    }
    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        return false;
    }

    return verificarDegenerada(raiz->esquerda) && verificarDegenerada(raiz->direita);
}

bool verificarDestoricda(NoArvore* raiz) {
    if (raiz == NULL) {
        return true;
    }

    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        return false;
    }

    return verificarDestoricda(raiz -> esquerda) && verificarDestoricda(raiz -> direita);
}
int main(){
	
	NoArvore* raiz = inserirNo (1);
    raiz->esquerda = inserirNo(2);
    raiz->direita = inserirNo(4);
    raiz->esquerda->esquerda = inserirNo(6);
    //raiz->direita->direita = inserirNo(7);
    //raiz->esquerda->esquerda->esquerda = inserirNo(4);
    //raiz->direita->direita->direita = inserirNo(20);
    //raiz->esquerda->esquerda->esquerda->esquerda = inserirNo(9);
    //raiz->direita->direita->direita->direita = inserirNo(11);
    //raiz->esquerda->esquerda->esquerda->esquerda->esquerda = inserirNo(10);
    listar(raiz);
    verificarCheia(raiz);
    
    
    int numNo = contarNo(raiz);
    int indices = 0;
 
    if (verificarCompleta(raiz, indices, numNo)){
	
        cout << "\nE completa!\n";
    }else{
	
        cout << "\nNao e completa!\n";
    }
    
    if(verificarPerfeita(raiz)){
    	
    	cout << "E perfeita\n";
	}else{
	
        cout << "Nao e perfeita!\n";
    }
    
    
    if(verificarBalanceada(raiz)){
    	
    	cout << "E balanceada\n";
	}else{
	
        cout << "Nao e balanceada!\n";
    }
    
    if(verificarDegenerada(raiz)){
    	
    	cout << "E degenerada\n";
	}else{
	
        cout << "Nao e degenerada!\n";
    }
    
    if(verificarDestoricda(raiz)){
    	
    	cout << "E distoricda\n";
	}else{
	
        cout << "Nao e distorcida!\n";
    }
	
	return 0;
}
