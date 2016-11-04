#include<iostream>
using namespace std;
template<class T>class MGraph{
    private:
        int **arc;
        T *vertex;
        int vertexNum,arcNum;
    public:
        MGraph(T *vertex,int vertexNum,int arcNum);
        void DFSTraverse();
        void BFSTraverse();
};
template<class T>MGraph<T>::MGraph(T *vertex,int vertexNum,int arcNum){
    this->vertex = vertex;
    this->vertexNum = vertexNum;
    this->arcNum = arcNum;
    arc = new int*[vertexNum];
    for(int i = 0;i < vertexNum;i++){
        arc[i] = new int[vertexNum];
        for(int j = 0;j < vertexNum;j++){
            arc[i][j] = 0;
        }
    }
    while(arcNum--){
        cin>>i>>j;
        arc[i][j] = arc[j][i] = 1;
    }
}

template<class T> void 
