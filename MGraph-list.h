#include<iostream>
using namespace std;

class ArcNode
{
public:
    ArcNode (int id){
        this->vertexNodeId = id;
        this->next = NULL;
    }
    int vertexNodeId;
    ArcNode* next;
};


class VertexNode
{
public:
    VertexNode (){
        this->firstEdge = NULL;
        this->visited = false;
    }
    int data;
    bool visited;
    ArcNode* firstEdge;
};

class MGraphlist
{
public:
    MGraphlist (int vertexNum, int arcNum){
        this->vertexNum = vertexNum;
        this->arcNum = arcNum;
        int i, j, temp;
        for(i = 1; i <= vertexNum; i++){
            // cin >> temp;
            vertexs[i].data = i;//temp;
        }
        for (j = 1;j <= arcNum; j++){
            cin >> i >> temp;

            //正向链接
            ArcNode *newArcNode = new ArcNode(temp);
            //首插法
            // newArcNode->next = vertexs[i].firstEdge;
            // vertexs[i].firstEdge = newArcNode;

            //尾插
            ArcNode *p = vertexs[i].firstEdge;
            if(p){
                while(p->next){
                    p = p->next;
                }
                p->next = newArcNode;
            }else{
                vertexs[i].firstEdge = newArcNode;
            }


            //反向链接
            newArcNode = new ArcNode(i);
            // 首插法
            // newArcNode->next = vertexs[temp].firstEdge;
            // vertexs[temp].firstEdge = newArcNode;
            
            //尾插
            p = vertexs[temp].firstEdge;
            if (p) {
                while(p && p->next){
                    p = p->next;
                }
                p->next = newArcNode;
            } else {
                vertexs[temp].firstEdge = newArcNode;
            }
        }
    }
    void DFS(int start){
        // reset();
        cout << vertexs[start].data << ' ';
        vertexs[start].visited = true;
        ArcNode* p = vertexs[start].firstEdge;
        while(p){
            if(vertexs[p->vertexNodeId].visited == false){
                DFS(p->vertexNodeId);
            }
            p=p->next;
        }
    }

    void BFS(int start){
        // reset();
        int Q[vertexNum];
        for (int i = 0; i < vertexNum; ++i) {
            Q[i] = 0;
        }
        int front =-1, rear = -1;
        cout << vertexs[start].data << ' ';
        vertexs[start].visited = true;
        Q[++rear] = start;
        while(front != rear){
            start = Q[++front];
            ArcNode *p = vertexs[start].firstEdge;
            while(p){
                if(vertexs[p->vertexNodeId].visited == false){
                    cout << vertexs[p->vertexNodeId].data << ' ';
                    vertexs[p->vertexNodeId].visited = true;
                    Q[++rear] = p->vertexNodeId;
                }
                p = p->next;
            }
        }
    }
    void reset(){
        for (int i = 0; i < vertexNum; ++i) {
            vertexs[i].visited = false;
        }
    }

private:
    VertexNode vertexs[20];
    int vertexNum, arcNum;
};
