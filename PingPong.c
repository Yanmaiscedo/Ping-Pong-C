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
int main(){

    return 0;
}