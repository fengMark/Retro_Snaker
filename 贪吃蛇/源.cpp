#include<iostream>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define SNAKE_LENGTH 35*35
struct Snake{
	int x, y;
	int now;
}Snake_Node[SNAKE_LENGTH],Clear;
void showGame();
void AddRand();
void initGame();
void startGame();
bool eatFood();
void mouseLeft();
void mouseRight();
void mouseUp();
void mouseDown();
int score;
int best;
int map[35][35];
int head_x, head_y;
int length = 0;
int main(){
	initGame();
	startGame();
	return 0;
}
void AddRand(){
	srand((unsigned int)time(NULL));//添加食物
	int i, j;
	while (true){
		i = rand() % 35;
		j = rand() % 35;
		if (map[i][j] == 0){
			map[i][j] = 3;
			break;
		}
	}
}
void showGame(){
	printf("GAME:贪吃蛇\n\n");
	printf("score:%d\tbest:%d\n",score,best);
	printf("---------------------------------------------------------------------------\n\n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	for (int i = 0; i <35; i++)
	{
		printf("┃");
		for (int j = 0; j < 35; j++){
			if (map[i][j] == 2){
				printf("●");//蛇头
			}
			else if (map[i][j] == 3){
				printf("★");
			}
			else if (map[i][j] == 1){
				printf("■");//蛇节点
			}
			else if(map[i][j]==0){
				printf("  ");
			}
		}
		printf("┃\n");	
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("---------------------------------------------------------------------------\n\n");
	printf("W↑\tS↓\tA←\tD→");
}
void startGame(){
	while (true)
	{
		switch (getch())
		{
		case 'W':
		case 'w':mouseUp();
			break;
		case 'S':
		case 's':mouseDown();
			break;
		case 'A':
		case 'a':mouseLeft();
			break;
		case 'D':
		case 'd':mouseRight();
			break;
		default:
			break;
		}
		if (head_x<0 || head_x>34 || head_y<0 || head_y>34){
			break;
		}
		system("cls");
		map[Clear.x][Clear.y] = 0;//清除尾节点
		map[Snake_Node[0].x][Snake_Node[0].y] = 2;//新头节点赋值
		for (int i = 1; i < length; i++){
			map[Snake_Node[i].x][Snake_Node[i].y] = 1;
		}
		showGame();
	}
}
bool eatFood(){
	switch (Snake_Node[0].now)//判断蛇头方向的下一个是否有食物
	{
	case 1://上面有食物
		head_x--;
		if (map[head_x][head_y] == 3){
			Snake_Node[length+1].x = Snake_Node[length].x;
			Snake_Node[length+1].y = Snake_Node[length].y;
			Snake_Node[length+1].now = Snake_Node[length].now;
			length++;
			return true;//吃到上面的食物
		}
		break;
	case 2://下面有食物
		head_x++;
		if (map[head_x ][head_y] == 3){
			Snake_Node[length+1].x = Snake_Node[length].x;
			Snake_Node[length+1].y = Snake_Node[length].y;
			Snake_Node[length+1].now = Snake_Node[length].now;
			length++;
			return true;//吃到下面的食物
		}
		break;
	case 3://左面有食物
		head_y--;
		if (map[head_x ][head_y] == 3){
			Snake_Node[length+1].x = Snake_Node[length].x;
			Snake_Node[length+1].y = Snake_Node[length].y;
			Snake_Node[length+1].now = Snake_Node[length].now;
			length++;
			head_y--;
			return true;//吃到左面的食物
		}
		break;
	case 4://右面有食物
		head_y++;
		if (map[head_x ][head_y] == 3){
			Snake_Node[length+1].x = Snake_Node[length].x;
			Snake_Node[length+1].y = Snake_Node[length].y;
			Snake_Node[length+1].now = Snake_Node[length].now;
			length++;
			
			return true; //吃到右面面的食物
		}
		break;
	default:
		break;
	}
	return false;
}
void initGame(){
	int i, j;
	for (i = 0; i < 35; i++){
		for (j = 0; j < 35; j++){
			map[i][j] = 0;
		}
	}
	srand((unsigned int)time(NULL));
	head_x = rand() % 35;
	head_y = rand() % 35;
	Snake_Node[0].x = head_x;
	Snake_Node[0].y = head_y;
	Snake_Node[0].now = 0;//没有方向
	map[head_x][head_y] = 2;
	AddRand();
	showGame();
}
void mouseLeft(){//方向键按下：蛇头重新赋值新位置和方向；其他节点赋值上一个节点的位置和方向
	Snake_Node[0].now = 3;
	if (eatFood()){
		score += 1;
		AddRand();
	}
	for (int i = length; i > 0; i--){
		Snake_Node[i].now = Snake_Node[i - 1].now;
		Snake_Node[i].x = Snake_Node[i - 1].x;
		Snake_Node[i].y = Snake_Node[i - 1].y;
	}
	Clear.x = Snake_Node[length].x;
	Clear.y = Snake_Node[length].y;
	Snake_Node[0].y--;
}
void mouseRight(){
	Snake_Node[0].now = 4;
	if (eatFood()){
		score += 1;
		AddRand();
	}
	for (int i = length; i > 0; i--){
		Snake_Node[i].x = Snake_Node[i - 1].x;
		Snake_Node[i].y = Snake_Node[i - 1].y;
	}
	
	Clear.x = Snake_Node[length].x;
	Clear.y = Snake_Node[length].y;
	Snake_Node[0].y++;
}
void mouseUp(){
	Snake_Node[0].now = 1;
	if (eatFood()){
		score += 1;
		AddRand();
	}
	for (int i = length; i > 0; i--){
		Snake_Node[i].now = Snake_Node[i - 1].now;
		Snake_Node[i].x = Snake_Node[i - 1].x;
		Snake_Node[i].y = Snake_Node[i - 1].y;
	}
	Clear.x = Snake_Node[length].x;
	Clear.y = Snake_Node[length].y;
	Snake_Node[0].x--;
}
void mouseDown(){
	Snake_Node[0].now = 2;
	if (eatFood()){
		score += 1;
		AddRand();
	}
	for (int i = length; i > 0; i--){
		Snake_Node[i].now = Snake_Node[i - 1].now;
		Snake_Node[i].x = Snake_Node[i - 1].x;
		Snake_Node[i].y = Snake_Node[i - 1].y;
	}
	Clear.x = Snake_Node[length].x;
	Clear.y = Snake_Node[length].y;
	Snake_Node[0].x++;
}