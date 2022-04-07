#include<iostream>
#include<string>

using namespace std;

#define HEIGHT 7
#define WIDTH 7
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
	for (int i = 0; i < 3; i++) {
		cout << "�浹����" << i << "��°" << w_count[0][i] << endl;
		cout << "�浹����" << i << "��°" << h_count[0][i] << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << "�鵹����" << i << "��°" << w_count[1][i] << endl;
		cout << "�鵹����" << i << "��°" << h_count[1][i] << endl;
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
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 1; y < HEIGHT; y++) {
			if (gameboard[y][x].compare("@") == 0) {
				if (gameboard[y][x].compare(gameboard[y-1][x]) == 0) {
					h_count[0][x]++;
				}
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y-1][x]) == 0) {
					h_count[1][x]++;
				}
			}
		}
	}


	for (int i = 0; i < HEIGHT; i++)
	{
		if (w_count[0][i] > w_count[1][i] && w_count[0][i] > h_count[0][i] && w_count[0][i] > h_count[1][i])
			cout << " �浹 ���� ���� ���� - " << i << "��° ��" << w_count[0][i] + 1 << "��" << endl;
		else if (w_count[1][i] > w_count[0][i] && w_count[1][i] > h_count[0][i] && w_count[1][i] > h_count[1][i])
			cout << " �鵹 ���� ���� ���� - " << i << "��° ��" << w_count[0][i] + 1 << "��" << endl;
		else if (h_count[0][i] > w_count[0][i] && h_count[0][i] > w_count[1][i] && h_count[0][i] > h_count[1][i])
			cout << " �浹 ���� ���� ���� - " << i << "��° ��" << w_count[0][i] + 1 << "��" << endl;
		else if(h_count[1][i] > w_count[0][i] && h_count[1][i] > w_count[1][i] && h_count[1][i] > h_count[0][i])
			cout << " �鵹 ���� ���� ���� - " << i << "��° ��" << w_count[0][i] + 1<< "��" << endl;
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

		cout << "�������� ���� : " << black << endl;
		cout << "���� ���� : " << white << endl;
		RockCount();
		concheck();
	}
	return 0;
}