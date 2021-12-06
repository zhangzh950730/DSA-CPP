//
// Created by 张之豪 on 2021/12/6.
//
#define MaxVertexNum 100 //顶点数目最大值
typedef char VertexType; //顶点的数据类型
typedef int EdgeType; //带权图边上权值的数据类型

typedef struct {
    VertexType Vex[MaxVertexNum]; //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵,边表
    int vexnum, arcnum; //图的当前定点数和弧数
} MGraph;