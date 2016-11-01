#include"Queue.h"
#include"LinkList.h"
#include"Stack.h"
#include<iostream>
using namespace std;
void menu(Queue<int> &queue){
    int choose,value;
    while(true){
        cout << "1.push one.\n2.pop.\n3.empty.\n4.isFull.\n5.isEmpty.\nInput:" << queue.getLength() << endl;
        cin >> choose;
        try{
            switch(choose){
                case 1:
                    cout << "input the value:" << endl;
                    cin >> value;
                    queue.push(value);
                    break;
                case 3:
                    queue.empty();
                    break;
                case 2:
                    cout << queue.pop() << " droped!\n" << endl << endl;
                    break;
                case 4:
                    cout << queue.isFull() << endl << endl;
                    break;
                case 5:
                    cout << queue.isEmpty() << endl << endl;
                    break;
                case 6:
                    cout << queue.getLength() << endl << endl;
                    break;
                case 0:
                    return;
            }
        }catch(string e){
            cout << e << endl;
        }
    }
}
int main(){
    Queue<int> queue;
    menu(queue);
    return 0;
}
