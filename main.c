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

    int a[] = {3, 4, 2, 8, 5, 0, 1};
    int x = 0;
    printf("%d", linear_search(a, sizeof(a), sizeof(int), &x));

    return 0;
}