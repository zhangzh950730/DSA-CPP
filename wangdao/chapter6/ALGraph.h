//
// Created by 张之豪 on 2021/12/6.
//

#define MaxVertexNum 100 //顶点数目最大值
typedef char VertexType; //顶点的数据类型
typedef int EdgeType; //带权图边上权值的数据类型

typedef struct ArcNode { //边表结点
    int adjvex; //该弧所指向的顶点的位置
    struct ArcNode *next; //指向下一条弧的指针
} ArcNode;

typedef struct VNode { //顶点表结点
    VertexType data; //顶点信息
    ArcNode *first; //指向第一条依附该订单的弧的指针
} VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices; //邻接表
    int vexnum, arcnum; //图的顶点数和弧数
} ALGraph;

void visit(int v);

int FirstNeighbor(ALGraph G, int v);

int NextNeighbor(ALGraph G, int v, int w);