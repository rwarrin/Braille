/**
 *
 * Compile with:
 * gcc -std=c11 -ggdb -Wall -Werror -Wextra -pedantic -O0 -I./include src/texttobraille.c -c -o lib/texttobraille.o
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "braillemap.h"
#include "texttobraille.h"

void GetBrailleOutput(BrailleOutput *bo, char *string) {
	bo->mCharPosition = 0;
	memset(bo->mLineOne, 0x00, MAX_BRAILLE_OUTPUT_LENGTH);
	memset(bo->mLineTwo, 0x00, MAX_BRAILLE_OUTPUT_LENGTH);
	memset(bo->mLineThree, 0x00, MAX_BRAILLE_OUTPUT_LENGTH);
	char brailleStr[7] = {'\0'};
	for(int i = 0, j = strlen(string); i < j; i++) {
		LetterToBraille(string[i], brailleStr);
		AppendCharacter(bo, brailleStr);
	}
}

void LetterToBraille(char character, char brailleStr[]) {
	CharMap foundChar;
	for(int i = 0; i < BRAILLE_MAP_SIZE; i++) {
		if(character == _BRAILLE[i].mEnglishCharacter)
			foundChar = _BRAILLE[i];
	}

	for(int i = 0; i < 6; i++)
		brailleStr[i] = foundChar.mBrailleString[i];
}

void AppendCharacter(BrailleOutput *bo, char brailleStr[]) {
	bo->mLineOne[bo->mCharPosition] = brailleStr[0];
	bo->mLineOne[bo->mCharPosition + 1] = brailleStr[1];
	bo->mLineTwo[bo->mCharPosition] = brailleStr[2];
	bo->mLineTwo[bo->mCharPosition + 1] = brailleStr[3];
	bo->mLineThree[bo->mCharPosition] = brailleStr[4];
	bo->mLineThree[bo->mCharPosition + 1] = brailleStr[5];
	
	bo->mCharPosition += 2;
	bo->mLineOne[bo->mCharPosition] = ' ';
	bo->mLineTwo[bo->mCharPosition] = ' ';
	bo->mLineThree[bo->mCharPosition] = ' ';
	bo->mCharPosition++;
}
