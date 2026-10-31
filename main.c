/*
 *棋局信息: 棋盘(由15 * 15数组表示) 步数
 *棋局管理: 判断胜负
 *基础机器算法: MAXMIN算法 评估函数 节点生成
 *进阶机器算法: alpha-beta剪枝 节点排序算法
 */
#include "main.h"

int main(void) {

    // 获取先后手信息
    int player;
    printf("Welcome to Gobang!\nChoose your color(1: black 2: white):");
    scanf("%d", &player);

    // 初始化对局
    int step = 0;
    int board[15][15];  // 棋盘信息: 0 空位置, 1 黑子, 2 白子
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            board[i][j] = 0;
        }
    }

    // 游戏运行
    int x = 0;
    int y = 0;
    int user_x, user_y;
    int *machine_place;
    int game_result = 0;
    while ( ! check_game_over(board, step)) {

        system("cls");
        if (step != 0) {
            user_x = x + 1;
            user_y = y + 1;
            printf("The position for placing the piece is %d %d.\n", user_x, user_y);
        }
        print_board(board);

        // 获取落子位置
        if ((player == 1 && step % 2 == 0) || (player == 2 && step % 2 != 0)) {

            printf("Please enter the position for placing the piece(x y):");
            scanf("%d %d", &user_x, &user_y);
            x = user_x - 1;
            y = user_y - 1;
        } else {
            printf("Machine thinking...\n");
            machine_place = machine(board, step);
            x = machine_place[0];
            y = machine_place[1];
            free(machine_place);
        }

        // 更新棋盘信息
        board[x][y] = (step % 2) ? 2 : 1;
        step++;
    }

    // 打印游戏结局信息
    system("cls");
    user_x = x + 1;
    user_y = y + 1;
    printf("The position for placing the piece is %d %d.\n", user_x, user_y);
    print_board(board);

    game_result = check_game_over(board, step);
    if (game_result == 1) {
        printf("The black win!\n");
    } else if (game_result == 2) {
        printf("The white win!\n");
    } else {
        printf("Draw!\n");
    }

    system("pause");

    return 0;
}
