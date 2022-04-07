#include<iostream>
#include<string>

using namespace std;

#define HEIGHT 3
#define WIDTH 3
string gameboard[HEIGHT][WIDTH] = {};
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

	if (gameboard[i_y][i_x] == "*")
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
void RockCount() {

	int h_count[2][HEIGHT]{};  // 2 19 2 19 
	int w_count[2][WIDTH]{};
	// 가로 세로 돌의 개수를 파악.

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (gameboard[y][x].compare("@") == 0) {

				w_count[0][y]++;
				h_count[0][x]++;
			}
			else if (gameboard[y][x].compare("#") == 0) {
				w_count[1][y]++;
				h_count[1][x]++;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		cout << "흑돌가로" << i << "번째" << w_count[0][i] << endl;
		cout << "흑돌세로" << i << "번째" << h_count[0][i] << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << "백돌가로" << i << "번째" << w_count[1][i] << endl;
		cout << "백돌세로" << i << "번째" << h_count[1][i] << endl;
	}
}
void concheck() {
	int h_count[2][HEIGHT]{};
	int w_count[2][WIDTH]{};

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 1; x < WIDTH; x++) {
			if (gameboard[y][x].compare("@") == 0) {
				if (gameboard[y][x].compare(gameboard[y][x - 1]) == 0) {
					w_count[0][y]++;
				}
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y][x - 1]) == 0) {
					w_count[1][y]++;
				}
			}
		}
	}
	for (int i = 0; i < HEIGHT; i++)
	{
		cout << " 흑돌 가로 연속 개수 - " << i << "번째 줄" << w_count[0][i] << "개" << endl;
		cout << " 백돌 가로 연속 개수 - " << i << "번째 줄" << w_count[1][i] << "개" << endl;
	}
}

int main()
{
	drawboard();

	int r_x = 0;
	int r_y = 0;

	int black = 0;
	int white = 0;

	bool onoff = true;

	while (onoff)
	{
		cin >> r_x;
		cin >> r_y;
		if (gameboard[r_y][r_x] == "*")
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
		RockCount();
		concheck();
	}
	return 0;
}