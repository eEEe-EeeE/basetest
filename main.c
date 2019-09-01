#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <binary_tree.h>
#include <utils.h>
#include <stack.h>




int main() {

    //"A(B(D,E(G)),C(F(,H)))@";
    char sentence[] = "A(B(D,E(G)),C(F(,H)))@";
    int sentence_len = sizeof(sentence) / sizeof(char);

    BTREE T = create_bt(sentence, sentence_len);
    post_order_recur(T, (void (*)(int, ...)) print_bt_node);
    printf("\n");
    post_order(T, (void (*)(int, ...)) print_bt_node);

    return 0;
}