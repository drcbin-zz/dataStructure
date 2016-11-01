#include<iostream>
#include<string>
using namespace std;
template<class T>class ST_node{
    public:
        T data;
        ST_node<T> *next,*pre;
        ST_node(){
            this->next = NULL;
            this->pre = NULL;
        }
        ST_node(T data){
            this->next = NULL;
            this->pre = NULL;
            this->data = data;
            cout << "this->data = data" << data << endl;
        }
};
template<class T>class Stack{
    private:
        ST_node<T> *head,*top;
        bool hasMaxSize;
        int MAXSIZE;
        int length;
    public:
        Stack();
        Stack(int MAXSIZE);
        void push(T data);
        T pop();
        void empty();
        bool isEmpty();
        bool isFull();
        int getLength();
        T get();
};
template<class T>Stack<T>::Stack(){
    this->length = 0;
    this->head = NULL;
    this->top = NULL;
    this->hasMaxSize = false;
}
template<class T>Stack<T>::Stack(int MAXSIZE){
    this->length = 0;
    this->head = NULL;
    this->top = NULL;
    if(MAXSIZE <= 0){
        try{
            string VALUEERROR = "VALUEERROR";
            throw VALUEERROR; }catch(string e){
            throw e;
        }
    }
    this->hasMaxSize = true;
    this->MAXSIZE = MAXSIZE;
}
template<class T>void Stack<T>::push(T data){
    if(!head){
        head = new ST_node<T>(data);
        top = head;
        length++;
        return;
    } 
    if(hasMaxSize){
        if(length >= MAXSIZE){
            string OVERFLOWERROR = "OVERFLOWERROR";
            try{
                throw OVERFLOWERROR;
            }catch(string e){
                throw OVERFLOWERROR;
            }
        }
    }
    top->next = new ST_node<T>(data);
    top->next->pre = top;
    top = top->next;
    length++;
}
template<class T>T Stack<T>::pop(){
    string OVERFLOWERROR = "OVERFLOWERROR";
    if(!top && !length){
        try{
            throw OVERFLOWERROR;
        }catch(string e){
            throw ;
        }    
    }
        T data = top->data;
    if(top == head){
        delete top;
        head = NULL;
        top = NULL;
    }else{
        top = top->pre;
        delete top-> next;
        top->next = NULL;
    }
    length--;
    return data;
}
template<class T>bool Stack<T>::isFull(){
    if(hasMaxSize){
        return length>=MAXSIZE?true:false;
    }
    return false;
}
template<class T> bool Stack<T>::isEmpty(){
    if(length == 0 && top == NULL && head == NULL){
        return true;
    }
    return false;
}
template<class T>int Stack<T>::getLength(){
    return length;
}
template<class T>void Stack<T>::empty(){
    ST_node<T> *p = top;
    while(p){
        length--;
        p=p->pre;
        delete top;
        top = p;
    }
    head = NULL;
}
template<class T>T Stack<T>::get(){
    string OVERFLOWERROR = "OVERFLOWERROR";
    if(!top){
        try{
            throw OVERFLOWERROR;
        }catch(string e){
            throw e;
        }
    }
    return top->data;
}
