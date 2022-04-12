#include<iostream>
#include<string>


#define MAX_LIST 20

using namespace std;


struct LoLdict
{
	string Name;
	int HP;
	int MP;
	int Speed;
	int Range;
	string Position;

};

struct Node {
	Node* Next;
	LoLdict Data;
};

void Array2LinkedList(Node** head,LoLdict* champion) {
	
	for (int i = 0; i < MAX_LIST; ++i) {

		Node* NEW = new Node;
		NEW->Data = champion[i];
		
		NEW->Next = *head;
		*head = NEW;
	}
}
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
	
};

void Search(Node** head, const string& name) {
	Node* p;
	for (p = *head; p->Next != *head; p = p->Next) {
		if(p->Data.Name.compare(name) == 0)
			cout << p->Data.Name << " " << p->Data.HP << " " << p->Data.MP << " " << p->Data.Speed << " " << p->Data.Range << " " << p->Data.Position << " " << endl;
	}
}


void Delete(Node** head, const string& name) {

	Node* p;
	for (p = *head; p->Next != NULL; p = p->Next) {
		if (p->Next->Data.Name.compare(name) == 0) {
			p->Next = p->Next->Next;
		}
	}
}

void printAll(Node** head) {
	Node* p;
	for (p = *head; p->Next != NULL; p = p->Next) {
		cout << p->Data.Name << " " << p->Data.HP << " "<<p->Data.MP<< " "<<p->Data.Speed<< " "<<p->Data.Range<< " "<<p->Data.Position << " "<<  endl;
	}
}

int main()
{

	while (true) {

		Node* head = NULL;
		Array2LinkedList(&head, List);
		string Name;
		cin >> Name;
		Delete(&head, Name);
		//Search(&head, Name);
		printAll(&head);
	}

}
