#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "source.h"

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
const int UP_KEY = 72;
const int DOWN_KEY = 80;
const int LEFT_KEY = 75;
const int RIGHT_KEY = 77;
const int SHOT_KEY = 32;
const int EXIT_KEY = 27;

enum TANK_DIRECTION
{
    SOUTH = 0,
    EAST,
    NORTH,
    WEST
};
void drawWheel(COORD pos, int symbol)
{
    if(pos.Y % 2 == 0)
    {
        printf("%c%c%c%c%c\n",178,178,(char)symbol,178,178);
    }else{
        printf("%c%c%c%c%c\n",176,176,(char)symbol,176,176);
    }

}
void drawWheelX(COORD pos)
{
    if(pos.Y % 2 == 0)
    {
        printf("%c%c%c%c%c%c%c%c",178,178,176,176,178,178,176,176);
    }else{
        printf("%c%c%c%c%c%c%c%c",176,176,178,178,176,176,178,178);
    }

}

void drawTankForDirectionUP()
{
    COORD drawPos = {10, 0};
    char symbol1 = 202;
    char symbol2 = 205;
    char symbol3 = 32;
    SetConsoleCursorPosition(hCon,drawPos);
    printf("  %c  \n",220);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    printf("  %c  \n",186);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheel(drawPos, symbol1);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheel(drawPos, symbol3);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheel(drawPos, symbol3);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheel(drawPos, symbol2);
}

void drawTankForDirectionDOWN()
{
    COORD drawPos = {10, 0};
    char symbol1 = 203;
    char symbol2 = 205;
    char symbol3 = 32;
    printf("\n");
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheel(drawPos, symbol2);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheel(drawPos, symbol3);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheel(drawPos, symbol3);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheel(drawPos, symbol1);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    printf("  %c  ",186);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    printf("  %c  ",223);

}

void drawTankForDirectionWEST()
{
    COORD drawPos = {10, 0};
    char symbol1 = 204;
    char symbol2 = 206;
    char symbol3 = 32;
    printf("\n");
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheelX(drawPos);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    printf("%c%c%c%c%c%c%c%c%c%c",186, 32, 32, 32, 32, 32, 32, 204, 205, 254);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheelX(drawPos);
    drawPos.Y++;

}
void drawTankForDirectionEAST()
{
    COORD drawPos = {10, 0};
    char symbol1 = 204;
    char symbol2 = 206;
    char symbol3 = 32;
    printf("\n");
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheelX(drawPos);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    printf("%c%c%c%c%c%c%c%c",185, 32, 32, 32, 32, 32, 32, 186);
    drawPos.Y++;
    SetConsoleCursorPosition(hCon,drawPos);
    drawWheelX(drawPos);
    drawPos.Y++;
}

void drawTankForDirection(TANK_DIRECTION tankDirection)
{
    switch(tankDirection)
    {
    case SOUTH:
        system("cls");
        drawTankForDirectionDOWN();
        break;
    case EAST:
        system("cls");
        drawTankForDirectionEAST();
        break;
    case NORTH:
        system("cls");
        drawTankForDirectionUP();
        break;
    case WEST:
        system("cls");
        drawTankForDirectionWEST();
        break;
    }

}
int main()
{
    system("mode con cols=165 lines=55");
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = true;


    SetConsoleCursorInfo(hCon, &cci);

    while(true){
    int ch = getch();

    switch(ch)
    {
        case UP_KEY:   //UP
            drawTankForDirection(NORTH);
        break;
        case DOWN_KEY: //DOWN
            drawTankForDirection(SOUTH);
        break;
        case LEFT_KEY: //LEFT
            drawTankForDirection(WEST);
        break;
        case RIGHT_KEY: //RIGHT
            drawTankForDirection(EAST);
        break;
        case SHOT_KEY:  //SHOT

        break;
        case EXIT_KEY:  //EXIT
        return 0;

    }
    }
    return 0;
}

