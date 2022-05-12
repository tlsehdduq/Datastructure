
#include<iostream>
#define GAMEBOARD 19

using namespace std;

struct OMOK {
	char style;
	bool check;
};

struct Count {
	int ccount;
	int b_x[GAMEBOARD];
	int b_y[GAMEBOARD];
	int w_x[GAMEBOARD];
	int w_y[GAMEBOARD];
	char R;
};

void Rowstone(OMOK arr[][GAMEBOARD], Count* Rowdol)
{
	int nowcount = 0;
	int x[GAMEBOARD];
	int y[GAMEBOARD];
	int xindex = 0;
	int yindex = 0;

	for (int i = 0; i < GAMEBOARD; i++)
	{
		for (int j = 0; j < GAMEBOARD; j++)
		{
			if (arr[i][j].style == '@')
			{
				for (int k = j; arr[i][k].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = i;
					xindex++;
					yindex++;
					if (arr[i][k + 1].style == '+' && arr[i][k + 2].style == '@')
					{
						k++;
						j++;
					}
					j++;
				}
				if (nowcount > Rowdol->ccount)
				{
					Rowdol->ccount = nowcount;

					for (int u = 0; u < nowcount; u++)
					{
						Rowdol->b_x[u] = x[u];
						Rowdol->b_y[u] = y[u];
					}
					Rowdol->R = '@';
				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD; j++)
		{
			if (arr[i][j].style == '#')
			{
				for (int k = j; arr[i][k].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = j;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[i][k + 1].style == '*' && arr[i][k + 2].style == '#')
					{
						k++;
						j++;
					}
					j++;
				}
				if (nowcount > Rowdol->ccount)
				{
					Rowdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Rowdol->w_x[u] = x[u];
						Rowdol->w_y[u] = y[u];
					}
					Rowdol->R = '#';
				}
			}
			nowcount = 0;
		}
	}
}

void Colstone(OMOK arr[][GAMEBOARD], Count* Coldol)
{
	int nowcount = 0;
	int x[GAMEBOARD];
	int y[GAMEBOARD];
	int xindex = 0;
	int yindex = 0;


	for (int i = 0; i < GAMEBOARD; i++)
	{
		for (int j = 0; j < GAMEBOARD; j++)
		{
			if (arr[j][i].style == '@')
			{
				for (int k = j; arr[k][i].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][i].style == '*' && arr[k + 2][i].style == '@')
					{
						k++;
						j++;
					}
					j++;

					if (nowcount > Coldol->ccount)
					{
						Coldol->ccount = nowcount;
						for (int u = 0; u < nowcount; u++)
						{
							Coldol->b_x[u] = x[u];
							Coldol->b_y[u] = y[u];
						}
						Coldol->R = '@';
					}
				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD; j++)
		{
			if (arr[j][i].style == '#')
			{
				for (int k = j; arr[k][i].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][i].style == '*' && arr[k + 2][i].style == '#')
					{
						k++;
						j++;
					}
					j++;
					if (nowcount > Coldol->ccount)
					{
						Coldol->ccount = nowcount;
						for (int u = 0; u < nowcount; u++)
						{
							Coldol->w_x[u] = x[u];
							Coldol->w_y[u] = y[u];
						}
						Coldol->R = '#';
					}
				}
			}
			nowcount = 0;
		}
	}
}

