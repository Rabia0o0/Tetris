#define A_WIDTH 10 //Arena Width
#define A_HEIGHT 20 //Arena Height
#define T_WIDTH 2 //Tetromino Width
#define T_HEIGHT 4 //Tetromino height 

typedef struct {
    char *buffer;
    size_t buffLen;
    size_t byteLen;
}  BufferBuilder;

//Milliseconds between two clock_t values.
int getMs(clock_t start, clock_t end);

//Creating new Buffer.
BufferBuilder *bbCreate(size_t initialSize);

//Append a string to Buffer.
int bbAppend(BufferBuilder *bb, const char *str);

//Free a Buffer.
void bbFree(BufferBuilder *bb);

//Generate new Tetromino.
void newTetromino();

//To see if position is valid.
bool validPos(int tetromino, int rotation, int posX, int posY);

//Rotate Tetromino.
int rotate(int x, int y, int rotation);

//Process keyboard inputs.
void processInputs();

//Move Tetromino down.
bool moveDown();

//Add Tetromino to Arena.
void addToArena();

//Check if lines can be cleared.
void checkLines();

//Draw Arena.
void drawArena();
