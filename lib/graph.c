//
// Created by BPanther on 2019/11/15.
//

#include <graph.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define MAXVALUE INT_MAX
#define MAXVNUM 100

VLink init_undirected_graph(int n, int e) {
    VLink G = (VLink) malloc(sizeof(VNode) * n);
    if (G != NULL) {
        undirected_adj_list(G, n, e);
    }
    return G;
}

VLink init_directed_graph(int n, int e) {
    VLink G = (VLink) malloc(sizeof(VNode) * n);
    if (G != NULL) {
        directed_adj_list(G, n, e);
    }
    return G;
}

void undirected_adj_list(VLink G, int n, int e) {
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
            printf("%d edge\n", k);
            printf("iNode: ");
            scanf("%d", &vi);
            printf("jNode: ");
            scanf("%d", &vj);
            printf("Weight: ");
            scanf("%d", &weight);
            iPtr->adjvex = vj - 1;
            jPtr->adjvex = vi - 1;
            iPtr->weight = jPtr->weight = weight;
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

void directed_adj_list(VLink G, int n, int e) {
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
            printf("%d edge\n");
            printf("tail: ");
            scanf("%d", &vt);
            printf("head: ");
            scanf("%d", &vh);
            printf("weight: ");
            scanf("%d", &weight);
            ePtr->adjvex = vh - 1;
            ePtr->weight = weight;
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

void adj_matrix(int A[][MAXVNUM], int n, int e) {
    int i, j, k, weight;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            A[i][j] = MAXVALUE;
        }
    }

    for (k = 0; k < n; ++k) {
        printf("i = ");
        scanf("%d", &i);
        printf("j = ");
        scanf("%d", &j);
        printf("weight = ");
        scanf("%d", &weight);
        printf("\n");
        A[i][j] = weight;
        A[j][i] = weight;
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
