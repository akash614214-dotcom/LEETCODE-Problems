#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int r[9][9] = {0};
    int c[9][9] = {0};
    int b[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int v = board[i][j] - '1';
                int k = (i / 3) * 3 + (j / 3);

                if (r[i][v] || c[j][v] || b[k][v]) {
                    return false;
                }

                r[i][v] = 1;
                c[j][v] = 1;
                b[k][v] = 1;
            }
        }
    }
    return true;
}