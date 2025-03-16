#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

typedef enum {
    STOP = 0, LEFT, UPLEFT, DOWNLEFT, RIGHT, UPRIGHT, DOWNRIGHT
} eDir;

typedef struct {
    int x, y;
    int originalX, originalY;
    eDir direction;
} Ball;

typedef struct {
    int x, y;
    int originalX, originalY;
} Paddle;

typedef struct {
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    int quit;
    Ball ball;
    Paddle player1;
    Paddle player2;
} GameManager;

void ResetBall(Ball *ball) {
    ball->x = ball->originalX;
    ball->y = ball->originalY;
    ball->direction = STOP;
}

void MoveBall(Ball *ball) {
    switch (ball->direction) {
        case LEFT: ball->x--; break;
        case RIGHT: ball->x++; break;
        case UPLEFT: ball->x--; ball->y--; break;
        case DOWNLEFT: ball->x--; ball->y++; break;
        case UPRIGHT: ball->x++; ball->y--; break;
        case DOWNRIGHT: ball->x++; ball->y++; break;
        default: break;
    }
}

void Draw(GameManager *gm) {
    system("cls");
    for (int i = 0; i < gm->width + 2; i++) printf("#");
    printf("\n");
    
    for (int i = 0; i < gm->height; i++) {
        for (int j = 0; j < gm->width; j++) {
            if (j == 0) printf("#");
            else if (gm->ball.x == j && gm->ball.y == i) printf("O");
            else if (gm->player1.x == j && (gm->player1.y <= i && i < gm->player1.y + 4)) printf("|");
            else if (gm->player2.x == j && (gm->player2.y <= i && i < gm->player2.y + 4)) printf("|");
            else printf(" ");
            if (j == gm->width - 1) printf("#");
        }
        printf("\n");
    }
    for (int i = 0; i < gm->width + 2; i++) printf("#");
    printf("\nScore 1: %d    Score 2: %d\n", gm->score1, gm->score2);
}

void Input(GameManager *gm) {
    if (_kbhit()) {
        char current = _getch();
        if (current == gm->up1 && gm->player1.y > 0) gm->player1.y--;
        if (current == gm->down1 && gm->player1.y < gm->height - 4) gm->player1.y++;
        if (current == gm->up2 && gm->player2.y > 0) gm->player2.y--;
        if (current == gm->down2 && gm->player2.y < gm->height - 4) gm->player2.y++;
        if (current == 'q') gm->quit = 1;
    }
}

int main(){

    return 0;
}