#include <stdio.h>
#include "word.h"

int main() {
    int i = 0, j = 0, k = 0;

    // Read filename of crossword
    char filename[200];
    printf("Insert filename of crossword (including the format): ");
    scanf("%s", filename);

    // Read file
    char c, cPrev;
    int Row = 0, Col = 0;
    int foundRow = 0;
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("No such file with name %s is found!\n", filename);
    } else {
        printf("----------------------------\n");
        printf("     WORD SEARCH PUZZLE\n");
        printf("----------------------------\n");

        // Read rows and columns of crossword matrix
        c = cPrev = getc(fp);
        while ((c != '\n') || (cPrev != '\n')) {
            if (c == '\n') {
                foundRow = 1;
                Row++;
            }
            if (!foundRow && c != ' ') {
                Col++;
            }
            cPrev = c;
            c = getc(fp);
        }
        fclose(fp);
        printf("%d ROWS and %d COLUMNS\n\n", Row, Col);

        // Read crossword matrix
        char CROSSWORD[Row][Col];

        fp = fopen(filename, "r");
        c = cPrev = getc(fp);
        while ((c != '\n') || (cPrev != '\n')) {
            if (c != '\n' && c != ' ') {
                CROSSWORD[i][j] = c;
                j++;
                if (j == Col) {
                    j = 0;
                    i++;
                }
            }
            cPrev = c;
            c = getc(fp);
        }

        // Print array
        for (i=0; i < Row; i++) {
            for (j=0; j < Col; j++) {
                printf("%c ", CROSSWORD[i][j]);
            }
            printf("\n");
        }

        printf("\nWORDS:\n");
        // Read words
        int wordcount = 0, wordlength = 0;
        Word words[30];
        c = getc(fp);
        while (c != EOF) {
            if (c == '\n') {
                words[wordcount].length = wordlength;
                wordcount++;
                wordlength = 0;
            } else {
                words[wordcount].word[wordlength] = c;
                wordlength++;
            }
            c = getc(fp);
        }
        fclose(fp);

        // Print words
        for (i=0; i < wordcount; i++) {
            printf("%d. ", i+1);
            for (j = 0; j < words[i].length; j++) {
                printf("%c",words[i].word[j]);
            }
            printf("\n");
        }
        printf("\n");



        
    }
    
    return 0;
}