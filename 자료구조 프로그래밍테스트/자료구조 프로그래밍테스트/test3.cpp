#include<iostream>
#include<fstream>

using namespace std;

struct Stone {
	int x, y;
	char stone;
};
struct Node {
	Stone Data;
	Node* Next;
};

void Gameboard(char** board) {
	for (int y = 0; y < 19; ++y) {
		for (int x = 0; x < 19; ++x) {
			cout << board[y][x] << " ";
		}
		cout << endl;
	}
}

int main()
{

	char** board = new char* [19];
	for (int i = 0; i < 19; ++i) {
		board[i] = new char[19];
	}
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19; ++j) {
			board[i][j] = '+';
		}
	}

	Gameboard(board);
}