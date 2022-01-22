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