#include <stdio.h>
 
void countRowCol(char *NAME, int *ROW, int *COL) {
    int c, row, col, foundRow, foundMatrix, lastCharNL;

    row = 0;
    col = 0;
    foundRow = 0;
    foundMatrix = 0;
    lastCharNL = 0;

    FILE *fp = fopen(NAME, "r");

    c = getc(fp);
    // Figure out how many rows and columns the text file has
    while (c != EOF)
    {
        if (!foundMatrix) {
            if (c == '\n') {
                lastCharNL = 1;
                row++;
                foundRow = 1;
            } else {
                lastCharNL = 0;
            }

            if (c != ' ' && !foundRow) {
                col++;
            }
        }
        c = getc(fp);
        if (lastCharNL && c == '\n') {
            foundMatrix = 1;
        }
    }
    fclose(fp);

    *ROW = row;
    *COL = col;
}

int main()
{
    int c, row, col, i, j;

    countRowCol("file.txt", &row, &col);
    printf("Row: %d, Column: %d\n\n", row, col);

    // Read letters into array
    FILE *fp = fopen("file.txt", "r");

    char arr[row][col];

    i = 0;
    j = 0;
    while (i < row) {
        c = getc(fp);
        if (c != '\n' && c != ' ') {
            arr[i][j] = c;
            j++;
            if (j == col) {
                j = 0;
                i++;
            }
        }
    }

    // Print array
    for (i=0; i < row; i++) {
        for (j=0; j < col; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    while (c != EOF) {
        c = getc(fp);
        putchar(c);
    }
    fclose(fp);

    
}