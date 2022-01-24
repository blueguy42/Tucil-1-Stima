#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
   char word[1000];
   int length;
} Word;

typedef struct {
    char matrix[100][100];
    int row;
    int col;
} Matrix;

// Print matrix
void PrintMatrix (Matrix matrix) {
    int i, j;
    for (i=0; i < matrix.row; i++) {
        for (j=0; j < matrix.col; j++) {
                printf("%c ", matrix.matrix[i][j]);
            }
            printf("\n");
        }
}

// Make a copy of a matrix with '-' in every index
void CopyEmptyMatrix (Matrix original, Matrix *copy) {
    Matrix temp = original;
    int i, j;
    for (i=0; i < temp.row; i++) {
        for (j=0; j < temp.col; j++) {
            temp.matrix[i][j] = '-';
        }
    }
    *copy = temp;
}

void solveFirst (Matrix Puzzle, int pRow, int pCol, Word word, int *compare, int *firstFound) {
    int bool;
    if (Puzzle.matrix[pRow][pCol] != word.word[0]) {
        bool = 0;
    } else {
        bool = 1;
    }
    *compare = *compare + 1;
    *firstFound = bool;
}

void solveE (Matrix Puzzle, int pRow, int pCol, Word word, int *foundBool, int *compare) {
    Matrix Solution;
    CopyEmptyMatrix(Puzzle, &Solution);

    if (!*foundBool) {
        int bool, allFound, counter;
        counter = *compare;
        bool = 1;
        allFound = 0;
        Solution.matrix[pRow][pCol] = Puzzle.matrix[pRow][pCol];
        if (pCol < (Puzzle.col - word.length + 1)) {
            int i = pRow, j = pCol+1, k = 1;
            while ((k < word.length) && bool) {
                Solution.matrix[i][j] = Puzzle.matrix[i][j];
                if (Puzzle.matrix[i][j] != word.word[k]) {
                    bool = 0;
                } else {
                    if (k == word.length-1) {
                        allFound = 1;
                    }
                }
                j++;
                k++;
                counter++;
            }

            if (allFound) {
                PrintMatrix(Solution);
                printf("\n");
            }

            *foundBool = allFound;
            *compare = counter;
        }
    }
}

void solveSE (Matrix Puzzle, int pRow, int pCol, Word word, int *foundBool, int *compare) {
    Matrix Solution;
    CopyEmptyMatrix(Puzzle, &Solution);

    if (!*foundBool) {
        int bool, allFound, counter;
        counter = *compare;
        bool = 1;
        allFound = 0;
        Solution.matrix[pRow][pCol] = Puzzle.matrix[pRow][pCol];
        if ((pCol < (Puzzle.col - word.length + 1)) && (pRow < (Puzzle.row - word.length + 1))) {
            int i = pRow+1, j = pCol+1, k = 1;
            while ((k < word.length) && bool) {
                Solution.matrix[i][j] = Puzzle.matrix[i][j];
                if (Puzzle.matrix[i][j] != word.word[k]) {
                    bool = 0;
                } else {
                    if (k == word.length-1) {
                        allFound = 1;
                    }
                }
                i++;
                j++;
                k++;
                counter++;
            }

            if (allFound) {
                PrintMatrix(Solution);
                printf("\n");
            }

            *foundBool = allFound;
            *compare = counter;
        }
    }
}

void solveS (Matrix Puzzle, int pRow, int pCol, Word word, int *foundBool, int *compare) {
    Matrix Solution;
    CopyEmptyMatrix(Puzzle, &Solution);

    if (!*foundBool) {
        int bool, allFound, counter;
        counter = *compare;
        bool = 1;
        allFound = 0;
        Solution.matrix[pRow][pCol] = Puzzle.matrix[pRow][pCol];
        if (pRow < (Puzzle.row - word.length + 1)) {
            int i = pRow+1, j = pCol, k = 1;
            while ((k < word.length) && bool) {
                Solution.matrix[i][j] = Puzzle.matrix[i][j];
                if (Puzzle.matrix[i][j] != word.word[k]) {
                    bool = 0;
                } else {
                    if (k == word.length-1) {
                        allFound = 1;
                    }
                }
                i++;
                k++;
                counter++;
            }

            if (allFound) {
                PrintMatrix(Solution);
                printf("\n");
            }

            *foundBool = allFound;
            *compare = counter;
        }
    }
}

