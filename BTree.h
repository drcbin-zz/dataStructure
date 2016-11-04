#include<iostream>
#include<string>
using namespace std;
template<class T>class BTree_node{
    public:
        T data;
        int ltag,rtag;
        BTree_node<T> *lchild,*rchild;
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
template<class T>
class Node{
    public:
        Node *next;
        BTree_node<T> *BNode;
        Node(BTree_node<T> *BNode){
            this->BNode = BNode;
            this->next = NULL;
        }
};
template<class T>class BTree{
    private:
        BTree_node<T>* root;
    public:
        BTree();
        BTree_node<T>* _create();
        void _threadly(BTree_node<T> *root,BTree_node<T>* pre);
        void _preOrder(BTree_node<T> *root);
        void _inOrder(BTree_node<T> *root);
        void _postOrder(BTree_node<T>* root);
        void _levelOrder(BTree_node<T> *root);

        void create(){
           root =  _create();
        }
        void threadly(){
            _threadly(root,NULL);
        }
        void preOrder(){
            _preOrder(root);
        }
        void inOrder(){
            _inOrder(root);
        }
        void postOrder(){
            _postOrder(root);
        }
        void levelOrder(){
            _levelOrder(root);
        }
};
template<class T>BTree<T>::BTree(){
    this->root = NULL;
}
template<class T>BTree_node<T>* BTree<T>::_create(){
   T data;
   cout << "input value:";
   cin >> data;
   BTree_node<T>* temp;
    if(data == '#'){
        cout << "input #" << endl;
        temp = NULL;
    }else{
        cout << "inputed,not #" << endl;
        temp = new BTree_node<T>(data);
        temp->lchild =  _create();
        temp->rchild = _create();
    }
    return temp;
}
template<class T>void BTree<T>::_preOrder(BTree_node<T>* root){
    if(root != NULL){
        cout << root->data << " ";
        _preOrder(root->lchild);
        _preOrder(root->rchild);
    }   
}
template<class T>void BTree<T>::_inOrder(BTree_node<T> *root){
    if(root != NULL){
        _inOrder(root->lchild);
        cout << root->data << " ";
        _inOrder(root->rchild);
    }
}
template<class T>void BTree<T>::_postOrder(BTree_node<T>* root){
    if(root != NULL){
        _postOrder(root->lchild);
        _postOrder(root->rchild);
        cout << root->data << " ";
    }
}
template<class T>void BTree<T>::_threadly(BTree_node<T>* root,BTree_node<T> *pre){
    if(root == NULL){
        return;
    }
    if(root ->lchild == NULL && root->ltag == 0){
        root->lchild = pre;
        root-> ltag = 1;
        pre = root;
    }
    _threadly(root->lchild,pre);
    if(pre->rtag == 0 && pre->rchild == NULL){
        pre->rtag =1;
        pre->rchild = root;
        }
    pre = root;
    _threadly(root->rchild,pre);
}
template<class T>void BTree<T>::_levelOrder(BTree_node<T> *root){
    Node<T> *head,*p,*last;
    head = new Node<T>(root);
    head->BNode = root;
    p = last = head;
    while(head){
        if(head->BNode->lchild){
            last->next = new Node<T>(head->BNode->lchild);
            last = last->next;
        }
        if(head->BNode->rchild){
            last->next = new Node<T>(head->BNode->rchild);
            last = last->next;
        }
        cout << head->BNode->data;
        head = head->next;
        delete p;
        p=head;
    }
}
