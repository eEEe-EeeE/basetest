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

typedef struct edge {
    int adjvex;
    int weight;
    struct edge *next;
} ELink;

typedef struct ver {
    int vertex;
    ELink *link;
} VLink;


void adj_matrix(int A[][MAXVNUM], int n , int e);
void adj_list(VLink G[], int n, int e);

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
    printf("input vertex num: \n");
    scanf("%d", &n);
    printf("input edge num: \n");
    scanf("%d", &e);

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

void adj_list(VLink G[], int n, int e) {

}