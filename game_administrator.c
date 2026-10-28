
// 返回值: 0 未结束, 1 黑胜, 2 白胜, 3 和局
int check_game_over(int board[15][15], int step) {
    int i, j;
    int color = 0;
    int length = 0;

    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (board[i][j]) {
                if (length == 0) {
                    length = 1;
                    color = board[i][j];
                } else if (color == board[i][j]) {
                    length++;
                    if (length == 5) {
                        return color;
                    }
                } else if (color != board[i][j]) {
                    length = 1;
                    color = board[i][j];
                }
            } else {
                color = 0;
                length = 0;
            }
        }
        color = 0;
        length = 0;
    }

    for (j = 0; j < 15; j++) {
        for (i = 0; i < 15; i++) {
            if (board[i][j]) {
                if (length == 0) {
                    length = 1;
                    color = board[i][j];
                } else if (color == board[i][j]) {
                    length++;
                    if (length == 5) {
                        return color;
                    }
                } else if (color != board[i][j]) {
                    length = 1;
                    color = board[i][j];
                }
            } else {
                color = 0;
                length = 0;
            }
        }
        color = 0;
        length = 0;
    }

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 15-i; j++) {
            if (board[i+j][j]) {
                if (length == 0) {
                    length = 1;
                    color = board[i+j][j];
                } else if (color == board[i+j][j]) {
                    length++;
                    if (length == 5) {
                        return color;
                    }
                } else if (color != board[i+j][j]) {
                    length = 1;
                    color = board[i+j][j];
                }
            } else {
                color = 0;
                length = 0;
            }
        }
        color = 0;
        length = 0;
    }

    for (j = 1; j < 11; j++) {
        for (i = 0; i < 15-j; i++) {
            if (board[i][i+j]) {
                if (length == 0) {
                    length = 1;
                    color = board[i][i+j];
                } else if (color == board[i][i+j]) {
                    length++;
                    if (length == 5) {
                        return color;
                    }
                } else if (color != board[i][i+j]) {
                    length = 1;
                    color = board[i][i+j];
                }
            } else {
                color = 0;
                length = 0;
            }
        }
        color = 0;
        length = 0;
    }

    for (i = 4; i < 15; i++) {
        for (j = 0; j < i+1; j++) {
            if (board[i-j][j]) {
                if (length == 0) {
                    length = 1;
                    color = board[i-j][j];
                } else if (color == board[i-j][j]) {
                    length++;
                    if (length == 5) {
                        return color;
                    }
                } else if (color != board[i-j][j]) {
                    length = 1;
                    color = board[i-j][j];
                }
            } else {
                color = 0;
                length = 0;
            }
        }
        color = 0;
        length = 0;
    }

    for (j = 1; j < 11; j++) {
        for (i = 0; i < 15-j; i++) {
            if (board[14-i][i+j]) {
                if (length == 0) {
                    length = 1;
                    color = board[14-i][i+j];
                } else if (color == board[14-i][i+j]) {
                    length++;
                    if (length == 5) {
                        return color;
                    }
                } else if (color != board[14-i][i+j]) {
                    length = 1;
                    color = board[14-i][i+j];
                }
            } else {
                color = 0;
                length = 0;
            }
        }
        color = 0;
        length = 0;
    }

    return (step == 225) ? 3 : 0;
}
