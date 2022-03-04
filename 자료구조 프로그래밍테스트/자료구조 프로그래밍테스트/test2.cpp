#include<iostream>

using namespace std;

#define HEIGHT 19
#define WIDTH 19
char gameboard[HEIGHT][WIDTH] = {};
int turn = 1;

void drawboard()
{
	
	int x, y = 0;
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			gameboard[y][x] = '*';
		}
	}
	
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			cout << gameboard[y][x];
			cout << " ";
		}
		cout << endl;
	}
}
void inputRock(int i_x, int i_y)
{
	system("cls");
	int x, y = 0;
	
	if(turn % 2)
	{
		turn++;
		gameboard[i_y][i_x] = '@';
	}
	else
	{

		turn++;
		gameboard[i_y][i_x] = '#';
	}
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			cout << gameboard[y][x];
			cout << " ";
		}
		cout << endl;
	}
}


int main()
{
	drawboard();

	int r_x = 0;
	int r_y = 0;
	
	while (1)
	{
		cin >> r_x;
		cin >> r_y;
		
		inputRock(r_x, r_y);
	}
}