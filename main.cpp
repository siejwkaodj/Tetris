/*  20220813 Tetris Game Project - 한성준
*   
*/
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int, int);
void square(int, int, int, int);    // 외곽 출력
void printBlocks(int, int, int, int);   // □ 출력
void printScore(int score, int level, int lines);   // 점수 등 출력

int main(){
    square(47, 0, 71, 22);  // MAP
    printBlocks(49, 1, 69, 21);

    square(32, 0, 43, 5);   // HOLD
    printBlocks(34, 1, 41, 4);

    square(32, 15, 43, 22); // SCORE, LEVEL, LINES 출력
    printScore(0, 0, 0);
    
    square(73, 0, 84, 11);  // NEXT Block
    gotoxy(73, 1);
    printf("Next Blocks");
    printBlocks(75, 2, 81, 10);

    return 0;
}

void gotoxy(int x, int y){
      COORD Cur;
      Cur.X = x;
      Cur.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

void square(int x1, int y1, int x2, int y2){
    int i, j;
    // x방향 그리기
    for(j = x1; j <= x2; j++){
        gotoxy(j, y1);
        printf("─");
        gotoxy(j, y2);
        printf("─");
    }
    // y방향 그리기
    for(i = y1; i <= y2; i++){
        gotoxy(x1, i);
        printf("│");
        gotoxy(x2, i);
        printf("│");
    }
    gotoxy(x1, y1);
    printf("┌");
    gotoxy(x1, y2);
    printf("└");
    gotoxy(x2, y1);
    printf("┐");
    gotoxy(x2, y2);
    printf("┘");
    return;
}
void printBlocks(int x1, int y1, int x2, int y2){
    for(int i = y1; i <= y2; i++){
        for(int j = x1; j <= x2; j+=2){
            gotoxy(j, i);
            printf("□");
        }
    }
    return;
}
void printScore(int score, int level, int lines){
    // printBlocks(34, 16, 41, 21);
    gotoxy(34, 16);
    printf("Score");
    gotoxy(34, 17);
    printf("%10d", score);
    
    gotoxy(34, 18);
    printf("Level");
    gotoxy(34, 19);
    printf("%10d", level);

    gotoxy(34, 20);
    printf("Lines");
    gotoxy(34, 21);
    printf("%10d", lines);
    return;
}