#include<iostream>
#include<string>
#include<Windows.h>
#define MAX_LIST 10

using namespace std;

void Search();
void Insert();
void Delete();
void PrintAll();

struct LoLdict
{	
	string Name;
	int HP;
	int MP;
	int Speed;
	int Range;
	string Position;
};

LoLdict List[MAX_LIST] = {

	{"����",200,300,200,100,"TOP"},
	{"������",200,300,200,100,"TOP"},
	{"�ٸ��콺",200,300,200,100,"TOP" },
	{"�ǿ���",200,300,200,100,"TOP"},
	{"�츣��",200,300,200,100,"TOP" },
	{"����",200,300,200,100,"TOP"},
	{"None",-1,-1,-1,-1,"None"},
	{"None",-1,-1,-1,-1,"None"},
	{"None",-1,-1,-1,-1,"None"},
	{"None",-1,-1,-1,-1,"None"},

};

int main()
{
	while (true) {
		cout << "1. SEARCH" << endl;
		cout << "2. INSERT" << endl;
		cout << "3. DELETE" << endl;
		cout << "4.PRINTALL" << endl;

		int key{};
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");
			Search();
			break;
		case 2:
			system("cls");
			Insert();
			break;
		case 3:
			system("cls");
			Delete();
			break;
		case 4:
			system("cls");
			PrintAll();
			break;
		}
	}

}

void Search() {
	string Ch;
	cout << "ã�� è�Ǿ��� �̸��� �Է��Ͻÿ�.:" << endl;
	cin >> Ch;

	for (int i = 0; i < size(List); i++)
	{
		if (Ch.compare(List[i].Name) == 0)
		{
			cout << List[i].Name << endl;    
			cout << List[i].HP << endl;
			cout << List[i].MP << endl;
			cout << List[i].Speed << endl;
			cout << List[i].Range << endl;
			cout << List[i].Position << endl;
		}
	}
}

void Insert()
{
	cout << "�߰��� è�Ǿ��� ������ �Է��Ͻÿ�.:" << endl;

	bool check = false;

	for (int i = 0; i < MAX_LIST; i++)
	{
		if (List[i].HP <= 0)
		{
			cin >> List[i].Name >> List[i].HP >> List[i].MP >> List[i].Speed>> List[i].Range>> List[i].Position;
			break;
			
		}
		else if (List[i].HP > 0 && i == MAX_LIST - 1)
		{
			check = true;
			break;
		}
	}
	if (check)
	{
		cout << "List�� ������ �����ϴ�.";
	}
	PrintAll();
}

void Delete() {
	string Ch;
	cout << "������ è�Ǿ��� �̸��� �Է��Ͻÿ�.: " << endl;
	cin >> Ch;
	for (int i = 0; i < MAX_LIST; i++)
	{
		if (Ch.compare(List[i].Name) == 0)
		{
			List[i].Name = "None";
			List[i].HP = -1;
			List[i].MP = -1;
			List[i].Speed =-1;
			List[i].Range = -1;
			List[i].Position = "None";
		}
	}
	PrintAll();
}

void PrintAll()
{
	for (int i = 0; i < size(List); i++)
	{
		if (List[i].HP > 0) {
			cout << List[i].Name << " " << List[i].HP << " " << List[i].MP << " " << List[i].Speed << " " << List[i].Range << " " << List[i].Position << endl;
		}
	}
}