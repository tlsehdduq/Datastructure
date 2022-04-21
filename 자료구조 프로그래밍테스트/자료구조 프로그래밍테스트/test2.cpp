#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#define HEIGHT 19
#define WIDTH 19
#define CROSS 40
string gameboard[HEIGHT][WIDTH] = {};
int turn = 1;

struct Stone {
	int x, y;
	string stone;
};
struct Node {
	Stone Data;
	Node* Next;
};

void getStack(Node** head, int x, int y, bool turn) {
	Node* New = new Node;
	New->Data.x = x;
	New->Data.y = y;
	if (turn == false) {
		New->Data.x = '@';
	}
	else
		New->Data.x = '@';
	if (*head == NULL) {
		New->Next = NULL;
		*head = New;
	}
	else
	{
		New->Next = *head;
		*head = New;
	}
}
void backStack(Node** cancle, Node** head, int* x, int* y) {
	Node* New = new Node;
	Node* p;
	p = *cancle;
	if (*cancle == NULL)
	{
		New->Next = NULL;
		*cancle = New;
	}
	else
	{
		New->Next = *cancle;
		*cancle = New;
	}
	New->Data.x = p->Data.x;
	New->Data.y = p->Data.y;
	New->Data.stone = p->Data.stone;

	*x = p->Data.x;
	*y = p->Data.y;

	*head = p->Next;

	delete p;
}
void cancle(Node** cancle, Node** head, int* x, int* y) {
	Node* New = new Node;
	Node* p;
	p = *cancle;
	if (*head == NULL)
	{
		New->Next = NULL;
		*head = New;
	}
	else
	{
		New->Next = *head;
		*head = New;
	}
	New->Data.x = p->Data.x;
	New->Data.y = p->Data.y;
	New->Data.stone = p->Data.stone;

	*x = p->Data.x;
	*y = p->Data.y;

	*cancle = p->Next;

	delete p;
}
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
	ofstream out("Test2.txt");
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

	int h_count[2][HEIGHT]{};
	int w_count[2][WIDTH]{};

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
		if (w_count[0][i] > 0) {
			cout << "흑돌 가로 " << i << " 번째 " << w_count[0][i] << " 개 " << endl;
		}
		if (h_count[0][i] > 0) {
			cout << "흑돌 세로 " << i << " 번째 " << h_count[0][i] << " 개 " << endl;
		}
	}
	for (int i = 0; i < HEIGHT; i++) {
		if (w_count[1][i] > 0) {
			cout << "백돌 가로 " << i << " 번째" << w_count[1][i] << " 개 " << endl;
		}
		if (h_count[1][i] > 0) {
			cout << "백돌 세로 " << i << " 번째" << h_count[1][i] << " 개 " << endl;
		}
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
				else
					w_count[0][y] = 0;
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y][x - 1]) == 0) {
					w_count[1][y]++;
				}
				else
					w_count[1][y] = 0;
			}
		}
	}
	for (int x = 0; x < WIDTH; x++) {
		for (int y = 1; y < HEIGHT; y++) {
			if (gameboard[y][x].compare("@") == 0) {
				if (gameboard[y][x].compare(gameboard[y - 1][x]) == 0) {
					h_count[0][x]++;
				}
				else
					h_count[0][x] = 0;
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y - 1][x]) == 0) {
					h_count[1][x]++;
				}
				else
					h_count[1][x] = 0;
			}
		}
	}

	for (int i = 0; i < HEIGHT; i++)
	{
		if (w_count[0][i] > w_count[1][i] && w_count[0][i] > h_count[0][i] && w_count[0][i] > h_count[1][i])
		{
			cout << " 흑돌 가로 연속 개수 - " << i << "번째 줄" << w_count[0][i] + 1 << " 개" << endl;

		}
		else if (w_count[1][i] > w_count[0][i] && w_count[1][i] > h_count[0][i] && w_count[1][i] > h_count[1][i])
		{
			cout << " 백돌 가로 연속 개수 - " << i << "번째 줄" << w_count[1][i] + 1 << " 개" << endl;

		}
		else if (h_count[0][i] > w_count[0][i] && h_count[0][i] > w_count[1][i] && h_count[0][i] > h_count[1][i])
		{
			cout << " 흑돌 세로 연속 개수 - " << i << "번째 줄" << h_count[0][i] + 1 << " 개" << endl;
		}
		else if (h_count[1][i] > w_count[0][i] && h_count[1][i] > w_count[1][i] && h_count[1][i] > h_count[0][i])
		{
			cout << " 백돌 세로 연속 개수 - " << i << "번째 줄" << h_count[1][i] + 1 << " 개" << endl;
		}
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
				else
					rightdown[0][x] = 0;
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y - 1][x - 1]) == 0) {
					rightdown[1][x]++;
				}
				else
					rightdown[1][x] = 0;
			}
		}
	}
	for (int y = HEIGHT; y > 1; y--) {
		for (int x = 1; x < WIDTH; x++) {
			if (gameboard[y][x].compare("@") == 0) {
				if (gameboard[y][x].compare(gameboard[y + 1][x - 1]) == 0) {
					leftup[0][x]++;
				}
				else
					leftup[0][x] = 0;
			}
			else if (gameboard[y][x].compare("#") == 0) {
				if (gameboard[y][x].compare(gameboard[y + 1][x - 1]) == 0) {
					leftup[1][x]++;
				}
				else
					leftup[1][x] = 0;
			}
		}
	}

	for (int i = 1; i < CROSS; i++) {
		if (rightdown[0][i] > rightdown[1][i])
			cout << "대각선 연속의 개수 (흑돌)" << i << "번째" << rightdown[0][i] + 1 << " 개" << endl;
		else if (rightdown[1][i] > rightdown[0][i])
			cout << "대각선 연속의 개수 (백돌)" << i << "번째" << rightdown[1][i] + 1 << " 개" << endl;
		else if (leftup[0][i] > leftup[1][i])
			cout << "대각선 연속의 개수 (흑돌)" << i << "번째" << rightdown[0][i] + 1 << " 개" << endl;
		else if (leftup[1][i] > leftup[0][i])
			cout << "대각선 연속의 개수 (백돌)" << i << "번째" << rightdown[1][i] + 1 << " 개" << endl;
	}
}


int main()
{
	drawboard();

	Node* head = NULL;
	Node* canclehead = NULL;

	int r_x = 0;
	int r_y = 0;

	int black = 0;
	int white = 0;

	bool onoff = true;
	bool ox = true;

	char Mode;

	while (onoff)
	{
		switch (Mode) {
		case 'O':
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

			cout << " 흑돌의 개수 : " << black << endl;
			cout << " 흰돌의 개수 : " << white << endl;

			getStack(&head, r_x, r_y,turn);
			RockCount();
			concheck();
			diagcheck();
			break;
		case 'u':
			backStack(&canclehead, &head, &r_x, &r_y);
			gameboard[r_x][r_y] = "*";
			drawboard();
			break;
		case 'r':
			cancle(&canclehead, &head, &r_x, &r_y);


		}
	}

}