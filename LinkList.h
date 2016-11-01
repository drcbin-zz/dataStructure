#include<string>
using namespace std;
template<class T> class LS_node{
    public:
        LS_node(){
            this->next = NULL;
            this->pre = NULL;
        }
        LS_node<T>(T data){
            this->data=data;
            this->next=NULL;
            this->pre = NULL;
        }
        T data;
        LS_node *next,*pre;
};
template<class T> class LinkList{
    private:
        int MAXSIZE;
        LS_node<T> *head;
        LS_node<T> *last;
        bool haveMaxSize;
        int length;
        LS_node<T> data;
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
        void empty();
};
template<class T> LinkList<T>::LinkList(){
    this->head=NULL;
    this->last=NULL;   
    this->haveMaxSize=false;
}
template<class T> LinkList<T>::LinkList(int MAXSIZE){
    if(MAXSIZE <= 0){
        string VALUEERROR = "VALUEERROR";
        try{
             throw VALUEERROR;
        }catch(string e){
            throw e;
        }
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
        try{
            throw OVERFLOWERROR;
        }catch(string e){
            throw e;
        }
    }
    if(!head){
        head=new LS_node<T>(data);
        last=head;
        length++;
        return;
    }
    last->next = new LS_node<T>(data);
    last->next->pre=last;
    last = last->next;
    length++;
}
template<class T> T LinkList<T>::pop(){
    if(!head){
        string OVERFLOWERROR = "OVERFLOWERROR";
        try{
            throw OVERFLOWERROR;
        }catch(string e){
            throw e;
        }
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
    LS_node<T> *p=head;
    if(local > length){
        string OVERFLOWERROR = "OVERFLOWERROR";
        try{
            throw OVERFLOWERROR;
        }catch(string e){
            throw e;
        }
    }
    for(int i=0;p && i<local-1;i++){
        p = p->next;
    }        
    if(p==head){
            T data = p->data;
            head = head->next;
            head->pre = NULL;
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
        try{
             throw OVERFLOWERROR;
        }catch(string e){
            throw e;
        }
    }
    T data = last->data;
    return data;
}
template<class T> T LinkList<T>::get(int local){
    LS_node<T> *p=head;
    if(local > length){
        string OVERFLOWERROR = "OVERFLOWERROR";
        try{
            throw OVERFLOWERROR;
        }catch(string e){
            throw e;
        }
    }
    for(int i=0;p && i<local-1;i++){
        p = p->next;
    }
    if(!p){
        string NOTFINDERROR="NOTFINDERROR";
        try{
           throw NOTFINDERROR; 
        }catch(string e){
            throw e;
        }
    }
    return p->data;
}
template<class T> bool LinkList<T>::isEmpty(){
    if(haveMaxSize){
        return length >= MAXSIZE?true:false;
    }
    return false;
}
template<class T>void LinkList<T>::empty(){
    LS_node<T> *p = last;
    while(p){
        p = last->pre;
        delete last;
        length--;
    }
    head = NULL;
}
