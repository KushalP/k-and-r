
#include <stdio.h>

int main (int argc, char *argv[])
{
    int character;

    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            putchar('\\');
            putchar('t');
        }
        
        else if (character == '\b') {
            putchar('\\');
            putchar('b');
        }

        else if (character == '\\') {
            putchar('\\');
            putchar('\\');
        }

        else
            putchar(character);
    }

    return 0;
}


