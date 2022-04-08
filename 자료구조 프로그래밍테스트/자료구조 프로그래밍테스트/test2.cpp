#include<iostream>
#include<string>

using namespace std;

#define HEIGHT 6
#define WIDTH 6
#define CROSS 10
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

		cout << "�̹� ���� �����ֽ��ϴ�." << endl;
	}
}
void RockCount() {

	int h_count[2][HEIGHT]{};  // 2 19 2 19 
	int w_count[2][WIDTH]{};
	// ���� ���� ���� ������ �ľ�.

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
	for (int i = 0; i < HEIGHT; i++) {
		cout << "�浹 ���� " << i << " ��° " << w_count[0][i] << " �� " << "\t";
		cout << "�浹 ���� " << i << " ��° " << h_count[0][i] << " �� " << endl;
	}
	for (int i = 0; i < HEIGHT; i++) {
		cout << "�鵹 ���� " << i << " ��°" << w_count[1][i] << " �� " << "\t";
		cout << "�鵹 ���� " << i << " ��°" << h_count[1][i] << " �� " << endl;
	}
}
void concheck() {
	int h_count[2][HEIGHT]{};
	int w_count[2][WIDTH]{};



	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 1; x < WIDTH; x++) {
			if (gameboard[y][x].compare("@") == 0) {
				if (gameboard[y][x].compare(gameboard[y][x - 1]) == 0) {

				}
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y][x - 1]) == 0) {

				}
			}
		}
	}
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 1; y < HEIGHT; y++) {
			if (gameboard[y][x].compare("@") == 0) {
				if (gameboard[y][x].compare(gameboard[y - 1][x]) == 0) {
					h_count[0][x]++;
				}
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y - 1][x]) == 0) {
					h_count[1][x]++;
				}
			}
		}
	}

	for (int i = 0; i < HEIGHT; i++)
	{
		if (w_count[0][i] > w_count[1][i] && w_count[0][i] > h_count[0][i]&&w_count[0][i]>h_count[1][i] )
		{
			cout << " �浹 ���� ���� ���� - " << i << "��° ��" << w_count[0][i] + 1 << " ��" << endl;
			tempbwcount = w_count[0][i];
		}
		else if (w_count[1][i] > w_count[0][i] && w_count[1][i] > h_count[0][i] && w_count[1][i] > h_count[1][i])
		{
			cout << " �鵹 ���� ���� ���� - " << i << "��° ��" << w_count[1][i] + 1 << " ��" << endl;
			tempwwcount = w_count[1][i];
		}
		else if (h_count[0][i] > w_count[0][i] && h_count[0][i] > w_count[1][i] && h_count[0][i] > h_count[1][i])
		{
			cout << " �浹 ���� ���� ���� - " << i << "��° ��" << h_count[0][i] + 1 << " ��" << endl;
		}
		else if (h_count[1][i] > w_count[0][i] && h_count[1][i] > w_count[1][i] && h_count[1][i] > h_count[0][i])
		{
			cout << " �鵹 ���� ���� ���� - " << i << "��° ��" << h_count[1][i] + 1 << " ��" << endl;
		}
	}
	if (tempbwcount > tempwwcount) {
		cout << " ���� ū ������ �����ϴ� ���� ��ǥ��" << endl;
	}
	
	
}
void diagcheck() {

	int rightdown[2][CROSS]{};
	int leftup[2][CROSS]{};

	int bcount{};
	int wcount{};


	for (int y = 1; y < HEIGHT; y++) {
		for (int x = 1; x < WIDTH; x++) {
			if (gameboard[y][x].compare("@") == 0) {
				if (gameboard[y][x].compare(gameboard[y - 1][x - 1]) == 0) {
					rightdown[0][x]++;
				}
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y - 1][x - 1]) == 0) {
					rightdown[1][x]++;
				}
			}
		}
	}
	for (int y = HEIGHT; y > 0; y--) {
		for (int x = 1; x < WIDTH; x++) {
			if (gameboard[y][x].compare("@") == 0) {
				if (gameboard[y][x].compare(gameboard[y + 1][x - 1]) == 0) {
					leftup[0][x]++;
				}
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y +1][x - 1]) == 0) {
					leftup[1][x]++;
				}
			}
		}
	}
	for (int i = 1; i < CROSS; i++) {
		if (rightdown[0][i] > rightdown[1][i])
			cout << "�밢�� ������ ���� (�浹)" << i << "��°" << rightdown[0][i] << " ��" << endl;
		else if(rightdown[1][i] > rightdown[0][i])
			cout << "�밢�� ������ ���� (�鵹)" << i << "��°" << rightdown[1][i] << " ��" << endl;
		else if (leftup[0][i] > leftup[1][i])
			cout << "�밢�� ������ ���� (�浹)" << i << "��°" << rightdown[0][i] << " ��" << endl;
		else if (leftup[1][i] > leftup[0][i])
			cout << "�밢�� ������ ���� (�鵹)" << i << "��°" << rightdown[1][i] << " ��" << endl;
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

		cout << " �浹�� ���� : " << black << endl;
		cout << " ���� ���� : " << white << endl;

		RockCount();
		concheck();
		diagcheck();
	}
	return 0;
}
