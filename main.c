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
    char *sentences[] = {"A", "(", "B", "(", "D", ",", "E", "(", "G", ")", ")", ",", "C", "(", "F", "(", ",", "H", ")",
                         ")", ")", "@", NULL};

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
    char *str = (char *) malloc(20);
    scanf("%s", str);
    printf("|%s|", str);
    return 0;
}