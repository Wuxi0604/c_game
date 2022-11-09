#include "c_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>

void
print_border(uint16 length, uint16 width, uint16 boll_x, uint16 boll_y, char border_type)
{
    GAME_ASSERT(length <= 60);
    GAME_ASSERT(width <= 20);
    uint16 x;
    uint16 y;

    for(y = 0; y < width; y++)
    {
        //边界上不能有球
        if(y == 0 || y == width - 1)
        {
            for(x = 0; x < length; x++)
                printf("%c", border_type);
            printf("\n");
            continue;
        }
        for(x = 0; x < length; x++)
        {
            if( x == 0 || x == length-1)
                printf("%c", border_type);
            else if(boll_x == x && boll_y == y)
            {
                printf("o");
                Sleep(50);
            }else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int
main()
{
    //sint16 i, j;
    sint16 x = 5;
    sint16 y = 5;

    //定义小球的边框
    sint16 top = 0;
    sint16 bottom = 20;
    sint16 left = 0;
    sint16 right = 60;

    sint16 velocity_x = 1;
    sint16 velocity_y = 1;

    //每一次循环的时候都需要重新绘制边框
    while(1 == 1)
    {
        print_border(right - left, bottom - top, x, y, '-');
        //for(i = 0; i < y; i++)
        //    printf("\n");

        //for(j = 0; j < x; j++)
        //    printf(" ");

        //printf("o");
        //printf("\n");
        //Sleep(50);

        if((y == top + 1) || (y == bottom - 1))
            velocity_y = - velocity_y;

        if((x == left + 1) || (x == right - 1))
            velocity_x = - velocity_x;

        x = x + velocity_x;
        y = y + velocity_y;
        system("cls");
    }
}