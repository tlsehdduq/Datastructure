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


	if (gameboard[i_y][i_x] == '*')
	{

		if (turn % 2)
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
	else
	{
		for (y = 0; y < HEIGHT; y++)
		{
			for (x = 0; x < WIDTH; x++)
			{
				cout << gameboard[y][x];
				cout << " ";
			}
			cout << endl;
		}

		cout << "이미 돌이 놓여있습니다." << endl;
	}
}


int main()
{
	drawboard();

	int r_x = 0;
	int r_y = 0;

	int black = 0;
	int white = 0;
	
		while (1)
		{
			cin >> r_x;
			cin >> r_y;
			if (gameboard[r_y][r_x] == '*')
			{

				if (turn % 2) {

					black++;
				}
				else
				{
					white++;
				}
			}
			inputRock(r_x, r_y);

			cout << "검은돌의 개수 : " << black << endl;
			cout << "흰돌의 개수 : " << white << endl;

		}
	
}