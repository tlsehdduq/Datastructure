#include<iostream>
#include<string>
#include<Windows.h>

#define MAX_LIST 30

using namespace std;

void Search(int start, int size, string* name);
void Insert(int start, int size);
void Delete(int start, int size, string* name);
void DeleteAll(int start, int size, string* name);
void FindMaxHp(int start, int size, int temp);

void PrintAll(int start, int size);


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

	{"가렌",620,0,340,175,"top"},
	{"갈리오",562,500,335,125,"mid"},
	{"베인",515,231,330,550,"bot"},
	{"티모",528,267,330,500,"top"},
	{"소라카",535,425,325,550,"supprt"},
	{"녹턴",585,275,345,125,"jungle"},
	{"블리츠크랭크",582,267,325,125,"support"},
	{"퀸",532,268,335,525,"top"},
	{"장지웅",620,0,350,500,"bot"},
	{"시비르",530,300,325,350,"bot"},
	{"모르가나",500,350,320,550,"support"},
	{"코르키",550,450,125,330,"mid"},
	{"리 신",619,0,350,250,"top"},
	{"레나타 글라스크",800,235,330,125,"support"},
	{"코르키",500,340,330,500,"mid"},
	{"바드",490,300,330,300,"support"},
	{"바루스",510,250,345,570,"bot"},
	{"쉔",620,0,330,200,"top"},
	{"애쉬",500,350,330,500,"bot"},
	{"라이즈",550,400,325,400,"mid"},
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

void SortByHp(LoLdict arr[], int n);

int main()
{
	string name;

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
			cout << "찾으실 챔피언의 이름을 입력하시오.:  ";
			cin >> name;
			Search(0, size(List), &name);
			break;
		case 2:
			system("cls");
			cout << "추가할 챔피언의 정보를 입력하시오.:" << endl;
			Insert(0, size(List));
			break;
		case 3:
			system("cls");
			cout << "삭제할 챔피언의 이름을 입력하시오.;";
			cin >> name;
			Delete(0, size(List), &name);
			break;
		case 4:
			system("cls");
			PrintAll(0, size(List));
			break;
		case 5:
			system("cls");
			cout << "삭제하실 포지션을 입력하시오.:";
			cin >> name;
			DeleteAll(0, size(List), &name);
			break;
		case 6:
			system("cls");
			FindMaxHp(0, size(List), 0);
			break;
		case 7:
			system("cls");
			SortByHp(List, size(List));
			break;
		}
	}

}

void Search(int start, int size, string* name) {

	string Ch = *name;

	if (start == size) {
		return;
	}
	if (Ch.compare(List[start].Name) == 0) {
		cout << "이름 : " << List[start].Name << " " << "HP :" << List[start].HP << " " << "MP :" << List[start].MP << " " << "Speed :" << List[start].Speed << " " << "Range :" << List[start].Range << " " << "Position :" << List[start].Position << " " << endl;
	}
	else {
		Search(start + 1, size , name);
	}
}

void Insert(int start, int size)
{
	if (start == size) {
		return;
	}
	if (List[start].HP < 0) {
		cin >> List[start].Name >> List[start].HP >> List[start].MP >> List[start].Speed >> List[start].Range >> List[start].Position;
	}
	else
		Insert(start + 1, size);

}

void Delete(int start, int size, string* name) {
	string Ch = *name;

	if (start == size) {
		return;
	}
	if (Ch.compare(List[start].Name) == 0) {
		List[start].Name = 'None';
		List[start].HP = -1;
		List[start].MP = -1;
		List[start].Speed = -1;
		List[start].Range = -1;
		List[start].Position = 'None';
	}
	else {
		Delete(start + 1, size , name);
	}
}

void PrintAll(int start, int size)
{
	if (start == size) {
		return;
	}
	if (List[start].Speed > 0) {
		cout << List[start].Name << " " << List[start].HP << " " << List[start].MP << " " << List[start].Speed << " " << List[start].Range << " " << List[start].Position << endl;
	}
	PrintAll(start + 1, size);
}

void DeleteAll(int start, int size, string* name)
{
	string Ch = *name;

	if (start == MAX_LIST) {
		return;
	}
	if (Ch.compare(List[start].Position) == 0) {
		List[start].Name = 'None';
		List[start].HP = -1;
		List[start].MP = -1;
		List[start].Speed = -1;
		List[start].Range = -1;
		List[start].Position = 'None';
	}
	DeleteAll(start + 1, size, name);

}
void FindMaxHp(int start, int fsize, int temp)
{
	LoLdict max{};
	int _temp = temp;

	if (start == MAX_LIST)
	{
		for (int i = 0; i < size(List); i++) {
			if (_temp == List[i].HP) {
				cout << List[i].Name << " " << List[i].HP << " " << List[i].MP << " " << List[i].Speed << " " << List[i].Range << " " << List[i].Position << endl;
			}
		}
		return;
	}

	if (_temp < List[start].HP) {
		_temp = List[start].HP;
	}
	FindMaxHp(start + 1, fsize - 1, _temp);
}
void SortByHp(LoLdict arr[], int n)
{
	if (n == 1)return;

	for (int i = 0; i < n; i++) {
		if (arr[i].HP < arr[i + 1].HP) {
			LoLdict temp = arr[i + 1];
			arr[i + 1] = arr[i];
			arr[i] = temp;
		}
	}
	SortByHp(arr, n - 1);
}