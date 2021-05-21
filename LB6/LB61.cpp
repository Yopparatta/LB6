#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<vector<long>> column;
	vector<long> row;

	//1

	cout << "Введите количество строк и столбцов" << endl;
	int m, n;
	cin >> m >> n;
	for (int i =1;i<=m; i++) {
		row.clear();
		for (int j = 0;j<n; j++) {
			row.push_back(i);
		}
		column.push_back(row);
	}
	for (int i = 0; i < column.size();i++) {
		for (int j : column[i]) {
			cout << j << "\t";
		}
		cout << endl;
	}

	column.clear();
	row.clear();
	cout << endl << endl;
	//2
	int max=0,min=0;
	for (int i = 1; i <= m; i++) {
		row.clear();
		for (int j = 0; j < n; j++) {
			row.push_back(rand()%9+1);
		}
		column.push_back(row);
	}
	for (int i = 0; i < m; i++) {
		sort(column[i].begin(), column[i].end());
	}
	for (int i = 0; i < column.size(); i++) {
		for (int j : column[i]) {
			cout << j << "\t";
		}
		cout << endl;
	}


	int minVal=10, maxVal=0;
	for (int i = 0; i < m-1; i++) {
		if (maxVal < column[i+1][column[i+1].size() - 1]) {
			max = i;
			maxVal = column[i][column[i].size() - 1];
		}
		if (minVal > column[i + 1][0]) {
			min = i;
			minVal = column[i][0];
		}
	}
	cout << endl;
	column[max].swap(column[min]);
	for (int i = 0; i < column.size(); i++) {
		for (int j : column[i]) {
			cout << j << "\t";
		}
		cout << endl;
	}

	//3
	column.clear();
	row.clear();
	cout << endl << endl << "Введите число n" << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		row.clear();
		for (int j = 0; j < n; j++) {
			row.push_back(rand()%4+1);
		}
		column.push_back(row);
	}

	for (int i = 0; i < column.size(); i++) {
		for (int j : column[i]) {
			cout << j << "\t";
		}
		cout << endl;
	}
	int a=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (!(column[i][j] == column[j][i])) {
				cout << "NO" << endl;
				a++;
				break;
			}
		}
		if (a) break;
	}
	if (a == 0) {
		cout << "YES" << endl;
	}
}

