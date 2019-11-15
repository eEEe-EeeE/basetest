#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <binary_tree.h>
#include <binary_search_tree.h>
#include <thread_binary_tree.h>
#include <balanced_binary_tree.h>
#include <huffman_tree.h>
#include <utils.h>
#include <stack.h>
#include <queue.h>

#define MAXVALUE INT_MAX
#define MAXVNUM 100

typedef struct _edge {
    int adjvex;
    int weight;
    struct _edge *next;
} ENode, *ELink;

typedef struct _vertex {
    int data;
    ELink link;
} VNode, *VLink;

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


void adj_matrix(int A[][MAXVNUM], int n, int e);

void adj_list(VNode G[], int n, int e);

void delver(VNode G[], int n, int key);

int main() {

//    "A(B(D,E(G)),C(F(,H)))@";
//    char *words[] = {"A", "(", "B", "(", "D", ",", "E", "(", "G", ")", ")", ",", "C", "(", "F", "(", ",", "H", ")",
//                     ")", ")", "@", NULL};

//    int keys[] = {
//            5,
//            10,
//            5,
//            20,
//            17,
//            12,
//            19,
//            2
//    };

    VLink G = (VLink) malloc(sizeof(VNode) * 3);
    adj_list(G, 3, 3);
    G[0];
    G[1];
    G[2];
    return 0;
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

void adj_list(VNode G[], int n, int e) {
    int i, j, k, weight;
    for (i = 0; i < n; ++i) {
        G[i].data = i + 1;
        G[i].link = NULL;
    }

    for (k = 0; k < e; ++k) {
        ELink p = (ELink) malloc(sizeof(ENode));
        if (p != NULL) {
            scanf("%d %d %d", &i, &j, &weight);
            p->adjvex = j - 1;
            p->weight = weight;
            p->next = NULL;
            if (G[i - 1].link == NULL) {
                G[i - 1].link = p;
            } else {
                ELink q = G[i - 1].link;
                while (q->next) {
                    q = q->next;
                }
                q->next = p;
            }
        }
    }
}

void delver(VNode G[], int n, int key) {
    int i;
    int keyIndex = -1;
    for (i = 0; i < n; ++i) {
        if (G[i].data == key) {
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
            G[i - 1].data = G[i].data;
            G[i - 1].link = G[i].link;
        }
    }
}