void solveSW (Matrix Puzzle, int pRow, int pCol, Word word, int *foundBool, int *compare) {
    Matrix Solution;
    CopyEmptyMatrix(Puzzle, &Solution);

    if (!*foundBool) {
        int bool, allFound, counter;
        counter = *compare;
        bool = 1;
        allFound = 0;
        Solution.matrix[pRow][pCol] = Puzzle.matrix[pRow][pCol];
        if ((pCol >= (word.length - 1)) && (pRow < (Puzzle.row - word.length + 1))) {
            int i = pRow+1, j = pCol-1, k = 1;
            while ((k < word.length) && bool) {
                Solution.matrix[i][j] = Puzzle.matrix[i][j];
                if (Puzzle.matrix[i][j] != word.word[k]) {
                    bool = 0;
                } else {
                    if (k == word.length-1) {
                        allFound = 1;
                    }
                }
                i++;
                j--;
                k++;
                counter++;
            }

            if (allFound) {
                PrintMatrix(Solution);
                printf("\n");
            }

            *foundBool = allFound;
            *compare = counter;
        }
    }
}

void solveW (Matrix Puzzle, int pRow, int pCol, Word word, int *foundBool, int *compare) {
    Matrix Solution;
    CopyEmptyMatrix(Puzzle, &Solution);

    if (!*foundBool) {
        int bool, allFound, counter;
        counter = *compare;
        bool = 1;
        allFound = 0;
        Solution.matrix[pRow][pCol] = Puzzle.matrix[pRow][pCol];
        if (pCol >= (word.length - 1)) {
            int i = pRow, j = pCol-1, k = 1;
            while ((k < word.length) && bool) {
                Solution.matrix[i][j] = Puzzle.matrix[i][j];
                if (Puzzle.matrix[i][j] != word.word[k]) {
                    bool = 0;
                } else {
                    if (k == word.length-1) {
                        allFound = 1;
                    }
                }
                j--;
                k++;
                counter++;
            }

            if (allFound) {
                PrintMatrix(Solution);
                printf("\n");
            }

            *foundBool = allFound;
            *compare = counter;
        }
    }
}

void solveNW (Matrix Puzzle, int pRow, int pCol, Word word, int *foundBool, int *compare) {
    Matrix Solution;
    CopyEmptyMatrix(Puzzle, &Solution);

    if (!*foundBool) {
        int bool, allFound, counter;
        counter = *compare;
        bool = 1;
        allFound = 0;
        Solution.matrix[pRow][pCol] = Puzzle.matrix[pRow][pCol];
        if ((pCol >= (word.length - 1)) && (pRow >= (word.length - 1))) {
            int i = pRow-1, j = pCol-1, k = 1;
            while ((k < word.length) && bool) {
                Solution.matrix[i][j] = Puzzle.matrix[i][j];
                if (Puzzle.matrix[i][j] != word.word[k]) {
                    bool = 0;
                } else {
                    if (k == word.length-1) {
                        allFound = 1;
                    }
                }
                i--;
                j--;
                k++;
                counter++;
            }

            if (allFound) {
                PrintMatrix(Solution);
                printf("\n");
            }

            *foundBool = allFound;
            *compare = counter;
        }
    }
}

void solveN (Matrix Puzzle, int pRow, int pCol, Word word, int *foundBool, int *compare) {
    Matrix Solution;
    CopyEmptyMatrix(Puzzle, &Solution);

    if (!*foundBool) {
        int bool, allFound, counter;
        counter = *compare;
        bool = 1;
        allFound = 0;
        Solution.matrix[pRow][pCol] = Puzzle.matrix[pRow][pCol];
        if (pRow >= (word.length - 1)) {
            int i = pRow-1, j = pCol, k = 1;
            while ((k < word.length) && bool) {
                Solution.matrix[i][j] = Puzzle.matrix[i][j];
                if (Puzzle.matrix[i][j] != word.word[k]) {
                    bool = 0;
                } else {
                    if (k == word.length-1) {
                        allFound = 1;
                    }
                }
                i--;
                k++;
                counter++;
            }

            if (allFound) {
                PrintMatrix(Solution);
                printf("\n");
            }

            *foundBool = allFound;
            *compare = counter;
        }
    }
}

