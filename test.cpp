#include"LinkList.h"
#include<iostream>
using namespace std;
int main(){
    LinkList<int> lis;
    lis.push(4);
    cout<<lis.get()<<endl;
    return 0;
}
