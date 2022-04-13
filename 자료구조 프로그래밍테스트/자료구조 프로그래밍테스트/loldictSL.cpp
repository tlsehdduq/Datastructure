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
	
	Node* headnode = new Node;
	headnode->Data = champion[0];
	headnode->Next = *head;
	*head = headnode;
	Node* p = *head;
	for (int i = 1; i < MAX_LIST; ++i) {

		Node* NEW = new Node;
		NEW->Data = champion[i];
		NEW->Next = *head;
		p->Next = NEW;
		p = p->Next;
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

void Insert(Node** head, LoLdict* champion) {
	Node* p;
	Node* NEW = new Node;
	NEW->Data = *champion;
	NEW->Next = NULL;


	for (p = *head; p->Next != *head; p = p->Next) {
		/*if (p->Data.HP < NEW->Data.HP) {
			NEW->Next = p->Next;
			p->Next = NEW;
		}*/
	}
	p->Next = NEW;
	NEW->Next = *head;
}

void Delete(Node** head, const string& name) {

	Node* p;
	
	for (p = *head; p->Next != *head; p = p->Next) {
		if (p->Next->Data.Position.compare(name) == 0) {
			p->Next = p->Next->Next;
		}
	}
}

void printAll(Node** head) {
	Node* p = *head;
	do {
		cout << p->Data.Name << " " << p->Data.HP << " " << p->Data.MP << " " << p->Data.Speed << " " << p->Data.Range << " " << p->Data.Position << " " << endl;
		p = p->Next;
	} while (p != *head);

}

void Delete_All(Node** head, const string& position) {
	Node* p;
	for (p = *head; p->Next != *head; p = p->Next) {
		if (p->Next->Data.Position.compare(position) == 0) {
			p->Next = p->Next->Next;
		}
	}
}

void FindMaxHp(Node** head) {
	Node* p;
	LoLdict Temp;
	for (p = *head; p->Next != *head; p = p->Next) {
		if (p->Data.HP > p->Next->Data.HP)
			Temp = p->Data;
	}
	cout <<Temp.Name << " " << Temp.HP << " " << Temp.MP << " " << Temp.Speed << " " << Temp.Range << " " << Temp.Position << " " << endl;
}

void SortByHp(Node** head) {
	Node* p;
	for (p = *head; p->Next != *head; p = p->Next) {
		if(p->Data.HP > p->Next->Data.HP)
	}
}

int main()
{
	Node* head = NULL;
	Array2LinkedList(&head, List);
	while (true) {

		cout << " 1. SEARCH " << endl;
		cout << " 2. INSERT " << endl;
		cout << " 3. DELETE " << endl;
		cout << " 4. DELETEALL" << endl;
		cout << " 5. PRINTALL " << endl;
		cout << " 6. FINDMAXHP " << endl;
		cout << " 7. SORTBYHP " << endl;

		char key{};
		cin >> key;
		string Name;
		LoLdict newchamp;
		switch (key)
		{
		case '1':
			cin >> Name;
			Search(&head, Name);
			break;
		case '2':
			cin >> newchamp.Name >> newchamp.HP >> newchamp.MP>> newchamp.Speed>> newchamp.Range>> newchamp.Position;
			Insert(&head, &newchamp);
			break;
		case '3':
			cin >> Name;
			Delete(&head, Name);
			break;
		case '4':
			cin >> Name;
			Delete_All(&head, Name);
			break;
		case '5':
			printAll(&head);
			break;
		case '6':
			FindMaxHp(&head);
			break;
		case '7':
			cin >> Name;
			Search(&head, Name);
			break;
		}





	}

}
