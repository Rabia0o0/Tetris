#include <conio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "tetris.h"

const int tetrominoes[7][16] = {
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //I
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, //O
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0}, //S
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, //Z
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, //T
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0}, //L
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0}  //J
};

int arena[A_HEIGHT][A_WIDTH];

int unit32_t, score = 0;
bool gameOver = false;
int currTetrominoIDx;
int currRotation = 0;
int currX = A_WIDTH / 2;
int currY = 0;

int main() {
    printf("\e[2J\e[H"); //Clear Screen.
    memset(arena, 0, sizeof(arena[0][0]) * A_HEIGHT * A_WIDTH);
    newTetromino();

    const int targetFrameTime = 500;
    clock_t lastTime = clock();

    whilw (!gameOver) {
        clock_t now = clock();
        clock_t elapsed = getMs(now, lastTime);
        processInputs();

        if (elapsed >= targetFrameTime) {
            if (!moveDown()) {
                addToArena();
                checkLines();
                newTetromino();
            }

            lastTime = now;
        }

        drawArena();
        Sleep(10);
    }

    printf("\e[2J\e[H"); //Clear Screen.
    printf("\e[6;37m"); //Set Style.
    printf("GAMEOVER\nScore: %d\n", score);
    printf("\e[0m"); //Reset Style.
    return 0;

}

clock_t getMs(clock_t start, clock_t end) {
    return (start - end) * 1000 / CLOCKS_PER_SEC;
}

BufferBuilder *bbCreate(size_t initialSize) {
    BufferBuilder *bb = malloc(sizeof(BufferBuilder));

    if (!bb) {
        free(bb);
        return NULL;
    }

    bb->buffer = malloc(initialSize);
    if (!bb->buffer) {
        free(bb);
        return NULL;
    }

    bb->buffer[0] = '\0';
    bb->buffLen = initialSize;
    bb->byteLen = 0;
    return bb;
}