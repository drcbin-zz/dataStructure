#include<string>
using namespace std;
template<class T>class BTree_node{
    public:
        T data;
        int ltag,rtag;
        BTree_node<T> *lchild,rchild;
        BTree_node(){
            this->lchild = NULL;
            this->rchild = NULL;
            this->ltag = 0;
            this->rtag = 0;
        }
        BTree_node(T data){
            this->lchild = NULL;
            this->rchild = NULL;
            this->ltag = 0;
            this->rtag = 0;
            this->data = data;
        }
};
template<class T>class BTree{
    private:
       BTree_node<T>* root;
    public:
       BTree();
        BTree_node<T>* create();
       void threadly();
       void preOrder();
       void inOrder();
       void postOrder();
       void levelOrder(); 
};
template<class T>BTree<T>::BTree(){
    this->root;
}
template<class T>BTree_node<T>* BTree<T>::create(){
   T data;
   cin >> data;
   if(data == '#'){
       
   }
}
