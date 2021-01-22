#pragma once
#ifndef STRING_CLASS
#define STRING_CLASS
#include<string>
#include<vector>
using namespace std;

class StringClassException {};


class StringClass
{
private:
	char* stroka;
	int len;
	string findpodstr_special(const string str);    //поиск подстроки в строке с выводом всей строки до найденной подстроки. Нужен для работы со *
public:
	StringClass();
	StringClass(const string str);
	~StringClass();
	string getstr(int index);     //получение значения stroka
	char& operator[](int index);
	void operator=(string str);
	StringClass& operator+=(string str);
	string findpodstr(const string str);   //поиск подстроки по шаблоны и вывод её
	void paste(string str, int index);     //вставка строки в строку
	friend ostream& operator<<(ostream& out, const StringClass& str);
	int countPredl();					   //подсчёт предлогов
	vector<string> split(string str);      //разделение строки 
	void getStatLetters();                 //вывод всех букв и их количества в строке
	void getStatLetters(char c);           //вывод конкретной буквы и её количества в строке
	void getStatWords();                   //вывод всех слов и их количества в строке
	void getStatWords(string str);         //вывод конкретного слова и его количества в строке
	void getStatSentences();               //вывод всех предложений и их количества в строке
	void getStatSentences(string str);     //вывод конкретного предложения и его количества в строке
};

#endif

