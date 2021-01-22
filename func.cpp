#include<iostream>
#include"func.h"
#include<vector>
#include<fstream>
#include<string>
using namespace std;

int question(int answer[]) {
	cout << "Кодовое слово и текст должны состоять из ангийских букв любого реестра.\nКодовое слово может состоять из не более чем 25 симоволов.\nВ файле сообщение и кодовое слово необходимо записать после слов Messange: и Secret code: соответственно\nВ ответах на вопросы необходимо записать номер ответа.\n\n\n";
tryagain1:
	cout << "Тип ввода:\n" << "1.С клавиатуры\n" << "2.Из файла\n";
	cin >> answer[0];
	if ((answer[0] != 1) && (answer[0] != 2)) {
		cout << "\nНеверный ввод! Введите заново.\n";
		goto tryagain1;
	}
tryagain2:
	cout << "Тип вывода:\n" << "1.На монитор\n" << "2.В файл\n";
	cin >> answer[1];
	if ((answer[1] != 1) && (answer[1] != 2)) {
		cout << "\nНеверный ввод! Введите заново.\n";
		goto tryagain2;
	}
tryagain3:
	cout << "Режим работы:\n" << "1.Зашифровать\n" << "2.Расшифровать\n";
	cin >> answer[2];
	if ((answer[2] != 1) && (answer[2] != 2)) {
		cout << "\nНеверный ввод! Введите заново.\n";
		goto tryagain3;
	}


	for (int i = 0; i < 3; i++) {
		return answer[i];
	}
}
char initCodeWord(char codeWord[], int count, int answer) {
	ifstream in;
	in.open("in.txt");
	string str;
	getline(in, str);
	char ch;
	for (int i = 0; i < 11; i++) {
		in >> ch;
	}

	for (int i = 0; i < count; i++) {
		codeWord[i] = '0';
	}

	if (answer == 1) {
		cout << "Введите кодовое слово оканчивая точкой:";
	}
	char temp = '0';
	for (int i = 0; i < count; i++) {
		if (temp != '.') {
			if (answer == 1) {
				cin >> temp;
			}
			else {
				in >> temp;
			}
			if ((temp != '.') && (temp != 'q') && (temp != 'Q')) {
				codeWord[i] = switchRegistr(temp);
			}
		}

	}
	in.close();

	*codeWord = deleteSameSybols(codeWord, count);
	for (int i = 0; i < count; i++) {
		return codeWord[i];
	}


}
vector<char> initCodeText(vector<char> text, int answer) {
	ifstream in;
	if (answer == 1) {
		cout << "Введите текст оканчивая его точкой:";
	}
	else{
	in.open("in.txt");
	char ch;

	for (int i = 0; i < 9; i++) {
		in >> ch;

	}
	}
	char sym = '0';
	int cnt = 1;
	while (sym != '.') {
		if (answer == 1) {
			cin >> sym;
		}
		else
		{
			in >> sym;

		}
		if ((sym != '.') && (sym != ' ') && (sym != 'q') && (sym != 'Q')) {
			text.resize(cnt);
			text[cnt - 1] = sym;
			cnt++;
		}
	}
	if(answer==2){
	in.close();
	}
	return text;
}
char switchRegistr(char symbol) { 
	int a;
	a = symbol;
	if ((a > 64) && (a < 91)) {
		a += 32;
	}


	symbol = (char)a;
	return symbol;
}
char deleteSameSybols(char codeWord[], int count) {

	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if ((codeWord[i] == codeWord[j]) && (codeWord[i] != '0')) {
				codeWord[j] = '0';
			}
		}
	}
	for (int p = 0; p < count; p++) {
		for (int i = 0; i < count; i++) {
			if (codeWord[i] == '0') {
				for (int l = i; l < count - 1; l++) {


					codeWord[l] = codeWord[l + 1];

				}
			}


		}
	}
	for (int i = 0; i < count; i++) {
		return codeWord[i];
	}

}
char fillMatrix(char** matrix, char codeWord[]) {

	char s[25];

	s[0] = 'a';
	for (int i = 1; i < 25; i++) {
		if (s[i - 1] != 'p') {
			s[i] = s[i - 1] + 1;
		}
		else {
			s[i] = s[i - 1] + 2;
		}
	}
	int count_zero = 0;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (s[i] == codeWord[j]) {
				s[i] = '0';
				if (codeWord[j] != '0') {
					count_zero++;
				}
			}
		}
	}
	for (int p = 0; p < 25; p++) {
		for (int i = 0; i < 25; i++) {
			if (s[i] == '0') {
				for (int j = i; j < 24; j++) {
					s[j] = s[j + 1];
				}

			}
		}
	}
	int e = 24;
	while (count_zero > 0) {
		s[e] = '0';
		count_zero--;
		e--;
	}


	int c = 0;
	int c2 = 0;
	matrix[0][1] = 'a';
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (codeWord[c] != '0') {
				matrix[i][j] = codeWord[c];
				c++;
			}
			else {
				matrix[i][j] = s[c2];
				c2++;
			}
		}
	}


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			return matrix[i][j];
		}
	}


}
vector<char> initText(vector<char> text, int answer) {
	ifstream in;
	if (answer == 1) {
		cout << "Введите текст оканчивая его точкой:";
	}
	else{
	
	in.open("in.txt");
	char ch;

	for (int i = 0; i < 9; i++) {
		in >> ch;

	}
	}
	char sym = '0';
	int cnt = 1;
	while (sym != '.') {
		if (answer == 1) {
			cin >> sym;
		}
		else
		{
			in >> sym;

		}
		if ((sym != '.') && (sym != ' ') && (sym != 'q') && (sym != 'Q')) {
			text.resize(cnt);
			sym = switchRegistr(sym);
			text[cnt - 1] = sym;
			cnt++;
		}
	}
	if(answer==2){
	in.close();
	}
	bool flag = true;
	for (int i = 0; i < text.size() - 1; i++) {
		if (flag) {
			if (text[i] == text[i + 1]) {
				text[i + 1] = 'x';
				flag = false;
			}
		}
		else {
			flag = true;
		}
	}
	if ((text.size() % 2) != 0) {
		text.resize(text.size() + 1);
		text[text.size() - 1] = 'x';
	}
	return text;


}
vector<char> encrypt(vector<char> text, char** matrix) {
	int* x = new int[text.size()];
	int* y = new int[text.size()];
	int* new_x = new int[text.size()];
	int* new_y = new int[text.size()];
	vector<char> new_text;
	new_text.resize(text.size());
	for (int p = 0; p < (text.size()); p++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (text[p] == matrix[i][j]) {
					x[p] = i;
					y[p] = j;
				}
			}
		}


	}
	for (int i = 0; i < text.size(); i += 2) {
		if (x[i] == x[i + 1]) {
			if (y[i] != 4) {
				new_y[i] = y[i] + 1;
				new_x[i] = x[i];
			}
			else {
				new_y[i] = 0;
				new_x[i] = x[i];
			}
			if (y[i + 1] != 4) {
				new_y[i + 1] = y[i + 1] + 1;
				new_x[i + 1] = x[i + 1];
			}
			else {
				new_y[i + 1] = 0;
				new_x[i + 1] = x[i + 1];
			}

		}
		if (y[i] == y[i + 1]) {
			if (x[i] != 4) {
				new_x[i] = x[i] + 1;
				new_y[i] = y[i];
			}
			else {
				new_x[i] = 0;
				new_y[i] = y[i];
			}
			if (x[i + 1] != 4) {
				new_x[i + 1] = x[i + 1] + 1;
				new_y[i + 1] = y[i + 1];
			}
			else {
				new_x[i + 1] = 0;
				new_y[i + 1] = y[i + 1];

			}
		}
		if ((x[i] != x[i + 1]) && (y[i] != y[i + 1])) {
			new_x[i] = x[i];
			new_x[i + 1] = x[i + 1];
			new_y[i] = y[i + 1];
			new_y[i + 1] = y[i];
		}
	}
	for (int p = 0; p < text.size(); p++) {
		new_text[p] = matrix[new_x[p]][new_y[p]];
	}



	return new_text;
}
vector<char> decrypt(vector<char> text, char** matrix) {
	int* x = new int[text.size()];
	int* y = new int[text.size()];
	int* new_x = new int[text.size()];
	int* new_y = new int[text.size()];
	vector<char> new_text;
	new_text.resize(text.size());
	for (int p = 0; p < (text.size()); p++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (text[p] == matrix[i][j]) {
					x[p] = i;
					y[p] = j;
				}
			}
		}


	}
	for (int i = 0; i < text.size(); i += 2) {
		if (x[i] == x[i + 1]) {
			if (y[i] != 0) {
				new_y[i] = y[i] - 1;
				new_x[i] = x[i];
			}
			else {
				new_y[i] = 4;
				new_x[i] = x[i];
			}
			if (y[i + 1] != 0) {
				new_y[i + 1] = y[i + 1] - 1;
				new_x[i + 1] = x[i + 1];
			}
			else {
				new_y[i + 1] = 4;
				new_x[i + 1] = x[i + 1];
			}

		}
		if (y[i] == y[i + 1]) {
			if (x[i] != 0) {
				new_x[i] = x[i] - 1;
				new_y[i] = y[i];
			}
			else {
				new_x[i] = 4;
				new_y[i] = y[i];
			}
			if (x[i + 1] != 0) {
				new_x[i + 1] = x[i + 1] - 1;
				new_y[i + 1] = y[i + 1];
			}
			else {
				new_x[i + 1] = 4;
				new_y[i + 1] = y[i + 1];

			}
		}
		if ((x[i] != x[i + 1]) && (y[i] != y[i + 1])) {
			new_x[i] = x[i];
			new_x[i + 1] = x[i + 1];
			new_y[i] = y[i + 1];
			new_y[i + 1] = y[i];
		}
	}
	for (int p = 0; p < text.size(); p++) {
		new_text[p] = matrix[new_x[p]][new_y[p]];
	}


	return new_text;
}
