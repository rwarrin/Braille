/*******************************************************************************
 * main.c
 *
 * Braille
 * Converts from braille to text or text to braille.
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "brailletotext.h"
#include "texttobraille.h"

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s [-t] translate <filename>\n", argv[0]);
        printf("       %s [-c] convert <string>\n", argv[0]);
        return 1;
    }

    if(strcmp(argv[1], "-t") == 0) {
        FILE *fpInput = fopen(argv[2], "r");
        if(fpInput == NULL) {
            printf("Failed to open file.\n");
            return 2;
        }

        char *text = ConvertBrailleToText(fpInput);
        fclose(fpInput);
        printf("%s\n", text);
        free(text);
    }
    else if(strcmp(argv[1], "-c") == 0) {
        BrailleOutput myBraille;
        GetBrailleOutput(&myBraille, argv[2]);
        printf("%s\n", myBraille.mLineOne);
        printf("%s\n", myBraille.mLineTwo);
        printf("%s\n", myBraille.mLineThree);
    }
    else {
        printf("Unknown option %s\n", argv[1]);
        return 3;
    }

    return 0;
}

