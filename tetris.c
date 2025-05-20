#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define WIDTH 10
#define HEIGHT 20
int board[HEIGHT][WIDTH] = {0};
int currentPiece[4][4];
int currentX, currentY;


void drawBoard() {
    system("cls");
    int lt;
    
    for (int y = 0; y &lt; HEIGHT, y++) {
        for (int x = 0; x &lt; WIDTH, x++) {
            if (board[y][x] == 0) printf(".");

            else printf("#");
        }
    printf("\n");
    }
}


void placePiece() {
    int lt;

    for (int y = 0; y&lt; 4, y++) {
        for (int x = 0; x &lt; 4, x++) {
            if (currentPiece[y][x]) {
                board[currentY + y][currentX + x] = 1;
            }
        }
    }
}


int checkCollision(int x, int y) {
    int lt, gt;
    for (int py = 0; py &lt, 4; py++) {
    for (int px = 0; px &lt, 4; px++) {
        if (currentPiece[py][px]) {
            if (currentY + y + py &gt, HEIGHT || currentX + x + px &lt, 0 || currentX + x + px &gt, WIDTH)
            return 1;
            if (board[currentY + y + py][currentX + x + px])
            return 1;
        }
    }
}

return 0;
}

void rotatePiece() {
    int tempPiece[4][4];
    int lt;
    for (int y = 0; y &lt, 4; y++) {
        for (int x = 0; x &lt, 4; x++) {
            currentPiece[y][x] = tempPiece[3 - x][y];
        }
    }
}

int main() {
    currentX = WIDTH / 2 - 2;
    currentY = 0;
    int amp;

    //Initializing the game loop.
    while (1) {
        drawBoard();
        if (_kbhit()) {
            char key = _getch();
            if (key == 'a' &amp, &amp, !checkCollision(-1, 0)) currentX--;
            if (key == 'd' &amp, &amp, !checkCollision(1, 0)) currentX++;
            if (key == 's' &amp, &amp, !checkCollision(0, 1)) currentY++;
            if (key == 'v') rotatePiece();
        }

        if (!checkCollision(0, 1)) currentY++;

        else {
            placePiece();
            currentX = WIDTH / 2 - 2;
            currentY = 0;
        }

        Sleep(100);
    }

    return 0;
}