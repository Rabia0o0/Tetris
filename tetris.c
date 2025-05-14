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