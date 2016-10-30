#include<string>
using namespace std;
template<class T>class Node{
    public:
       T data;
       Node<T> *next,pre;
       Node(){
           this->next = NULL;
           this->pre = NULL;
       }
       Node(T data){
           this->head = NULL;
           this->pre = NULL;
           this->data = data;
       }
};
template<class T>class Stack{
    private:
        Node<T> *head,*top;
        bool haveMaxSize;
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
};
template<class T>Stack<T>::Stack(){
    this->length = 0;
    this->head = NULL;
    this->top = NULL;
    this->haveMaxSize = false;
}
template<class T>Stack<T>::Stack(int MAXSIZE){
    this->length = 0;
    this->head = NULL;
    this->top = NULL;
    if(MAXSIZE <= 0){
        try{
            string VALUEERROR = "VALUEERROR";
            throw VALUEERROR;
        }catch(string e){
            throw e;
        }
    }
    this->haveMaxSize = true;
    this->MAXSIZE = MAXSIZE;
}
template<class T>void Stack<T>::push(T data){
    if(!head){
        head = new Node<T>(data);
        top = head;
        length++;
    } 
    if(haveMaxSize){
        if(length >= MAXSIZE){
            string OVERFLOWERROR = "OVERFLOWERROR";
            try{
                throw OVERFLOWERROR;
            }catch(string e){
                throw OVERFLOWERROR;
            }
        }
    }
    top->next = new Node<T>(data);
    top->next->pre = top;
    top = top->next;
    length++;
}

