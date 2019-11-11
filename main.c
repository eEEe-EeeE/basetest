#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <binary_tree.h>
#include <binary_search_tree.h>
#include <thread_binary_tree.h>
#include <balanced_binary_tree.h>
#include <huffman_tree.h>
#include <utils.h>
#include <stack.h>
#include <queue.h>


int main() {

    //"A(B(D,E(G)),C(F(,H)))@";
//    char *words[] = {"A", "(", "B", "(", "D", ",", "E", "(", "G", ")", ")", ",", "C", "(", "F", "(", ",", "H", ")",
//                     ")", ")", "@", NULL};
//
//    char *pre[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", NULL};
//    char *in[] = {"B", "C", "A", "E", "D", "G", "H", "F", "I", NULL};
//    BTree p = recover_bt_by_pre_in(pre, in, 9);
//    pre_order_recur(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    pre_order(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    post_order_recur(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    level_print_bt(p);
//    printf("\n");

//    BTree T = create_bt(words);
//    printf("%d\n", count_bt_leaf_recur(T));
//    printf("%d\n", count_bt_leaf(T));
//    printf("%d", count_bt_depth_in(T));

//    BTree T = NULL;
//    build_bt(&T);
//    level_print_bt(T);

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
    BSTree p = create_bst(keys, sizeof(keys) / sizeof(keys[0]));
    delete_bst(p, 5);
//
//    BTree T = create_bst(keys);
//    in_order(T, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    BTree p = search_bst(T, "19");
//    printf("%s", p->data);


//    int w[] = {4, 2, 1, 2, 2, 1, 1, 1};
//    size_t len = sizeof(w) / sizeof(*w);
//    int *parent = NULL;
//    int *l_child = NULL;
//    int *r_child = NULL;
//    create_hfmt(w, len, &parent, &l_child, &r_child);
//    for (int i = 0; i < 2 * (int) len - 1; ++i) {
//        printf("%d, %d, %d, %d, %d\n", i, w[i], parent[i], l_child[i], r_child[i]);
//    }
//
//    printf("\n************************\n");
//    int *start = NULL;
//    char *code = NULL;
//    create_hfm_code(&code, &start, len, parent, l_child, r_child);
//    int i;
//    for (i = 0; i < (int) len; ++i) {
//        int j;
//        for (j = start[i]; j < (int) len; ++j) {
//            printf("%d ", code[i * len + j]);
//        }
//        if (i != len - 1)
//            printf("\n");
//    }

    return 0;
}