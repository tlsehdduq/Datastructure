#include<iostream>
#include<string.h>
#define MAX_NAME_LEN 20
#define MAX_POSITION_LEN 20
#define A 6
#define MAX_LIST 10
using namespace std;


typedef struct {
	char Name[MAX_NAME_LEN];
	int HP;
	int MP;
	int Speed;
	int Range;
	char Position[MAX_POSITION_LEN];
}Champion;	

Champion arr[MAX_LIST] = {0};
void Search();
void Insert();
void Delete();


int main()
{
	cout << "챔피언의 정보를 입력하시오.:" << endl;
	for (int i = 0; i < 1; i++)
	{
		cin >> arr[i].Name >> arr[i].HP >> arr[i].MP >> arr[i].Speed >> arr[i].Range >> arr[i].Position;
	}

	cout << "1.Search" << endl;
	cout << "2.Insert" << endl;
	cout << "3.Delete" << endl;
	cout << "4.PrintALL" << endl;

	int key = 0;
	cin >> key;
	switch (key)
	{
	case 1:
		Search();
		break;
	case 2:
		Insert();
		break;
	case 3:
		Delete();
		for (int j = 0; j < MAX_LIST; j++)
		{
			cout << "Name : " << arr[j].Name << endl;
			cout << "HP : " << arr[j].HP << endl;
			cout << "MP : " << arr[j].MP << endl;
			cout << "Speed : " << arr[j].Speed << endl;
			cout << "Range : " << arr[j].Range << endl;
			cout << "Position : " << arr[j].Position << endl;
		}
		break;
	case 4:

		for (int j = 0; j < MAX_LIST; j++)
		{
			cout << "Name : " << arr[j].Name << endl;
			cout << "HP : " << arr[j].HP << endl;
			cout << "MP : " << arr[j].MP << endl;
			cout << "Speed : " << arr[j].Speed << endl;
			cout << "Range : " << arr[j].Range << endl;
			cout << "Position : " << arr[j].Position << endl;
		}
		break;
	case 5:

		break;
	}


} 
void Search()
{
	char s_name[MAX_NAME_LEN] = {};
	cout << "챔피언의 이름을 입력하시오." << endl;
	cin >> s_name;
	
	for (int i = 0; i < MAX_LIST; i++)
	{
		int compare = strcmp(s_name, arr[i].Name);
		if (!strcmp(s_name, arr[i].Name))
		{
			cout << arr[i].Name << endl;
			cout << arr[i].HP << endl;
			cout << arr[i].MP << endl;
			cout << arr[i].Speed << endl;
			cout << arr[i].Range << endl;
			cout << arr[i].Position << endl;

		}

	}
}
void Insert()
{
	char i_name[MAX_NAME_LEN] = {};
	cout << "챔피언의 정보를 입력하시오.: " << endl;
	cin >> arr[A + 1].Name >> arr[A + 1].HP >> arr[A + 1].MP >> arr[A + 1].Speed >> arr[A + 1].Range >> arr[A + 1].Position;
	for (int j = 0; j < MAX_LIST; j++)
	{
		cout << "Name : " << arr[j].Name << endl;
		cout << "HP : " << arr[j].HP << endl;
		cout << "MP : " << arr[j].MP << endl;
		cout << "Speed : " << arr[j].Speed << endl;
		cout << "Range : " << arr[j].Range << endl;
		cout << "Position : " << arr[j].Position << endl;
	}
}
void Delete()
{
	cout << "챔피언의 이름을 입력하시오.: " << endl;
	char d_name[MAX_LIST] = {};
	cin >> d_name;
	for (int i = 0; i < MAX_LIST; i++)
	{
		int compare = strcmp(d_name, arr[i].Name);
		if (!strcmp(d_name, arr[i].Name))
		{
			arr[i].Name[MAX_NAME_LEN] = {};
			arr[i].HP = 0;
			arr[i].MP = 0;
			arr[i].Speed = 0;
			arr[i].Range = 0;
			arr[i].Position[MAX_NAME_LEN] = {};
		}

	}

}

