#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <binary_tree.h>
#include <thread_binary_tree.h>
#include <utils.h>
#include <stack.h>
#include <queue.h>


int main() {

    //"A(B(D,E(G)),C(F(,H)))@";
    char *words[] = {"A", "(", "B", "(", "D", ",", "E", "(", "G", ")", ")", ",", "C", "(", "F", "(", ",", "H", ")",
                     ")", ")", "@", NULL};
//
//    char *pre[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", NULL};
//    char *in[] = {"B", "C", "A", "E", "D", "G", "H", "F", "I", NULL};
//    BTREE p = recover_bt_by_pre_in(pre, in, 9);
//    pre_order_recur(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    pre_order(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    post_order_recur(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    level_print_bt(p);
//    printf("\n");

//    BTREE T = create_bt(words);
//    level_print_bt(T);

//    BTREE T = NULL;
//    build_bt(&T);
//    level_print_bt(T);

//    STRING keys[] = {
//            "5",
//            "10",
//            "5",
//            "20",
//            "17",
//            "12",
//            "19",
//            "2",
//            NULL
//    };
//
//    BTREE T = create_bst(keys);
//    in_order(T, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    BTREE p = search_bst_recur(T, "19");
//    printf("%s", p->data);


    return 0;
}