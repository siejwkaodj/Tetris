#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int, int);

int main(){
    int x, y;
    while(1){
        scanf(" %d %d", &x, &y);
        system("cls");
        gotoxy(x, y);
        printf("бр");
    }
    return 0;
}

void gotoxy(int x, int y){
      COORD Cur;
      Cur.X = x;
      Cur.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}