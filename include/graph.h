//
// Created by BPanther on 2019/11/15.
//

#ifndef BASETEST_GRAPH_H
#define BASETEST_GRAPH_H

// 邻接表
typedef struct _edge {
    int adjvex;
    int weight;
    struct _edge *next;
} ENode, *ELink;

typedef struct _vertex {
    int key;
    ELink link;
} VNode, *VLink;

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

VLink init_undirected_graph(int n, int e);

VLink init_directed_graph(int n, int e);

void del_undirected_graph(VLink G);

void del_directed_graph(VLink G);

void undirected_adj_list(VLink G, int n, int e);

void directed_adj_list(VLink G, int n, int e);

void adj_matrix(int A[][100], int n, int e);

void delver(VLink G, int n, int key);




#endif //BASETEST_GRAPH_H
