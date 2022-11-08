#include "c_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>



void
print_border(uint16 length, uint16 width, uint16 boll_x, uint16 boll_y, char border_type)
{
    assert(length <= 60);
    assert(width <= 20);
    uint16 x;
    uint16 y;

    for(x = 0; x < width; x++)
    {
        //�߽��ϲ�������
        if(x == 0 || x == width - 1)
        {
            for(y = 0; y < length; y++)
                printf("%c", border_type);
            printf("\n");
            continue;
        }
        for(y = 0; y < length; y++)
        {
            if( y == 0 || y == length-1)
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

    //����С��ı߿�
    sint16 top = 0;
    sint16 bottom = 20;
    sint16 left = 0;
    sint16 right = 60;

    sint16 velocity_x = 1;
    sint16 velocity_y = 1;

    //ÿһ��ѭ����ʱ����Ҫ���»��Ʊ߿�
    while(1 == 1)
    {
        x = x + velocity_x;
        y = y + velocity_y;
        system("cls");
        print_border(right - left, bottom - top, x, y, '-');
        //for(i = 0; i < y; i++)
        //    printf("\n");

        //for(j = 0; j < x; j++)
        //    printf(" ");

        //printf("o");
        //printf("\n");
        //Sleep(50);

        if((y == top) || (y == bottom))
            velocity_y = - velocity_y;

        if((x == left) || (x == right))
            velocity_x = - velocity_x;
    }
}