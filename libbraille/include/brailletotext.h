#ifndef INC_BRAILLETOTEXT_H
#define INC_BRAILLETOTEXT_H

#include <stdbool.h>

#define MAX_BRAILLE_STR_LENGTH 256

typedef struct BrailleArray {
    char mLineOne[MAX_BRAILLE_STR_LENGTH];
    char mLineTwo[MAX_BRAILLE_STR_LENGTH];
    char mLineThree[MAX_BRAILLE_STR_LENGTH];
    unsigned int mReadPosition;
} BrailleArray;

char* ConvertBrailleToText(FILE *fpIn);
void GetBrailleTextFromFile(FILE *fpIn, BrailleArray *ba);
bool GetLetterFromBraille(BrailleArray *ba, char *character);
void ConvertBrailleStringToCharacter(char brailleStr[], char *character);

#endif
