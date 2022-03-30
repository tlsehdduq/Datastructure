#include<iostream>
#include<string>

#define MAX_LIST 30


using namespace std;

struct LoLDICT
{
	string Name;
	int HP;
	int MP;
	int Speed;
	int Range;
	string Position;

};

LoLDICT List[MAX_LIST]
{
	{"����", 620, 0, 340, 175, "top"},
	{"������", 562, 500, 335, 125,"mid"},
	{"����", 515, 231, 330, 550, "bot"},
	{"Ƽ��", 528, 267, 330, 500, "top" },
	{"�Ҷ�ī", 535, 425, 325, 550, "support" },
	{"����", 585, 275, 345, 125, "jungle" },
	{"����ũ��ũ", 582, 267, 325, 125, "support"},
	{"��", 532, 268, 335, 525, "top" },
	{"���縮����", 620, 0, 350, 500, "bot" },
	{"�ú�", 530, 300, 325, 350, "bot"},
	{"�𸣰���", 500, 350, 320, 550, "support" },
	{"�ڸ�Ű", 550, 450, 125, 330, "mid"},
	{"�� ��", 619, 0, 350, 250, "jungle"},
	{"����Ÿ �۶�ũ", 500, 235, 330, 125, "support"},
	{"�����", 500, 340, 330, 500, "mid"},
	{"�ٵ�", 490, 300, 330, 300, "support"},
	{"�ٷ罺", 510, 250, 345, 570, "bot"},
	{"��", 620, 0, 330, 200, "top"},
	{"�ֽ�", 500, 350, 330, 500, "bot"},
	{"������", 550, 400, 325, 400, "mid" },
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"},
	{"NoNe",-1,-1,-1,-1,"None"}
};
void Search();
void Insert();
void Delete();
void DeleteAll();
void PrintAll();
void FindMaxHp();
void SortByHp();

int main()
{
	
	while (true)
	{
		cout << " 1. SEARCH " << endl;
		cout << " 2. INSERT " << endl;
		cout << " 3. DELETE " << endl;
		cout << " 4. DELETEALL" << endl;
		cout << " 5. PRINTALL " << endl;
		cout << " 6. FINDMAXHP " << endl;
		cout << " 7. SORTBYHP " << endl;
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
			DeleteAll();
			break;
		case 5:
			system("cls");
			PrintAll();
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
	cout << " ã���� è�Ǿ��� �̸��� �Է��Ͻÿ� : ";
	string Ch;
	getline(cin, Ch);
	cin>> Ch;	
	
	for (int i = 0; i < size(List); i++)
	{
		getline(cin, List[i].Name);
		if (Ch._Equal(List[i].Name) == 0)
		{
			cout << "�̸� : " << List[i].Name << " " << "HP :" << List[i].HP << " " << "MP :" << List[i].MP << " " << "Speed :" << List[i].Speed << " " << "Range :" << List[i].Range << " " << "Position :" << List[i].Position << " " << endl;
			break;
		}
		else
		{
			cout << "ã���ô� è�Ǿ��� �����ϴ�." << endl;
			break;
		}
	}
}
void Insert()
{
	bool check = false;
	for (int i = 0; i < size(List); i++)
	{
		if (List[i].HP < 0)
		{
			
			cout << " �߰��Ͻ� è�Ǿ��� �����͸� �Է��Ͻÿ�.: " << endl;
			getline(cin, List[i].Name);
			cin >> List[i].Name >> List[i].HP >> List[i].MP >> List[i].Speed >> List[i].Range >> List[i].Position;
			break;
		}
		else if (check == false && i == (MAX_LIST - 1))
		{
			check = true;
		}

		if (check == true)
		{
			cout << " �޸𸮿� ������ �����ϴ�." << endl;
		}

	}
}
void Delete()
{
	cout << " �����Ͻ� è�Ǿ��� �̸��� �Է��Ͻÿ�.:";
	string Ch;
	for (int i = 0; i < size(List); i++)
	{
		if (Ch.compare(List[i].Name) == 0)
		{
			List[i].Name = "None";
			List[i].HP = -1;
			List[i].MP = -1;
			List[i].Speed = -1;
			List[i].Range = -1;
			List[i].Position = "None";
		}
		else
		{
			cout << "ã���ô� è�Ǿ��� �����ϴ�." << endl;
			break;
		}
	}
}
void DeleteAll()
{
	cout << " �����Ͻ� �������� �Է��Ͻÿ�.:";
	string Ch;
	cin >> Ch;
	for (int i = 0; i < size(List); i++)
	{
		if (Ch.compare(List[i].Position) == 0)
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
void PrintAll()
{

	for (int i = 0; i < size(List); i++)
	{
		if (List[i].HP >= 0) {
			cout << "�̸� : " << List[i].Name << " " << "HP :" << List[i].HP << " " << "MP :" << List[i].MP << " " << "Speed :" << List[i].Speed << " " << "Range :" << List[i].Range << " " << "Position :" << List[i].Position << " " << endl;
		}
	}
}
void FindMaxHp()
{
	int HpTemp{};
	for (int i = 0; i < size(List); i++)
	{
		if (HpTemp < List[i].HP)
		{
			HpTemp = List[i].HP;
		}
	}
	for (int j = 0; j < size(List); j++)
	{
		if (List[j].HP == HpTemp)
		{
			cout << "�̸� : " << List[j].Name << " " << "HP :" << List[j].HP << " " << "MP :" << List[j].MP << " " << "Speed :" << List[j].Speed << " " << "Range :" << List[j].Range << " " << "Position :" << List[j].Position << " " << endl;
		}
	}
}


void SortByHp()
{
	for (int i = 0; i < size(List); i++)
	{
		for (int j = 0; j < size(List); j++)
		{
			if (List[j].HP < List[j + 1].HP)
			{
				LoLDICT TEMP = List[j + 1];
				List[j + 1] = List[j];
				List[j] = TEMP;
			}
		}
	}
}