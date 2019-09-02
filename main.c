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

    int x = 1;
    int y = 3;
    int res = memcmp(&x, &y, sizeof(int));
    printf("%d", res);

    return 0;
}