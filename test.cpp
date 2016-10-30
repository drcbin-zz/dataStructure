#include"LinkList.h"
#include<iostream>
using namespace std;
void menu(LinkList<int> &lis){
    int choose,value;
    while(true){
        cout << "1.push one.\n2.get one.\n3.pop.\n0.exit.\nInput:" << endl;
        cin >> choose;
        switch(choose){
            case 1:
                cout << "input the value:" << endl;
                cin >> value;
                lis.push(value);
                break;
            case 2:
                cout << lis.get() << endl;
                break;
            case 3:
                cout << lis.pop() << " droped!" << endl;
                break;
            case 0:
                return;
        }
    }
}
int main(){
    LinkList<int> lis(2);
    cout << "this is in main functon" << endl;
    menu(lis);
    return 0;
}