void Crossstone(OMOK arr[][GAMEBOARD], Count* Crossdol)
{
	int nowcount = 0;
	int x[GAMEBOARD];
	int y[GAMEBOARD];
	int xindex = 0;
	int yindex = 0;

	for (int i = 0; i < GAMEBOARD; i++)//�»� -> ��
	{
		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[j][j + i].style == '@')
			{
				for (int k = j; arr[k][k + i].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = k + i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][k + i + 1].style == '*' && arr[k + 2][k + i + 2].style == '@')
					{
						k++;
						j++;
					}
					j++;
					if (nowcount > Crossdol->ccount)
					{
						Crossdol->ccount = nowcount;
						for (int u = 0; u < nowcount; u++)
						{
							Crossdol->b_x[u] = x[u];
							Crossdol->b_y[u] = y[u];
						}
						Crossdol->R = '@';
					}
				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[j][j + i].style == '#')
			{
				for (int k = j; arr[k][k + i].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = k + i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][k + i + 1].style == '*' && arr[k + 2][k + i + 2].style == '#')
					{
						k++;
						j++;
					}
					j++;
					if (nowcount > Crossdol->ccount)
					{
						Crossdol->ccount = nowcount;
						for (int u = 0; u < nowcount; u++)
						{
							Crossdol->w_x[u] = x[u];
							Crossdol->w_y[u] = y[u];
						}
						Crossdol->R = '#';
					}
				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}
	}

	for (int i = 1; i < GAMEBOARD; i++) //�»� -> ��
	{
		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[i + j][j].style == '@')
			{
				for (int k = j; arr[i + k][k].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = k + i;
					xindex++;
					yindex++;
					if (arr[i + k + 1][k + 1].style == '*' && arr[i + k + 2][k + 2].style == '@')
					{
						k++;
						j++;
					}
					j++;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->b_x[u] = x[u];
						Crossdol->b_y[u] = y[u];
					}
					Crossdol->R = '@';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[i + j][j].style == '#')
			{
				for (int k = j; arr[i + k][k].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = k + i;
					xindex++;
					yindex++;
					if (arr[i + k + 1][k + 1].style == '*' && arr[i + k + 2][k + 2].style == '#')
					{
						k++;
						j++;
					}
					j++;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->w_x[u] = x[u];
						Crossdol->w_y[u] = y[u];
					}
					Crossdol->R = '#';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}
	}

	for (int i = GAMEBOARD - 1; i >= 0; i--) //��� -> ��
	{
		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[j][i - j].style == '@')
			{
				for (int k = j; arr[k][i - k].style == '@'; k++)
				{
					nowcount++;
					x[xindex] = k - i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][i - k - 1].style == '*' && arr[k + 2][i - k - 2].style == '@')
					{
						k++;
						j++;
					}
					j++;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->b_x[u] = x[u];
						Crossdol->b_y[u] = y[u];
					}
					Crossdol->R = '@';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = 0; j < GAMEBOARD - i; j++)
		{
			if (arr[j][i - j].style == '#')
			{
				for (int k = j; arr[k][i - k].style == '#'; k++)
				{
					nowcount++;
					x[xindex] = k - i;
					y[yindex] = k;
					xindex++;
					yindex++;
					if (arr[k + 1][i - k - 1].style == '*' && arr[k + 2][i - k - 2].style == '#')
					{
						k++;
						j++;
					}
					j++;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->w_x[u] = x[u];
						Crossdol->w_y[u] = y[u];
					}
					Crossdol->R = '#';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}
	}

	for (int i = 1; i < GAMEBOARD; i++)//��� -> ��
	{
		for (int j = GAMEBOARD - 1; j >= i; j--)
		{
			if (arr[i + 18 - j][j].style)
			{
				for (int k = j; arr[i + 18 - k][k].style == '@'; k--)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = i + 18 - k;
					xindex++;
					yindex++;
					if (arr[i + 18 - k + 1][k - 1].style == '*' && arr[i + 18 - k + 2][k - 2].style == '@')
					{
						k--;
						j--;
					}
					j--;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->b_x[u] = x[u];
						Crossdol->b_y[u] = y[u];
					}
					Crossdol->R = '@';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

		for (int j = GAMEBOARD - 1; j >= i; j--)
		{
			if (arr[i + 18 - j][j].style)
			{
				for (int k = j; arr[i + 18 - k][k].style == '#'; k--)
				{
					nowcount++;
					x[xindex] = k;
					y[yindex] = i + 18 - k;
					xindex++;
					yindex++;
					if (arr[i + 18 - k + 1][k - 1].style == '*' && arr[i + 18 - k + 2][k - 2].style == '#')
					{
						k--;
						j--;
					}
					j--;
				}

				if (nowcount > Crossdol->ccount)
				{
					Crossdol->ccount = nowcount;
					for (int u = 0; u < nowcount; u++)
					{
						Crossdol->w_x[u] = x[u];
						Crossdol->w_y[u] = y[u];
					}
					Crossdol->R = '#';

				}
			}
			nowcount = 0;
			xindex = 0;
			yindex = 0;
		}

	}
}

