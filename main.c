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
    char sentence[] = "A(B(D,E(G)),C(F(,H)))@";
    int sentence_len = sizeof(sentence) / sizeof(char);

//    char pre[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
//    char in[] = {'B', 'C', 'A', 'E', 'D', 'G', 'H', 'F', 'I'};
//    BTREE p = recover_bt_by_pre_in(pre, in, 9);
//    pre_order_recur(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    pre_order(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    post_order_recur(p, (void (*)(int, ...)) print_bt_node);
//    printf("\n");
//    level_print_bt(p);
//    printf("\n");
    TBTREE T = create_tbt(sentence, sentence_len);
    in_thread(&T);
    thr_in_order(T);

    return 0;
}