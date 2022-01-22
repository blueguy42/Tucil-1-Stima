#include <stdio.h>
#include "word.h"

void solveE (char **puzzle, int Row, int Col, int pRow, int pCol, char *word, int length, int *foundBool) {
    int i = pRow, j = pCol, k = 0;
    int bool = 1;

    while ((j < Col) && (k < length) && bool) {
        if (puzzle[i][j] != word[k]) {
            bool = 0;
        }
        j++;
        k++;
    }
    *foundBool = bool;
}

int main() {
    int i = 0, j = 0, k = 0;

    // Read filename of puzzle
    char filename[200];
    printf("Insert filename of puzzle (including the format): ");
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

        // Read rows and columns of puzzle matrix
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

        // Read puzzle matrix
        char puzzle[Row][Col];

        fp = fopen(filename, "r");
        c = cPrev = getc(fp);
        while ((c != '\n') || (cPrev != '\n')) {
            if (c != '\n' && c != ' ') {
                puzzle[i][j] = c;
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
                printf("%c ", puzzle[i][j]);
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

        for (i=0; i < wordcount; i++) {
            
        }

        
    }
    
    return 0;
}