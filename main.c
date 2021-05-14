#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "angry-purple-tiger.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: angry-purple-tiger $message\n");
        return 0;
    }

    printf("%s\n", animal_name(argv[1], strlen(argv[1])));
}
