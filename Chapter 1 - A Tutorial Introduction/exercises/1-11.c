
#include <stdio.h>

#define IN  1
#define OUT 0

int main (int argc, char *argv[])
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == '\n')
            ++nl;

        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;

        else if (state == OUT) {
            state = IN;
            ++nw;
        }    
    }

    printf("\n---------------------------\n");
    printf("Total characters:\t%d\n", nc);
    printf("Total words:\t\t%d\n", nw);
    printf("Total lines:\t\t%d\n", nl);

    return 0;
}


