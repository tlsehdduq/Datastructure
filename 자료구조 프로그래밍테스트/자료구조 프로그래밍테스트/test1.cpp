#include<iostream>
#include<Windows.h>

using namespace std;
#define WIDTH 19
#define HEIGHT 19

void gameboard(int b_x,int b_y)
{
	system("cls");
	if (b_x == NULL, b_y == NULL)
	{
		for (int y = 0; y < 19; y++)
		{
			for (int x = 0; x < 19; x++)
			{

				cout << "*" << " ";


			}
			cout << "I";
			cout << endl;
		}
	}


}

int main()
{
	
	gameboard(NULL,NULL);
	
	int x, y = 0;
	cin >> x;
	cin >> y;
	gameboard(x, y);



}