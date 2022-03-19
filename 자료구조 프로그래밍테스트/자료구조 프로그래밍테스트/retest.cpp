#include<iostream>

using namespace std;

void gameboard(int x,int y);

int main() {
	int x = 0;
	int y = 0;
	cout << " 좌표를 입력하시오. : " << endl;
	cin >> x >> y; 
	gameboard(x,y);

}