#include "c_game.h"
#include <conio.h>
#include <windows.h>

uint32 position_x, position_y;
uint32 bullet_x, bullet_y;
uint32 enemy_x, enemy_y;
uint32 high, width;
uint32 score;

void gotoxy(int x, int y)  //光标移动函数
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void hide_cursor() 
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 }; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

gbool	
game_init()
{
	high		= 20;
	width		= 30;
	position_x	= high / 2;
	position_y	= width / 2;
	bullet_x	= -2;
	bullet_y	= position_y;
	enemy_x		= 0;
	enemy_y		= position_y;
	score		= 0;

	hide_cursor();
	return TRUE;
}

void
show()
{
	gotoxy(0, 0);
	int i, j;
	for(i = 0; i < high; i++)
	{
		for(j = 0; j < width; j++)
		{
			if((i == position_x) && (j == position_y))
				printf("*"); 
			else if((i == enemy_x) && (j == enemy_y))
				printf("@"); 
			else if((i == bullet_x) && (j == bullet_y))
				printf("|"); 
			else
				printf(" "); 
		}
		printf("\n");
	}
	printf("your score: %d\n", score);
}

void
update_default()
{
	if(bullet_x > -1)
		bullet_x--;

	if((bullet_x == enemy_x) && (bullet_y == enemy_y))
	{
		score++;              
		enemy_x = -1;         
		enemy_y = rand() % width;
		bullet_x = -2;         
	}
	if(enemy_x > high)  
	{
		enemy_x = -1;      
		enemy_y = rand() % width;
	}

	static int speed = 0;
	if(speed < 20)
		speed++;
	if(speed == 20)
	{
		enemy_x++;
		speed = 0;
	}
}

void
update_input()
{
	char input;
	if(_kbhit()) 
	{
		input = _getch();  
		if(input == 'a')
			position_y--; 
		if(input == 'd')
			position_y++;  
		if(input == 'w')
			position_x--; 
		if(input == 's')
			position_x++;  
		if(input == ' ')  
		{
			bullet_x = position_x - 1; 
			bullet_y = position_y;
		}

	}
}

void
simple_plane_ex()
{
    game_init();
    while(TRUE)
    {
        show();//游戏显示
        update_default();//游戏默认行为
        update_input();//用户行为
    }
}