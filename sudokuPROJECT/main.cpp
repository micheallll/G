#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void output(int a[9][9])//输出函数 
{
	int i, j;
	for (i = 0; i<9; i++)
	{
		for (j = 0; j<9; j++)
		{
			cout << a[i][j];
			if (j == 8)
				cout << endl;
			else
				cout << " ";
		}
	}
}

int main(int argc, char *argv[])
{
	
	srand((unsigned)time(NULL));
	int N, a = 0, i = 1, j, k, l, m = 1, tmp, x, y;
	if (sscanf(argv[2], "%d", &N) == 0 || N<0)
	{
		cout << "请输入一个正整数!" << endl;
		return 0;
	}
	freopen("sudoku.txt", "w", stdout);

	int sudo[9][9] = { 1,2,3,4,5,6,7,8,9,
		4,5,6,7,8,9,1,2,3,
		7,8,9,1,2,3,4,5,6,
		2,3,4,5,6,7,8,9,1,
		5,6,7,8,9,1,2,3,4,
		8,9,1,2,3,4,5,6,7,
		3,4,5,6,7,8,9,1,2,
		6,7,8,9,1,2,3,4,5,
		9,1,2,3,4,5,6,7,8, };//内置初始数独 
	while (a<N)
	{
		if (m == 1)
		{
			x = (rand() % 8) + 2;// 
			y = x;
			while (y == x)
			{
				y = (rand() % 8) + 2;
			}
			for (l = 0; l<9; l++)
			{
				for (j = 0; j<9; j++)
				{
					if (sudo[l][j] == x)
					{
						tmp = sudo[l][j];
						for (k = 0; k<9; k++)
						{
							if (sudo[l][k] == y)
							{
								sudo[l][j] = sudo[l][k];
								sudo[l][k] = tmp;
								break;
							}
						}
						break;
					}
				}
			}
			output(sudo);
			m++;
		}

		else if (m == 2)
		{
			for (j = 0; j<9; j++)
			{
				tmp = sudo[i][j];
				sudo[i][j] = sudo[i + 1][j];
				sudo[i + 1][j] = tmp;
			}
			output(sudo);
			m++;
		}

		else if (m == 3)
		{
			for (j = 0; j<9; j++)
			{
				tmp = sudo[j][i];
				sudo[j][i] = sudo[j][i + 1];
				sudo[j][i + 1] = tmp;
			}
			output(sudo);
			m = 1;
		}

		if (i == 1 || i == 4)
		{
			i = i + 2;
		}
		else if (i == 7)
		{
			i = 1;
		}
		else
		{
			i++;
		}

		a++;
		if (a == N)
		{
			break;
		}
		else
			cout << endl;
	}
	return 0;
}