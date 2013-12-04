#ifndef INC_BRAILLEMAP_H
#define INC_BRAILLEMAP_H

typedef struct CharMap {
    char mBrailleString[7];
    char mEnglishCharacter;
} CharMap;

#define BRAILLE_MAP_SIZE 33

static const CharMap _BRAILLE[BRAILLE_MAP_SIZE] = {
    {"O.....\0", 'a'},
    {"O.O...\0", 'b'},
    {"OO....\0", 'c'},
    {"OO.O..\0", 'd'},
    {"O..O..\0", 'e'},
    {"OOO...\0", 'f'},
    {"OOOO..\0", 'g'},
    {"O.OO..\0", 'h'},
    {".OO...\0", 'i'},
    {".OOO..\0", 'j'},
    {"O...O.\0", 'k'},
    {"O.O.O.\0", 'l'},
    {"OO..O.\0", 'm'},
    {"OO.OO.\0", 'n'},
    {"O..OO.\0", 'o'},
    {"OOO.O.\0", 'p'},
    {"OOOOO.\0", 'q'},
    {"O.OOO.\0", 'r'},
    {".OO.O.\0", 's'},
    {".OOOO.\0", 't'},
    {"O...OO\0", 'u'},
    {"O.O.OO\0", 'v'},
    {".OOO.O\0", 'w'},
    {"OO..OO\0", 'x'},
    {"OO.OOO\0", 'y'},
    {"O..OOO\0", 'z'},
    {"..O...\0", ','},
    {"..OO..\0", ':'},
    {"..OO.O\0", '.'},
    {"..OOO.\0", '!'},
    {"..O.OO\0", '?'},
    {".O..O.\0", '/'},
    {"......\0", ' '}
};

#endif