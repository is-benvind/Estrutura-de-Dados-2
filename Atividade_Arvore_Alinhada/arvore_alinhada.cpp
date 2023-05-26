#include <iostream>

using namespace std;

template<typename T>
struct ArovreNo {
    T valor;
    ArovreNo<T>* esquerda;
    ArovreNo<T>* direita;

    ArovreNo(const T& valor):valor(valor), esquerda(NULL), direita(NULL){}
};

template<typename T>
void incluirNo(ArovreNo<T>*& raiz, const T& valor){
    if(raiz==NULL){
        raiz = new ArovreNo<T>(valor); 
    } else {
        if(valor < raiz->valor){
            incluirNo(raiz->esquerda, valor);
        } else {
            incluirNo(raiz->direita, valor);
        }
    }
}

template<typename T>
void percursoInOrder(ArovreNo<T>* raiz){
    if(raiz!=NULL){
        percursoInOrder(raiz->esquerda);
        cout << raiz->valor << " ";
        percursoInOrder(raiz->direita);
    }
}

template<typename T>
void percursoPreOrder(ArovreNo<T>* raiz) {
    if(raiz!= NULL){
        cout<< raiz->valor << " ";
        percursoPreOrder(raiz->esquerda);
        percursoPreOrder(raiz->direita);
    }
}

int main(){
    ArovreNo<int>* raiz = NULL; 

    incluirNo(raiz, 9);
    incluirNo(raiz, 4);
    incluirNo(raiz, 14);
    incluirNo(raiz, 3);
    incluirNo(raiz, 6);

    cout<< "Percurso In-Order: ";
    percursoInOrder(raiz);
    cout << endl;

    cout<< "Percurso Pre-Order: ";
    percursoPreOrder(raiz);
    cout << endl;

    return 0;
}