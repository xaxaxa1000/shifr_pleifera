#include <iostream>
#include<cmath>
#include"func.h"
#include<vector>
#include<fstream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	bool last = true;
	while (last) {
		last = false;
		int answer[3];
		*answer = question(answer);
		int count = 25;
		vector<char> text;
		vector<char> new_text;
		if (answer[2] == 1) {
			text = initText(text, answer[0]);
		}
		else {
			text = initCodeText(text, answer[0]);
		}
		new_text.resize(text.size());
		char* codeWord = new char[count];
		*codeWord = initCodeWord(codeWord, count, answer[0]);
		char** a = new char* [sqrt(count)];

		for (int i = 0; i < sqrt(count); i++) {

			a[i] = new char[sqrt(count)];
			for (int j = 0; j < sqrt(count); j++) {
				a[i][j] = '0';
			}
		}

		**a = fillMatrix(a, codeWord);

		if (answer[2] == 1) {
			new_text = encrypt(text, a);
		}
		else {
			new_text = decrypt(text, a);
		}
		if (answer[1] == 1) {
			if (answer[2] == 1) {
				cout << "Шифр:";
			}
			else {
				cout << "Расшифровка:";
			}

			for (int i = 0; i < text.size(); i++) {
				cout << new_text[i];
			}
		}
		else {
			ofstream out;
			out.open("out.txt", ios_base::trunc);
			if (answer[2] == 1) {
				out << "Шифр:";
			}
			else {
				out << "Расшифровка:";
			}
			for (int i = 0; i < new_text.size(); i++) {
				out << new_text[i];
			}
			out.close();
		}
		int h;
		cout << "\n1.Выйти.\n2.Заново.\n";
		cin >> h;
		if (h == 1)
		{
			last = false;
		}
		else {
			last = true;
		}
	}
	return 0;
}

