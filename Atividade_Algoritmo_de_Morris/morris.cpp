#include <iostream>
#include <queue>
using namespace std;


template<class T>
class Node{
    public:
    T el;
    Node<T> *left, *right;

    Node(){
        left= right=0;
    }

    Node(T e, Node<T> *l = 0, Node<T> *r=0){
        el=e;
        left=l;
        right=r;
    }
};

template<class T>
class TreeNo{
    protected:
    TreeNo<T> *root;
    public:
    Tree(){
        root=0;
    }

    TreeNo<T>* getRoot(){
        return root;
    }
    bool isEmpty() const{
        returnroot=0;
    }

    void visit(TreeNo<T> *p){
        cout<<p->el<<" ";
    }

    void insert_in_tree(T el){
        TreeNo<T> *p=root,*prev=0;
        while (p!=0){
            prev=p;
            if(el<p->el){
                p=p->left;
            } else {
                p=p->right;
            }
            if(root==0){
                root=new TreeNo<T>(el);
            } else if(el < prev->el){
                prev->left=new TreeNo<T>(el);
            } else{
                prev->right=new TreeNo<T>(el);
            }
        }

       void MorrisInOrderSearch(){
        TreeNo<T> *p=root,*tmp;

        while(p!=0){
            if(p->left==0){
                visit(p);
                p=p->right;
            }
            else {
                tmp=p->right;
            }
            else {
                tmp=p->left;

                while(tmp->right != 0 && tmp->right != p){
                    tmp=tmp->right;
                }

                if(tmp->right==0){
                    tmp->right=p;
                    p=p->left;
                } else {
                    visit(p);
                    tmp->right=0;
                    p=p->right;
                }
            }
        }
    }

    void  MorrisInPreOrderSearch(){
        TreeNo<T> *p=root, *tmp;

        while(p!=0){
            if(p->left==0){
                visit(p);
                p=p->right;
            } else{
                tmp=p->left;

                while(tmp->right !=0 && tmp->right !=p){
                    tmp=tmp->right;
                }

                if(tmp->right == 0){
                    visit(p);
                    tmp->right=p;
                    p=p->right;
                }
            }
        }
    }

    void MorrisInPreOrderSearchDois(){
        TreeNo<T> *p=root, *temp;
        while(p!=0){
            if(p->left==0){
                visit(p);
                p=p->right;
            }
            else{
                tmp=p->left;
                while(tmp->right!=0 && tmp->right!=p){
                    tmp=tmp->right;
                    if(tmp->right==0){
                        visit(p);
                        tmp->right=p;
                        p=p->left;
                    }
                    else{
                        tmp->right=0;
                        p=p->right;
                    }
                }
            }
        }
    };

    main(){
        TreeNo<int> *tree= new TreeNo<int>();

        tree->insert_in_tree(14);
        tree->insert_in_tree(18);
        tree->insert_in_tree(3);
        tree->insert_in_tree(6);
        tree->insert_in_tree(9);
        tree->insert_in_tree(12);
        tree->insert_in_tree(23);
        tree->insert_in_tree(1);
        tree->insert_in_tree(26);
        tree->insert_in_tree(15);

        cout << "Começo" << endl;

        cout << "preorder_um" << endl;
        tree->MorrisInPreOrderSearch();

        cout << "Fim" << endl;
        cout << "Começo" << endl;

        cout<< "preorder_dois" << endl;
        tree->MorrisInPreOrderSearchDois();
        cout << "Fim" << endl;
    }   
}

/* Características do algoritmo de Morris para percurso in-order: 
- utiliza espaço de memória constante;
- não modifica a estrutura da árvore;
- utiliza os ponteiros right dos nós;
- realiza o percurso in-order em tempo linear; 
- mantém a ordem correta dos elementos. */