int main()
{
	OMOK arr[GAMEBOARD][GAMEBOARD];
	Count Rowdol, Coldol, Crossdol;

	int inputx = -1, inputy = -1;
	bool turn = true;

	for (int i = 0; i < GAMEBOARD; i++)
	{
		for (int j = 0; j < GAMEBOARD; j++)
		{
			arr[i][j].style = '*';
			cout << arr[i][j].style << " ";
			arr[i][j].check = false;

		}
		cout << endl;
	}

	while (true)
	{
		cout << " ��ǥ�� �Է����ּ���. : " << endl;
		cin >> inputy >> inputx;

		if ((inputx > 18 || inputx < 0) || (inputy > 18 || inputy < 0))
		{
			cout << " ������ �Ѿ����ϴ�." << endl;
			continue;
		}

		if (arr[inputy][inputx].check == true)
		{
			cout << " �̹� ���� ������ �ֽ��ϴ�. " << endl;
			continue;
		}
		else
		{
			if (turn == true)
			{
				arr[inputy][inputx].style = '@';
				arr[inputy][inputx].check = true;
				turn = false;
			}

			else
			{
				arr[inputy][inputx].style = '#';
				arr[inputy][inputx].check = true;
				turn = true;
			}
		}

		for (int i = 0; i < GAMEBOARD; i++)
		{
			for (int j = 0; j < GAMEBOARD; j++)
			{
				cout << arr[i][j].style << " ";

			}
			cout << endl;
		}

		Rowstone(arr, &Rowdol);
		Colstone(arr, &Coldol);
		Crossstone(arr, &Crossdol);

		if (Rowdol.ccount > Coldol.ccount)
		{
			if (Rowdol.ccount > Crossdol.ccount)
			{
				if (Rowdol.R == '@')
				{
					for (int i = 0; i < Rowdol.ccount; i++)
					{
						cout << " ��ǥ : " << Rowdol.b_y[i] << " , " << Rowdol.b_x[i] << endl;

					}


					if (Rowdol.ccount == 3)
					{
						cout << "���� ǥ�õ� ��ǥ���� 3 ������ �մϴ�." << endl;
					}
					else if (Rowdol.ccount == 4)
					{

						cout << "���� ǥ�õ� ��ǥ���� 4 ������ �մϴ�." << endl;
					}
				}
				else
				{
					for (int i = 0; i < Rowdol.ccount; i++)
					{
						cout << "��ǥ : " << Rowdol.w_y[i] << " , " << Rowdol.w_x[i] << endl;

					}
					cout << " ���ӵ� ���� ���� : " << Rowdol.R << " �� " << Rowdol.ccount << " ��" << endl;


					if (Rowdol.ccount == 3)
					{
						cout << "���� ǥ�õ� ��ǥ���� 3 ������ �մϴ�." << endl;
					}
					else if (Rowdol.ccount == 4)
					{
						cout << "���� ǥ�õ� ��ǥ���� 4 ������ �մϴ�." << endl;
					}
				}
			}
			else if (Rowdol.ccount < Crossdol.ccount)
			{
				if (Crossdol.R == '@')
				{
					for (int i = 0; i < Crossdol.ccount; i++)
					{
						cout << " ��ǥ : " << Crossdol.b_y[i] << " , " << Crossdol.b_x[i] << endl;

					}
					cout << "���ӵ� ���� ���� : " << Crossdol.R << " �� " << Crossdol.ccount << " ��" << endl;


					if (Crossdol.ccount == 3)
					{
						cout << "���� ǥ�õ� ��ǥ���� 3 ������ �մϴ�." << endl;
					}
					else if (Crossdol.ccount == 4)
					{
						cout << "���� ǥ�õ� ��ǥ���� 4������ �մϴ�." << endl;
					}
				}
				else
				{
					for (int i = 0; i < Crossdol.ccount; i++)
					{
						cout << " ��ǥ : " << Crossdol.w_y[i] << " , " << Crossdol.w_x[i] << endl;

					}
					cout << " ���ӵ� ���� ���� : " << Crossdol.R << "  " << Crossdol.ccount << " ��" << endl;


					if (Crossdol.ccount == 3)
					{
						cout << "���� ǥ�õ� ��ǥ���� 3 ������ �մϴ�." << endl;
					}
					else if (Crossdol.ccount == 4)
					{
						cout << "���� ǥ�õ� ��ǥ���� 4 ������ �մϴ�." << endl;
					}
				}
			}
		}
		else if (Coldol.ccount > Rowdol.ccount)
		{
			if (Coldol.ccount > Crossdol.ccount)
			{
				if (Coldol.R == '@')
				{
					for (int i = 0; i < Coldol.ccount; i++)
					{
						cout << " ��ǥ : " << Coldol.b_y[i] << " , " << Coldol.b_x[i] << endl;

					}
					cout << "���ӵ� ���� ���� " << Coldol.R << " " << Coldol.ccount << " ��" << endl;


					if (Coldol.ccount == 3)
					{
						cout << "���� ǥ�õ� ��ǥ���� 3 ������ �մϴ�." << endl;
					}
					else if (Coldol.ccount == 4)
					{
						cout << "���� ǥ�õ� ��ǥ���� 4 ������ �մϴ�." << endl;
					}
				}
				else
				{
					for (int i = 0; i < Coldol.ccount; i++)
					{
						cout << " ��ǥ : " << Coldol.w_y[i] << " , " << Coldol.w_x[i] << endl;

					}
					cout << "���ӵ� ���� ���� : " << Coldol.R << " " << Coldol.ccount << " �� " << endl;


					if (Coldol.ccount == 3)
					{
						cout << "���� ǥ�õ� ��ǥ���� 3 ������ �մϴ�." << endl;
					}
					else if (Coldol.ccount == 4)
					{
						cout << "���� ǥ�õ� ��ǥ���� 4 ������ �մϴ�." << endl;
					}
				}
			}
			else
			{
				if (Crossdol.R == '@')
				{
					for (int i = 0; i < Crossdol.ccount; i++)
					{
						cout << " ��ǥ : " << Crossdol.b_y[i] << " , " << Crossdol.b_x[i] << endl;

					}
					cout << "���ӵ� ���� ���� : " << Crossdol.R << " " << Crossdol.ccount << " �� " << endl;


					if (Crossdol.ccount == 3)
					{
						cout << "���� ǥ�õ� ��ǥ���� 3 ������ �մϴ�." << endl;
					}
					else if (Crossdol.ccount == 4)
					{
						cout << "���� ǥ�õ� ��ǥ���� 4 ������ �մϴ�." << endl;
					}
				}
				else
				{
					for (int i = 0; i < Crossdol.ccount; i++)
					{
						cout << "��ǥ : " << Crossdol.w_y[i] << " , " << Crossdol.w_x[i] << endl;

					}
					cout << " ���ӵ� ���� ����  : " << Crossdol.R << " " << Crossdol.ccount << " ��" << endl;


					if (Crossdol.ccount == 3)
					{
						cout << "���� ǥ�õ� ��ǥ���� 3 ������ �մϴ�." << endl;
					}
					else if (Crossdol.ccount == 4)
					{
						cout << "���� ǥ�õ� ��ǥ���� 4 ������ �մϴ�." << endl;
					}
				}
			}
		}
		else if (Rowdol.ccount == Coldol.ccount && Rowdol.ccount == Crossdol.ccount)
		{
			cout << " ���� ���� �밢������ ���ӵ� ���� ������ �����ϴ�. - " << Rowdol.ccount << " ��" << endl;

		}
	}

}