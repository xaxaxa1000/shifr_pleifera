#pragma once
#include<vector>
using namespace std;
int question(int answer[]);
vector<char> initText(vector<char> text,int answer);
vector<char> initCodeText(vector<char> text, int answer);
char initCodeWord(char codeWord[], int count,int answer);
char switchRegistr(char symbol);
char deleteSameSybols(char codeWord[],int count);
char fillMatrix(char **matrix,char codeWord[]);
vector<char> encrypt(vector<char> text, char** matrix);
vector<char> decrypt(vector<char> text, char** matrix);