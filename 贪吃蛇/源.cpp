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
	srand((unsigned int)time(NULL));//���ʳ��
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
	printf("GAME:̰����\n\n");
	printf("score:%d\tbest:%d\n",score,best);
	printf("---------------------------------------------------------------------------\n\n");
	printf("��������������������������������������������������������������������������\n");
	for (int i = 0; i <35; i++)
	{
		printf("��");
		for (int j = 0; j < 35; j++){
			if (map[i][j] == 2){
				printf("��");//��ͷ
			}
			else if (map[i][j] == 3){
				printf("��");
			}
			else if (map[i][j] == 1){
				printf("��");//�߽ڵ�
			}
			else if(map[i][j]==0){
				printf("  ");
			}
		}
		printf("��\n");	
	}
	printf("��������������������������������������������������������������������������\n");
	printf("---------------------------------------------------------------------------\n\n");
	printf("W��\tS��\tA��\tD��");
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
		map[Clear.x][Clear.y] = 0;//���β�ڵ�
		map[Snake_Node[0].x][Snake_Node[0].y] = 2;//��ͷ�ڵ㸳ֵ
		for (int i = 1; i < length; i++){
			map[Snake_Node[i].x][Snake_Node[i].y] = 1;
		}
		showGame();
	}
}
bool eatFood(){
	switch (Snake_Node[0].now)//�ж���ͷ�������һ���Ƿ���ʳ��
	{
	case 1://������ʳ��
		head_x--;
		if (map[head_x][head_y] == 3){
			Snake_Node[length+1].x = Snake_Node[length].x;
			Snake_Node[length+1].y = Snake_Node[length].y;
			Snake_Node[length+1].now = Snake_Node[length].now;
			length++;
			return true;//�Ե������ʳ��
		}
		break;
	case 2://������ʳ��
		head_x++;
		if (map[head_x ][head_y] == 3){
			Snake_Node[length+1].x = Snake_Node[length].x;
			Snake_Node[length+1].y = Snake_Node[length].y;
			Snake_Node[length+1].now = Snake_Node[length].now;
			length++;
			return true;//�Ե������ʳ��
		}
		break;
	case 3://������ʳ��
		head_y--;
		if (map[head_x ][head_y] == 3){
			Snake_Node[length+1].x = Snake_Node[length].x;
			Snake_Node[length+1].y = Snake_Node[length].y;
			Snake_Node[length+1].now = Snake_Node[length].now;
			length++;
			head_y--;
			return true;//�Ե������ʳ��
		}
		break;
	case 4://������ʳ��
		head_y++;
		if (map[head_x ][head_y] == 3){
			Snake_Node[length+1].x = Snake_Node[length].x;
			Snake_Node[length+1].y = Snake_Node[length].y;
			Snake_Node[length+1].now = Snake_Node[length].now;
			length++;
			
			return true; //�Ե��������ʳ��
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
	Snake_Node[0].now = 0;//û�з���
	map[head_x][head_y] = 2;
	AddRand();
	showGame();
}
void mouseLeft(){//��������£���ͷ���¸�ֵ��λ�úͷ��������ڵ㸳ֵ��һ���ڵ��λ�úͷ���
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