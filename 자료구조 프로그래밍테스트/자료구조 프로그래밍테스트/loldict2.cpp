#include<iostream>
#include<string>
#include<Windows.h>
#define MAX_LIST 30

using namespace std;

void Search();
void Insert();
void Delete();
void DeleteAll();
void FindMaxHp();
void SortByHp();
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

{"����",620,0,340,175,"top"},
	{"������",562,500,335,125,"mid"},
	{"����",515,231,330,550,"bot"},
	{"Ƽ��",528,267,330,500,"top"},
	{"�Ҷ�ī",535,425,325,550,"supprt"},
	{"����",585,275,345,125,"jungle"},
	{"����ũ��ũ",582,267,325,125,"support"},
	{"��",532,268,335,525,"top"},
	{"������",620,0,350,500,"bot"},
	{"�ú�",530,300,325,350,"bot"},
	{"�𸣰���",500,350,320,550,"support"},
	{"�ڸ�Ű",550,450,125,330,"mid"},
	{"����",619,0,350,250,"top"},
	{"����Ÿ�۶�ũ",500,235,330,125,"support"},
	{"�ڸ�Ű",500,340,330,500,"mid"},
	{"�ٵ�",490,300,330,300,"support"},
	{"�ٷ罺",510,250,345,570,"bot"},
	{"��",620,0,330,200,"top"},
	{"�ֽ�",500,350,330,500,"bot"},
	{"������",550,400,325,400,"mid"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"}

};

LoLdict SortList[MAX_LIST] = {
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"},
	{"NONE",-1,-1,-1,-1,"NONE"}
};

int main()
{
	while (true) {
		cout << "1. SEARCH" << endl;
		cout << "2. INSERT" << endl;
		cout << "3. DELETE" << endl;
		cout << "4.PRINTALL" << endl;
		cout << "5. DELETEALL" << endl;
		cout << "6. FINDMAXHP" << endl;
		cout << "7. SORTBYHP" << endl;

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
		case 5:
			system("cls");
			DeleteAll();
			break;
		case 6:
			system("cls");
			FindMaxHp();
			break;
		case 7:
			system("cls");
			SortByHp();
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

void DeleteAll()
{
	string Pos;
	cout << "�����Ͻ� �������� �Է��Ͻÿ�.:";
	cin >> Pos;
	for (int i = 0; i < size(List); i++)
	{
		if (Pos.compare(List[i].Position) == 0)
		{
			List[i].Name = "None";
			List[i].HP = -1;
			List[i].MP = -1;
			List[i].Speed = -1;
			List[i].Range = -1;
			List[i].Position = "None";
		}
	}
}
void FindMaxHp()
{
	int tempHp{};

	for (int i = 0; i < size(List); i++)
	{
		if (List[i].HP > tempHp)
			tempHp = List[i].HP;
	}
	for (int j = 0; j < size(List); j++)
	{
		if (tempHp == List[j].HP)
		{
			cout << List[j].Name << " " << List[j].HP << " " << List[j].MP << " " << List[j].Speed << " " << List[j].Range << " " << List[j].Position << endl;
		}
	}
}
void SortByHp()
{
	for (int j = 0; j < size(List); j++)
	{
		for (int i = 0; i < size(List); i++)
		{
			if (List[i].HP < List[i + 1].HP)
			{
				LoLdict Temp = List[i];
				List[i] = List[i + 1];
				List[i + 1] = Temp;
			}
		}
	}
}