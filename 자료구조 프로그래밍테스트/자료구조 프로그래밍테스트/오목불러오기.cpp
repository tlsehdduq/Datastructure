
#include<iostream>
#include<fstream>

#define BOARD_SIZE 19

using namespace std;

struct OMOK {
	char a;
	bool b;
};

struct omokstack {
	int scanx, scany;
	char scanOX;
};

struct NODE {
	NODE* Next;
	omokstack data;
};


void getstack(NODE** head, int x, int y, bool turn)
{
	NODE* newnode = new NODE;
	newnode->data.scanx = x;
	newnode->data.scany = y;
	if (turn == false)
	{
		newnode->data.scanOX = 'O';
	}
	else
	{
		newnode->data.scanOX = 'X';
	}
	if (*head == NULL)
	{
		newnode->Next = NULL;
		*head = newnode;
	}
	else
	{
		newnode->Next = *head;
		*head = newnode;
	}
}

void backstack(struct NODE** cancle, struct NODE** head, int* x, int* y)
{
	NODE* newnode = new NODE;
	NODE* p;
	p = *head;
	if (*cancle == NULL)
	{
		newnode->Next = NULL;
		*cancle = newnode;
	}
	else
	{
		newnode->Next = *cancle;
		*cancle = newnode;
	}
	newnode->data.scanx = p->data.scanx;
	newnode->data.scany = p->data.scany;
	newnode->data.scanOX = p->data.scanOX;

	*x = p->data.scanx;
	*y = p->data.scany;

	*head = p->Next;
	delete p;
}

void cancelback(struct NODE** cancle, struct NODE** head, int* x, int* y)
{
	struct NODE* newnode = new NODE;
	struct NODE* p;

	p = *cancle;

	if (*head == NULL)
	{
		newnode->Next = NULL;
		*head = newnode;
	}
	else
	{
		newnode->Next = *head;
		*head = newnode;
	}
	newnode->data.scanx = p->data.scanx;
	newnode->data.scany = p->data.scany;
	newnode->data.scanOX = p->data.scanOX;

	*x = p->data.scanx;
	*y = p->data.scany;

	*cancle = p->Next;
	delete p;
}

int main()
{
	NODE* head = NULL;
	NODE* cancelhead = NULL;
	OMOK arr[BOARD_SIZE][BOARD_SIZE];

	int inputx = -1, inputy = -1;
	char button;
	bool turn = true;
	bool loop = true;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			arr[i][j].a = '*';

			cout << arr[i][j].a << " ";

			arr[i][j].b = false;
		}
		cout << endl;
	}


	while (loop)
	{

		cout << "오목돌 입력 : O , 오목돌 무르기 : U,  오목돌 무르기 취소 : R , 불러오기 : L,  오목판 저장후 종료 : X" << endl;
		cin >> button;
		switch (button)
		{
		case 'l':
		{
			ifstream in{ "test.txt" };
			while (!in.eof())
			{
				NODE* p = head;

				NODE* newnode = new NODE;
				in >> newnode->data.scany;
				in >> newnode->data.scanx;
				in >> newnode->data.scanOX;
				if (newnode->data.scanx == -1)
				{
					delete newnode;
					break;
				}

				else if (head == NULL)
				{
					arr[newnode->data.scany][newnode->data.scanx].a = newnode->data.scanOX;
					arr[newnode->data.scany][newnode->data.scanx].b = true;
					if (newnode->data.scanOX == 'O')
					{
						turn = false;
					}
					else
					{
						turn = true;
					}

					newnode->Next = NULL;
					head = newnode;
					p = head;
				}
				else if (head != NULL)
				{
					if (p != NULL)
					{
						arr[newnode->data.scany][newnode->data.scanx].a = newnode->data.scanOX;
						arr[newnode->data.scany][newnode->data.scanx].b = true;
						if (newnode->data.scanOX == 'O')
						{
							turn = false;
						}
						else
						{
							turn = true;
						}
						newnode->Next = NULL;
						p->Next = newnode;
						p = p->Next;
					}
				}

			}

			for (int i = 0; i < BOARD_SIZE; i++)
			{
				for (int j = 0; j < BOARD_SIZE; j++)
				{
					cout << arr[i][j].a << " ";
				}
				cout << endl;
			}
			break;
		}
		case 'o':
		
			cout << "좌표 값을 입력하세요 : " << endl;
			cin >> inputx >> inputy;

			if ((inputx > 18 || inputx < 0) || (inputy > 18 || inputy < 0))
			{
				cout << "범위를 넘었습니다." << endl;
				break;
			}

			if (arr[inputy][inputx].b == true)
			{
				cout << "이미 돌이 놓여져 있습니다. " << endl;
				break;
			}

			else
			{
				if (turn == true)
				{
					arr[inputy][inputx].a = 'O';
					arr[inputy][inputx].b = true;
					turn = false;
				}

				else
				{
					arr[inputy][inputx].a = 'X';
					arr[inputy][inputx].b = true;
					turn = true;
				}
			}

			getstack(&head, inputx, inputy, turn);

			for (int i = 0; i < BOARD_SIZE; i++)
			{
				for (int j = 0; j < BOARD_SIZE; j++)
				{
					cout << arr[i][j].a << " ";
				}
				cout << endl;
			}
			break;
		
		case 'u':
		
			backstack(&cancelhead, &head, &inputx, &inputy);

			arr[inputy][inputx].a = '*';
			arr[inputy][inputx].b = false;

			for (int i = 0; i < BOARD_SIZE; i++)
			{
				for (int j = 0; j < BOARD_SIZE; j++)
				{
					cout << arr[i][j].a << " ";
				}
				cout << endl;
			}
			break;
		
		case 'r':
		
			cancelback(&cancelhead, &head, &inputx, &inputy);
			if (turn == false)
			{
				arr[inputy][inputx].a = 'O';
				arr[inputy][inputx].b = true;
				turn = true;
			}
			else
			{
				arr[inputy][inputx].a = 'X';
				arr[inputy][inputx].b = true;
				turn = false;
			}
			for (int i = 0; i < BOARD_SIZE; i++)
			{
				for (int j = 0; j < BOARD_SIZE; j++)
				{
					cout << arr[i][j].a << " ";
				}
				cout << endl;;
			}
			break;
		
		case 'x':
			loop = false;
			break;
		
		}
	}
	ofstream out{ "test.txt" };
	NODE* k = head;
	for (; k->Next != NULL; k = k->Next)
	{
		out << k->data.scany;
		out << k->data.scanx;
		out << k->data.scanOX;
	}
	out << k->data.scany;
	out << k->data.scanx;
	out << k->data.scanOX;

}