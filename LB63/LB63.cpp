#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int n = 4, cnt;
	vector<vector<double>> matrix =
	{ {-0.77,-0.04, 0.21, -18, -1.24},
	{0.25, -1.23, 0.16, -0.09, 1.12},
	{-0.21, 0.16, 0.8, -0.13, 2.56},
	{0.15, -1.31, 0.06, 1.12, -0.77} };
	cout << "Система уравнений в виде матрицы:" << endl;
	for (auto it : matrix)
	{
		cnt = 1;
		cout << "|";
		for (auto i : it)
		{
			printf("%7.2f", i);
			if (cnt == n) cout <<"|";
			cnt++;
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j >= i; j--)
			matrix[i][j] /= matrix[i][i];
		for (int j = i + 1; j < n; j++)
		{
			for (int k = n; k >= i; k--)
				matrix[j][k] -= matrix[j][i] * matrix[i][k];
		}
	}
	cout << endl << "Прямой ход:" << endl;
	for (auto it : matrix)
	{
		cnt = 1;
		cout << "|";
		for (auto i : it)
		{
			printf("%7.2f", i);
			if (cnt == n) cout << "|";
			cnt++;
		}
		cout << "|" << endl;
	}
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			for (int k = n; k >= 0; k--)
			{
				matrix[j][k] -= matrix[j][i] * matrix[i][k];
			}
		}
	}
	cout << endl << "Обратный ход:" << endl;
	vector<double> xx;
	for (auto it : matrix)
	{
		xx.push_back(it[4]);
		cout << "|";
		cnt = 1;
		for (auto i : it)
		{
			printf("%7.2f", i);
			if (cnt == n) cout << "|";
			cnt++;
		}
		cout << "|" << endl;
	}
	cout << endl;
	int i = 1;
	for (auto it : xx)
	{
		cout << setprecision(4) << "x" << i++ << " = " << it << endl;
	}
}