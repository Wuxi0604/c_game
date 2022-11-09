#include "c_game.h"
#include <conio.h>

void
simple_plane()
{
    uint16 i;
    uint16 j;
    char   input;

    uint16 target    = 5;
    gbool  is_fire   = FALSE;
    uint16 x         = 5;
    uint16 y         = 10;
    gbool  is_killed = FALSE;

    while(TRUE)
    {
        system("cls");

        if(!is_killed)
        {
            for(j = 0; j < target; j++)
                printf(" ");
            printf("+\n");
        }

        if(is_fire)
        {
            for(i = 0; i < x; i++)
                printf("\n");
        }else
        {
            for(i = 0; i < x; i++)
            {
                for(j = 0; j < y; j++)
                    printf(" ");

                printf("  |\n");
            }
            if(y + 2 == target)
                is_killed = TRUE;
            is_fire = FALSE;
        }

        for(j = 0; j < y; j++)
            printf(" ");

        printf("  *\n");
        for(j = 0; j < y; j++)
            printf(" ");

        printf("*****\n");
        for(j = 0; j < y; j++)
            printf(" ");

        printf(" * * \n");

        //·Ç×èÈûÊ½
        if(_kbhit())
        {
            input = _getch();
            if(input == 'a')
                y--;
            if(input == 'd')
                y++;
            if(input == 'w')
                x--;
            if(input == 's')
                x++;
            if(input == ' ')
                is_fire = TRUE;
        }
    }
}
