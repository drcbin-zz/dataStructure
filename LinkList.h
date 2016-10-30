#include<iostream>
#include<string>
using namespace std;
template<class T> class Node{
    public:
        Node(){
            this->next = NULL;
            this->pre = NULL;
        }
        Node<T>(T data){
            this->data=data;
            this->next=NULL;
            this->pre = NULL;
        }
        T data;
        Node *next,*pre;
};
template<class T> class LinkList{
    private:
        int MAXSIZE;
        Node<T> *head;
        Node<T> *last;
        bool haveMaxSize;
        int length;
        Node<T> data;
    public:
        LinkList();
        LinkList(int MAXSIZE);
        int getLength();
        void push(T data);
        T pop();
        T pop(int local);
        T get();
        T get(int local);
        bool isEmpty();
};
template<class T> LinkList<T>::LinkList(){
    this->head=NULL;
    this->last=NULL;   
    this->haveMaxSize=false;
}
template<class T> LinkList<T>::LinkList(int MAXSIZE){
    if(MAXSIZE <= 0){
        string VALUEERROR = "VALUEERROR";
        throw VALUEERROR;
    }
    this->head=NULL;
    this->last=NULL;   
    this->MAXSIZE=MAXSIZE;
    this->haveMaxSize=true;
}
template<class T> int LinkList<T>::getLength(){
    return length;
}
template<class T> void LinkList<T>::push(T data){
    if(isEmpty()){
        string OVERFLOWERROR = "OVERFLOWERROR";
        throw OVERFLOWERROR;
    }
    if(!head){
        head=new Node<T>(data);
        last=head;
        length++;
        return;
    }
    last->next = new Node<T>(data);
    last->next->pre=last;
    last = last->next;
    length++;
}
template<class T> T LinkList<T>::pop(){
    if(!head){
        cout << "now in pop()" << endl;
        string OVERFLOWERROR = "OVERFLOWERROR";
        throw OVERFLOWERROR;
        cout << "now in the end of pop()" << endl;
    }
    T data = last->data;
    if(!last->pre){
        delete last;
        last = NULL;
        head = NULL;
    }else{
        last = last->pre;
        delete last->next;
        last->next = NULL;
    }
    length--;
    return data;  

}
template<class T> T LinkList<T>::pop(int local){
    Node<T> p=head;
    if(local > length){
        string OVERFLOWERROR = "OVERFLOWERROR";
        throw OVERFLOWERROR;
    }
    for(int i=0;p && i<local-1;i++){
        p = p->next;
    }        
    if(p==head){
        try{
            head = head->next;
            head->pre = NULL;
        }catch(...){
            cout << "get is" << endl;
        }
    }
    else if(p && p->next){
        T data = p->data;
        p->next->pre = p->pre;
    }
    else if(p && p->pre){
        T data = p->data;
        p->pre->next = p->next;
    }
    delete p;
    length--;
    return data;
}
template<class T> T LinkList<T>::get(){
    if(!head){
        string OVERFLOWERROR = "OVERFLOWERROR";
        throw OVERFLOWERROR;
    }
    T data = last->data;
    return data;
}
template<class T> T LinkList<T>::get(int local){
    Node<T> p=head;
    if(local > length){
        string OVERFLOWERROR = "OVERFLOWERROR";
        throw OVERFLOWERROR;
    }
    for(int i=0;p && i<local-1;i++){
        p = p->next;
    }
    if(!p){
        string NOTFINDERROR="NOTFINDERROR";
       throw NOTFINDERROR; 
    }
    return p->data;
}
template<class T> bool LinkList<T>::isEmpty(){
    if(haveMaxSize){
        return length >= MAXSIZE?true:false;
    }
    return false;
}
