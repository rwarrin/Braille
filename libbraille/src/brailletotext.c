/**
 *
 * Compile with:
 * gcc -std=c11 -ggdb -Wall -Werror -Wextra -pedantic -O0 -I./include src/brailletotext.c -c -o lib/brailletotext.o
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "braillemap.h"
#include "brailletotext.h"

typedef unsigned int uint;

char* ConvertBrailleToText(FILE *fpIn) {
    if(fpIn == NULL)
        return NULL;

    const unsigned int MAX_OUTPUT_LENGTH = 256;
    char *output = NULL;
    output = malloc(sizeof(char) * MAX_OUTPUT_LENGTH);
    if(output == NULL)
        return NULL;

    BrailleArray ba; 
    ba.mReadPosition = 0;
    memset(ba.mLineOne, 0x00, sizeof(char) * MAX_BRAILLE_STR_LENGTH);
    memset(ba.mLineTwo, 0x00, sizeof(char) * MAX_BRAILLE_STR_LENGTH);
    memset(ba.mLineThree, 0x00, sizeof(char) * MAX_BRAILLE_STR_LENGTH);

    GetBrailleTextFromFile(fpIn, &ba);

    char letter;
    int location = 0;
    while(GetLetterFromBraille(&ba, &letter)) {
        output[location++] = letter;
    }
    output[location] = '\0';

    return output;
}

void GetBrailleTextFromFile(FILE *fpIn, BrailleArray *ba) {
    if(fpIn == NULL)
        return;

    fgets(ba->mLineOne, MAX_BRAILLE_STR_LENGTH, fpIn);
    fgets(ba->mLineTwo, MAX_BRAILLE_STR_LENGTH, fpIn);
    fgets(ba->mLineThree, MAX_BRAILLE_STR_LENGTH, fpIn);
}

bool GetLetterFromBraille(BrailleArray *ba, char *character) {
    char brailleStr[6] = {'\0'};

    if(ba->mLineOne[ba->mReadPosition] == ' ')
        ba->mReadPosition++;

    if(ba->mLineOne[ba->mReadPosition] == '\n' || ba->mLineOne[ba->mReadPosition] == '\0')
        return false;

    brailleStr[0] = ba->mLineOne[ba->mReadPosition];
    brailleStr[1] = ba->mLineOne[ba->mReadPosition + 1];
    brailleStr[2] = ba->mLineTwo[ba->mReadPosition];
    brailleStr[3] = ba->mLineTwo[ba->mReadPosition + 1];
    brailleStr[4] = ba->mLineThree[ba->mReadPosition];
    brailleStr[5] = ba->mLineThree[ba->mReadPosition + 1];
    ba->mReadPosition += 2;

    ConvertBrailleStringToCharacter(brailleStr, character);

    return true;
}

void ConvertBrailleStringToCharacter(char brailleStr[], char *character) {
    for(int i = 0; i < BRAILLE_MAP_SIZE; i++) {
        if(strcmp(brailleStr, _BRAILLE[i].mBrailleString) == 0) {
            *character = _BRAILLE[i].mEnglishCharacter;
            return;
        }
    }
}
