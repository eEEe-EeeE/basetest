//
// Created by BPanther on 2019/11/15.
//

#include <graph.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <queue.h>


VLink init_undirected_graph(int n, int e, int isWeighted) {
    VLink G = (VLink) malloc(sizeof(VNode) * n);
    if (G != NULL) {
        undirected_adj_list(G, n, e, isWeighted);
    }
    return G;
}

VLink init_directed_graph(int n, int e, int isWeighted) {
    VLink G = (VLink) malloc(sizeof(VNode) * n);
    if (G != NULL) {
        directed_adj_list(G, n, e, isWeighted);
    }
    return G;
}

void clr_graph(VLink G, int n) {
    int index = 0;
    ELink ep = NULL;
    ELink delPtr = NULL;
    while (index < n) {
        ep = G[index].link;
        while (ep != NULL) {
            delPtr = ep;
            ep = ep->next;
            free(delPtr);
        }
        ++index;
    }
}

void undirected_adj_list(VLink G, int n, int e, int isWeighted) {
    int i;
    for (i = 0; i < n; ++i) {
        G[i].key = i + 1;
        G[i].link = NULL;
    }

    int vi, vj, k, weight;
    ELink iPtr = NULL;
    ELink jPtr = NULL;
    ELink p = NULL;
    for (k = 0; k < e; ++k) {
        iPtr = (ELink) malloc(sizeof(ENode));
        jPtr = (ELink) malloc(sizeof(ENode));
        if (iPtr != NULL && jPtr != NULL) {
            if (isWeighted) {
                printf("%d edge -- iNode, jNode, weight:\n", k);
                scanf("%d %d %d", &vi, &vj, &weight);
                iPtr->weight = jPtr->weight = weight;
            } else {
                printf("%d edge -- iNode, jNode:\n", k);
                scanf("%d %d", &vi, &vj);
                iPtr->weight = jPtr->weight = 1;
            }
            iPtr->adjvex = vj - 1;
            jPtr->adjvex = vi - 1;
            iPtr->next = jPtr->next = NULL;

            p = G[vi - 1].link;
            if (p != NULL) {
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = iPtr;
            } else {
                G[vi - 1].link = iPtr;
            }

            p = G[vj - 1].link;
            if (p != NULL) {
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = jPtr;
            } else {
                G[vj - 1].link = jPtr;
            }
        }
    }
}

void directed_adj_list(VLink G, int n, int e, int isWeighted) {
    int index;
    for (index = 0; index < n; ++index) {
        G[index].key = index + 1;
        G[index].link = NULL;
    }

    ELink ePtr = NULL;
    int vt, vh, k, weight;
    ELink p = NULL;
    for (k = 0; k < e; ++k) {
        ePtr = (ELink) malloc(sizeof(ENode));
        if (ePtr != NULL) {
            if (isWeighted) {
                printf("%d edge -- tail, head, weight:\n", k);
                scanf("%d %d %d", &vt, &vh, &weight);
                ePtr->weight = weight;
            } else {
                printf("%d edge -- tail, head:\n", k);
                scanf("%d %d", &vt, &vh);
                ePtr->weight = 1;
            }
            ePtr->adjvex = vh - 1;
            ePtr->next = NULL;

            p = G[vt - 1].link;
            if (p != NULL) {
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = ePtr;
            } else {
                G[vt - 1].link = ePtr;
            }
        }
    }
}

void delver(VLink G, int n, int key) {
    int i;
    int keyIndex = -1;
    for (i = 0; i < n; ++i) {
        if (G[i].key == key) {
            keyIndex = i;
            break;
        }
    }

    // 边结点相关指针
    ELink trvPtr, prePtr, delPtr;

    // 找到key结点
    if (keyIndex != -1) {
        // 第一部分 遍历 key 之前的顶点结点
        for (i = 0; i < keyIndex; ++i) {
            prePtr = trvPtr = G[i].link;
            // 遍历所有边结点
            while (trvPtr != NULL) {
                // 弧头是keyIndex就删除边结点，否则如果大于keyIndex就减一前移
                if (trvPtr->adjvex == keyIndex) {
                    delPtr = trvPtr;
                    if (prePtr == trvPtr) {
                        G[i].link = prePtr = trvPtr->next;
                    } else {
                        prePtr->next = trvPtr->next;
                    }
                    trvPtr = trvPtr->next;
                    free(delPtr);
                } else {
                    if (trvPtr->adjvex > keyIndex) {
                        trvPtr->adjvex -= 1;
                    }
                    prePtr = trvPtr;
                    trvPtr = trvPtr->next;
                }
            }
        }
        // 第二部分 删除 key 所有边结点
        trvPtr = G[keyIndex].link;
        while (trvPtr != NULL) {
            delPtr = trvPtr;
            trvPtr = trvPtr->next;
            free(delPtr);
        }

        // 第三部分 遍历 key 之后的顶点结点
        for (i = keyIndex + 1; i < n; ++i) {
            prePtr = trvPtr = G[i].link;
            // 遍历所有边结点
            while (trvPtr != NULL) {
                if (trvPtr->adjvex == keyIndex) {
                    delPtr = trvPtr;
                    if (prePtr == trvPtr) {
                        G[i].link = prePtr = trvPtr->next;
                    } else {
                        prePtr->next = trvPtr->next;
                    }
                    trvPtr = trvPtr->next;
                    free(delPtr);
                } else {
                    if (trvPtr->adjvex > keyIndex) {
                        trvPtr->adjvex -= 1;
                    }
                    prePtr = trvPtr;
                    trvPtr = trvPtr->next;
                }
            }

            // 结点前移
            G[i - 1].key = G[i].key;
            G[i - 1].link = G[i].link;
        }
    }
}


void travel_dfs(VLink G, int n) {
    int *visited = (int *) malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
    int i;
    for (i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            _dfs(G, i, visited);
        }
    }
    free(visited);
}

void _dfs(VLink G, int vIndex, int *visited) {
    // 访问结点
    printf("vertex key: %d\n", G[vIndex].key);

    // 访问完，访问标记置1
    visited[vIndex] = 1;

    ELink ePtr = G[vIndex].link;
    while (ePtr != NULL) {
        if (visited[ePtr->adjvex] == 0) {
            _dfs(G, ePtr->adjvex, visited);
        }
        ePtr = ePtr->next;
    }
}

void travel_bfs(VLink G, int n) {
    int *visited = (int *) malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(int) * n);
    int i;
    for (i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            _bfs(G, i, visited);
        }
    }
    free(visited);
}

void _bfs(VLink G, int vIndex, int *visited) {
    // 访问结点
    printf("vertex key: %d\n", G[vIndex].key);

    // 访问完，访问标记置1
    visited[vIndex] = 1;

    QUEUE *queue = init_queue(sizeof(int), 20);
    push_queue(queue, &vIndex);
    int vi = -1;
    ELink ePtr = NULL;
    while (!queue_is_empty(queue)) {
        pop_queue(queue, &vi);
        ePtr = G[vi].link;
        while (ePtr != NULL) {
            // 访问结点的所有邻接结点
            if (visited[ePtr->adjvex] == 0) {
                printf("vertex key: %d\n", G[ePtr->adjvex].key);

                push_queue(queue, &(ePtr->adjvex));
                visited[ePtr->adjvex] = 1;
            }
            ePtr = ePtr->next;
        }
    }
}

TREE min_span_prim(VLink G, int n) {

}

TREE min_span_kruskal(VLink G, int n) {

}
