#include"BTree.h"
#include"Queue.h"
#include"LinkList.h"
#include"Stack.h"
#include"MGraph-array.h"
#include"MGraph-list.h"
#include<iostream>
void menu(MGraphlist graph){
    cout<<"1.DFT\n2.BFT"<<endl;
    int choose = 1;
    while(choose != 0){
        cin>>choose;
        switch(choose){
            case 1:graph.DFS(1);
                   graph.reset();
                   break;
            case 2:graph.BFS(1);
                   graph.reset();
                   break;
        }
    }
}
 
int main(){
    MGraphlist graph(8,8);
    menu(graph);
}
