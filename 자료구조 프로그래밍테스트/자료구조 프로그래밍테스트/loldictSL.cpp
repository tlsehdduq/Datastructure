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


void Array2LinkedList(Node** head, LoLdict* champion) {

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
	{"소라카",535,425,325,550,"support"},
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

void Search(Node** head, string& name) {

	Node* p = *head;;
	do {
		if (p->Data.Name.compare(name) == 0)
			std::cout << p->Data.Name << " " << p->Data.HP << " " << p->Data.MP << " " << p->Data.Speed << " " << p->Data.Range << " " << p->Data.Position << " " << endl;
		p = p->Next;
	} while (p != *head);
}

void Insert(Node** head, LoLdict* champion) {
	Node* p;
	Node* NEW = new Node;
	NEW->Data = *champion;
	NEW->Next = NULL;

	for (p = *head; p->Next != *head; p = p->Next) {
		//if (p->Data.HP < NEW->Data.HP) {
		//	NEW->Next = p->Next;
		//	p->Next = NEW;
		//}
	}
	p->Next = NEW;
	NEW->Next = *head;
}

void Delete(Node** head, string& name) {

	Node* p;
	for (p = *head; p->Next != *head; p = p->Next) {

		if (p == *head) {
			if (p->Data.Name.compare(name) == 0) {
				Node* temp = *head;
				*head = p->Next;

				for (p = p->Next; p->Next != temp; p = p->Next) {}
				p->Next = *head;
				delete temp;
				break;
			}
		}
		else {
			if (p->Next->Data.Name.compare(name) == 0) {
				Node* temp = p->Next;
				p->Next = p->Next->Next;
				delete temp;

			}
		}
	}
}

void printAll(Node** head) {

	Node* p = *head;
	do {
		std::cout << p->Data.Name << " " << p->Data.HP << " " << p->Data.MP << " " << p->Data.Speed << " " << p->Data.Range << " " << p->Data.Position << " " << endl;
		p = p->Next;
	} while (p != *head);

}

void Delete_All(Node** head, string& position) {

	Node* p;
	Node* prevNode = *head;
	for (p = *head; p->Next != *head; p = p->Next) {
		p = prevNode;
		if (p == *head) {
			if (p->Data.Position.compare(position) == 0) {
				Node* temp = *head;
				*head = p->Next;

				for (p = p->Next; p->Next != temp; p = p->Next) {}
				p->Next = *head;
				p = *head;
				delete temp;
				prevNode = *head;
			}
			else if (p->Next->Data.Position.compare(position) == 0) {
				Node* temp = p->Next;
				p->Next = p->Next->Next;
				delete temp;
				prevNode = p;
				if (p->Next->Next == *head)
					break;
			}
			else {
				prevNode = p->Next;
			}
		}
		else {
			if (p->Next->Data.Position.compare(position) == 0) {
				Node* temp = p->Next;
				p->Next = p->Next->Next;
				delete temp;
				prevNode = p;
				if (p->Next->Next == *head)

					break;
			}
			else {
				prevNode = p->Next;
			}
		}
		//cout << '1';
	}
}

void FindMaxHp(Node** head) {
	Node* p = *head;
	Node* temp = new Node;
	do {
		if (p->Data.HP > temp->Data.HP) {
			temp->Data = p->Data;
		}
		p = p->Next;
	} while (p != *head);
	cout << temp->Data.Name << " " << temp->Data.HP << " " << temp->Data.MP << " " << temp->Data.Speed << " " << temp->Data.Range << " " << temp->Data.Position << endl;
}

void SortByHp(Node** head) {

	Node* p = *head;
	while (p->Next != *head) {
		Node* Temp = p->Next;
		do {
			if (p->Data.HP < Temp->Data.HP) {
				LoLdict Ltemp = p->Data;
				p->Data = Temp->Data;
				Temp->Data = Ltemp;
			}
			Temp = Temp->Next;
		} while (Temp != *head);                
		p = p->Next;
	}
}

int main()
{
	Node* head = NULL;
	Array2LinkedList(&head, List);
	while (true) {

		std::cout << " 1. SEARCH " << endl;
		std::cout << " 2. INSERT " << endl;
		std::cout << " 3. DELETE " << endl;
		std::cout << " 4. DELETEALL" << endl;
		std::cout << " 5. PRINTALL " << endl;
		std::cout << " 6. FINDMAXHP " << endl;
		std::cout << " 7. SORTBYHP " << endl;

		char key{};
		std::cin >> key;
		string Name;
		LoLdict newchamp;

		switch (key)
		{
		case '1':
			system("cls");
			std::cout << " 찾으실 챔피언의 이름을 입력하시오. " << endl;
			cin >> Name;
			Search(&head, Name);
			break;
		case '2':
			system("cls");
			std::cout << " 추가하실 챔피언의 정보를 입력하시오.: " << endl;
			cin >> newchamp.Name >> newchamp.HP >> newchamp.MP >> newchamp.Speed >> newchamp.Range >> newchamp.Position;
			Insert(&head, &newchamp);
			break;
		case '3':
			system("cls");
			std::cout << " 삭제하실 챔피언의 이름을 입력하시오. " << endl;
			cin >> Name;
			Delete(&head, Name);
			break;
		case '4':
			system("cls");
			std::cout << "삭제하실 포지션을 입력하시오. " << endl;
			cin >> Name;
			Delete_All(&head, Name);
			break;
		case '5':
			system("cls");
			printAll(&head);
			break;
		case '6':
			system("cls");
			std::cout << " 최대 HP " << endl;
			FindMaxHp(&head);
			break;
		case '7':
			system("cls");
			std::cout << " 정렬된 리스트" << endl;
			SortByHp(&head);
			break;
		}
	}
}
