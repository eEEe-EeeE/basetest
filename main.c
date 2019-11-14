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


void adj_matrix(int A[][MAXVNUM], int n , int e);
void adj_list(VNode G[], int n, int e);

int main() {

//    "A(B(D,E(G)),C(F(,H)))@";
//    char *words[] = {"A", "(", "B", "(", "D", ",", "E", "(", "G", ")", ")", ",", "C", "(", "F", "(", ",", "H", ")",
//                     ")", ")", "@", NULL};

    int keys[] = {
            5,
            10,
            5,
            20,
            17,
            12,
            19,
            2
    };


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