#ifndef INC_TEXTTOBRAILLE_H
#define INC_TEXTTOBRAILLE_H

#define MAX_BRAILLE_OUTPUT_LENGTH 256

typedef struct BrailleOutput {
    char mLineOne[MAX_BRAILLE_OUTPUT_LENGTH];
    char mLineTwo[MAX_BRAILLE_OUTPUT_LENGTH];
    char mLineThree[MAX_BRAILLE_OUTPUT_LENGTH];
    int mCharPosition;
} BrailleOutput;

void GetBrailleOutput(BrailleOutput *bo, char *string);
void LetterToBraille(char character, char brailleStr[]);
void AppendCharacter(BrailleOutput *bo, char brailleStr[]);

#endif
