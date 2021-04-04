#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#define SIZE 100
void initBoard(int board[ROW][COL], int row,int  col);
void show(int board[ROW][COL], int row, int  col);
void drawGraph(int board[ROW][COL], int row, int  col);
void playerMove(int board[ROW][COL], int row, int  col);
void  computerMove(int board[ROW][COL], int row, int  col);
int isWin(int board[ROW][COL], int row, int  col);