void solveNE (Matrix Puzzle, int pRow, int pCol, Word word, int *foundBool, int *compare) {
    Matrix Solution;
    CopyEmptyMatrix(Puzzle, &Solution);

    if (!*foundBool) {
        int bool, allFound, counter;
        counter = *compare;
        bool = 1;
        allFound = 0;
        Solution.matrix[pRow][pCol] = Puzzle.matrix[pRow][pCol];
        if ((pCol < (Puzzle.col - word.length + 1)) && (pRow >= (word.length - 1))) {
            int i = pRow-1, j = pCol+1, k = 1;
            while ((k < word.length) && bool) {
                Solution.matrix[i][j] = Puzzle.matrix[i][j];
                if (Puzzle.matrix[i][j] != word.word[k]) {
                    bool = 0;
                } else {
                    if (k == word.length-1) {
                        allFound = 1;
                    }
                }
                i--;
                j++;
                k++;
                counter++;
            }

            if (allFound) {
                PrintMatrix(Solution);
                printf("\n");
            }

            *foundBool = allFound;
            *compare = counter;
        }
    }
}

int main() {
    clock_t time;
    int i = 0, j = 0, k = 0, l = 0;

    printf("====================================\n");
    printf("WELCOME TO WORD SEARCH PUZZLE SOLVER\n");
    printf("by 13520023 - Ahmad Alfani Handoyo\n");
    printf("====================================\n\n");
    

    // Read filename of puzzle
    char directory[] = "../test/";
    char filename[200];
    printf("Insert filename of puzzle (including the format): ");
    scanf("%s", filename);
    strcat(directory,filename);


    // Read file
    char c, cPrev;
    int Row = 0, Col = 0;
    int foundRow = 0;
    FILE *fp = fopen(directory, "r");

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
        Matrix Puzzle;
        Puzzle.row = Row;
        Puzzle.col = Col;

        fp = fopen(directory, "r");
        c = cPrev = getc(fp);
        while ((c != '\n') || (cPrev != '\n')) {
            if (c != '\n' && c != ' ') {
                Puzzle.matrix[i][j] = c;
                j++;
                if (j == Col) {
                    j = 0;
                    i++;
                }
            }
            cPrev = c;
            c = getc(fp);
        }

        // Print puzzle
        PrintMatrix(Puzzle);

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
        words[wordcount].length = wordlength;
        wordcount++;
        fclose(fp);

        // Print words
        printf("\nKEYWORDS:\n");
        for (i=0; i < wordcount; i++) {
            printf("%d. ", i+1);
            for (j = 0; j < words[i].length; j++) {
                printf("%c",words[i].word[j]);
            }
            printf("\n");
        }
        printf("\n");

        // Brute-Force Algorithm
        printf("----------------------------\n");
        printf("         SOLUTIONS\n");
        printf("----------------------------\n");
        time = clock();
        int found, firstFound, compare = 0;
        for (i=0; i < wordcount; i++) {
            printf("%d. ", i+1);
            for (l = 0; l < words[i].length; l++) {
                printf("%c",words[i].word[l]);
            }
            printf("\n");

            found = 0;
            j = 0;
            while (j < Row && !found) {
                k = 0;
                while (k < Col && !found) {
                    solveFirst(Puzzle, j, k, words[i], &compare, &firstFound);
                    if (firstFound) {
                        solveE(Puzzle, j, k, words[i], &found, &compare);
                        solveSE(Puzzle, j, k, words[i], &found, &compare);
                        solveS(Puzzle, j, k, words[i], &found, &compare);
                        solveSW(Puzzle, j, k, words[i], &found, &compare);
                        solveW(Puzzle, j, k, words[i], &found, &compare);
                        solveNW(Puzzle, j, k, words[i], &found, &compare);
                        solveN(Puzzle, j, k, words[i], &found, &compare);
                        solveNE(Puzzle, j, k, words[i], &found, &compare);
                    }
                    k++;
                }
                j++;
            }
            if (!found) {
                printf("Word is not found in the puzzle\n\n");
            }
        }
        time = clock() - time;
        double time_consumed = ((double) time)/CLOCKS_PER_SEC;
        printf("----------------------------\n");
        printf("         STATISTICS\n");
        printf("----------------------------\n");
        printf("TOTAL LETTER COMPARISON: %d LETTERS\n", compare);
        printf("TOTAL TIME TAKEN: %f seconds\n\n", time_consumed);
        
        
    }
    
    return 0;
}