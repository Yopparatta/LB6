#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
string crypting(string text, string key)
{
	map <int, char> Num;
	int num = 0;
	while (num < 26)
	{
		Num[num] = 'a' + num;
		num++;
	}
	Num[num] = ' ';
	vector<vector<char>> code(27, vector <char>(27));
	for (int i = 0; i < 27; i++)
		for (int j = 0; j < 27; j++)
		{
			code[i][j] = Num[(j + i) % 27];
		}
	vector<pair<char, char>> mess;
	for (int i = 0; i < text.size(); i++)
	{
		mess.push_back(make_pair(text[i], key[i % key.size()]));
	}
	string crypt = text;
	int cs = 0, ts = 0, i = 0;
	for (auto it : mess)
	{
		for (auto it_1 : Num)
		{
			if (it_1.second == it.first)
				ts = it_1.first;
		}
		for (auto it_2 : Num)
		{
			if (it_2.second == it.second)
				cs = it_2.first;
		}
		crypt[i++] = code[ts][cs];
	}
	return crypt;
}
string uncrypting(string crypt, string key)
{
	map <int, char> Num;
	int num = 0;
	while (num < 26)
	{
		Num[num] = 'a' + num;
		num++;
	}
	Num[num] = ' ';
	vector<pair<char, char>> mess;
	for (int i = 0; i < crypt.size(); i++)
	{
		mess.push_back(make_pair(crypt[i], key[i % key.size()]));
	}
	string uncrypt = crypt;
	int cs = 0, ts = 0, i = 0;
	for (auto it : mess)
	{
		for (auto it_1 : Num)
		{
			if (it_1.second == it.first)
				ts = it_1.first;
		}
		for (auto it_2 : Num)
		{
			if (it_2.second == it.second)
				cs = it_2.first;
		}
		uncrypt[i++] = Num[(ts - cs + 27) % 27];
	}
	return uncrypt;
}
void main()
{
	setlocale(LC_ALL,"Russian");
	string text, key, crypt, uncrypt;
	cout << "Введите текст для шифрования: ";
	getline(cin, text);
	cout << "Введите ключ: ";
	cin >> key;
	crypt = crypting(text, key);
	cout << "Зашифрованный текст: " << crypt << endl;
	uncrypt = uncrypting(crypt, key);
	cout << "Расшифрованный текст: " << uncrypt;
}