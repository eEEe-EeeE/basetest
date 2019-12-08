//
// Created by BPanther on 2019/11/15.
//

#ifndef BASETEST_GRAPH_H
#define BASETEST_GRAPH_H

// 邻接表
typedef struct _edge {
    // 弧头结点的位置
    int adjvex;
    // 边权重
    int weight;
    // 弧尾结点的下一条出边
    struct _edge *next;
} ENode, *ELink;

typedef struct _vertex {
    int key;
    ELink link;
} VNode, *VLink;


/*
 * 逆邻接表
*/
typedef struct _r_edge {
    // 弧尾结点的位置
    int adjvex;
    // 边权重
    int weight;
    // 弧头结点的下一条入边
    struct _r_edge *next;
} RENode, *RELink;

typedef struct _r_vertex {
    int key;
    RELink link;
} RVNode, *RVLink;


/*
 * 十字邻接表和多重邻接表的本质是合并邻接表和逆邻接表，即将边两个顶点的信息都放入边结点
 */

// 十字邻接表
typedef struct _cross_edge {
    int tail;
    int head;
    int weight;
    struct _cross_edge *hLink;
    struct _cross_edge *tLink;
} CENode, *CELink;

typedef struct _cross_vertex {
    int key;
    CELink inLink;
    CELink outLink;
} CVNode, *CVLink;

// 多重邻接表
typedef struct _multi_edge {
    int mark;
    int iVertex;
    int jVertex;
    int weight;
    struct _multi_edge *iLink;
    struct _nulti_edge *jLink;
} MENode, MELink;

typedef struct _multi_vertex {
    int key;
    MELink link;
} MVNode, MVLink;


// 初始化图顶点结点
VLink init_undirected_graph(int n, int e, int isWeighted);

VLink init_directed_graph(int n, int e, int isWeighted);

// 销毁图
void clr_graph(VLink G, int n);

// 建立邻接表

void undirected_adj_list(VLink G, int n, int e, int isWeighted);

void directed_adj_list(VLink G, int n, int e, int isWeighted);

// 删除结点
void delver(VLink G, int n, int key);

// 深度遍历 打印结点
void travel_dfs(VLink G, int n);

void _dfs(VLink G, int vIndex, int *visited);

// 广度遍历 打印结点
void travel_bfs(VLink G, int n);

void _bfs(VLink G, int vIndex, int *visited);

#include <tree.h>

// 最小生成树
TREE min_span_prim(VLink G, int n);

TREE min_span_kruskal(VLink G, int n);


#endif //BASETEST_GRAPH_H
