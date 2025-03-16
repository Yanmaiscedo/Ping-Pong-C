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

int main(){

    return 0;
}