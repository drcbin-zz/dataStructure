#include<iostream>
using namespace std;


/*             图的邻接矩阵表示
 *
 *              A   B   C   D   E
 *
 *          A   0   0   1   1   0
 *
 *          B   0   0   1   0   0
 *
 *          C   1   1   0   0   1
 *
 *          D   1   0   0   0   0
 *
 *          E   0   0   1   0   0
 *
 *
 */
template<class T>class MGraph{ private: int *visited;
        int **arc;   //用来存储图的两个点之间关系的矩阵
        T *vertex;   //点集
        int vertexNum,arcNum;//点的个数，边的条数
    public:
        MGraph(T *vertex,int vertexNum,int arcNum);
        void DFSTraverse(int start);//深度遍历
        void BFSTraverse(int start);//广度遍历
        void reset();
};


template<class T> void MGraph<T>::reset(){
    for(int i = 0; i < vertexNum; i++){
        visited[i] = 0;
    }
}

template<class T>MGraph<T>::MGraph(T *vertex,int vertexNum,int arcNum){
    int i,j;
    this->vertex = vertex;
    this->vertexNum = vertexNum;
    this->arcNum = arcNum;
    arc = new int*[vertexNum];

    for(i = 0;i < vertexNum;i++){
        //初始化矩阵，并置0
        arc[i] = new int[vertexNum];
        for(j = 0;j < vertexNum;j++){
            arc[i][j] = 0;
        }
    }

    while(arcNum--){
        //用户输入有关联的两个点，并在矩阵中将这两个点的关联置为1
        cin>>i>>j;
        arc[i-1][j-1] = arc[j-1][i-1] = 1;
    }
    visited = new int[vertexNum];
}



template<class T> void MGraph<T>::DFSTraverse(int start){
    //深度遍历

    cout << vertex[start] << endl;
    visited[start] = 1;
    for(int j = 0; j < vertexNum; j++){
        if(arc[start][j] == 1 && visited[j] != 1){
            DFSTraverse(j);
        }
    }
}



template<class T> void MGraph<T>::BFSTraverse(int start){
    //广度遍历

    int j;
    int *Q = new int[vertexNum];
    int front = -1, rear = -1;
    cout << vertex[start];
    visited[start] = 1;
    Q[++rear] = start;
    while(front != rear){
        start = Q[++front];
        for(j = 0; j < vertexNum; j++){
            if(arc[start][j] ==1 & visited[front] != 1){
                cout << vertex[j];
                visited[j] = 1;
                Q[++rear] = j;
            }
        }
    }
}
