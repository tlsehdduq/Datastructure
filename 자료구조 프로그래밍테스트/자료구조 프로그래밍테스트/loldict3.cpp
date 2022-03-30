#include<iostream>

#define MAX_SIZE 30

using namespace std;



class Champion {
	char* Name;
	int HP;
	int MP;
	int Speed;
	int Range;
	char* Position;

public:
	
	Champion(char* c_Name, int c_HP, int c_MP, int c_Speed, int c_Range, char* c_Pos) {
		int len = strlen(c_Name) + 1;
		int plen = strlen(c_Pos) + 1;
		Name = new char[len];
		strcpy_s(Name, len, c_Name);
		HP = c_HP;
		MP = c_MP;
		Speed = c_Speed;
		Range = c_Range;
		Position = new char[plen];
		strcpy_s(Position, plen, c_Pos);
	}
	Champion() {
		Name = NULL;
		HP = 0;
		MP = 0;
		Speed = 0;
		Range = 0; 
		Position = NULL;

	}
};

//Champion List[MAX_SIZE]{
//
//	{"����",620,0,340,175,"top"},
//	{"������",562,500,335,125,"mid"},
//	{"����",515,231,330,550,"bot"},
//	{"Ƽ��",528,267,330,500,"top"},
//	{"�Ҷ�ī",535,425,325,550,"supprt"},
//	{"����",585,275,345,125,"jungle"},
//	{"����ũ��ũ",582,267,325,125,"support"},
//	{"��",532,268,335,525,"top"},
//	{"������",620,0,350,500,"bot"},
//	{"�ú�",530,300,325,350,"bot"},
//	{"�𸣰���",500,350,320,550,"support"},
//	{"�ڸ�Ű",550,450,125,330,"mid"},
//	{"�� ��",619,0,350,250,"top"},
//	{"����Ÿ �۶�ũ",500,235,330,125,"support"},
//	{"�ڸ�Ű",500,340,330,500,"mid"},
//	{"�ٵ�",490,300,330,300,"support"},
//	{"�ٷ罺",510,250,345,570,"bot"},
//	{"��",620,0,330,200,"top"},
//	{"�ֽ�",500,350,330,500,"bot"},
//	{"������",550,400,325,400,"mid"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"},
//	{"NONE",-1,-1,-1,-1,"NONE"}
//
//};


int main()
{

}