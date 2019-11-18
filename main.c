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

#include <graph.h>


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

    struct _node {
        int key;
        int degree;
        struct _node *child[100];
    };
    printf("%llu", sizeof(struct _node *));
    return 0;
}

