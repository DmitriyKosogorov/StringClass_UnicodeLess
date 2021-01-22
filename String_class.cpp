#include<iostream>
#include<string>
#include<vector>
#include "String_class.h"

using namespace std;

StringClass::StringClass()
{
	len = 0;
	stroka = new char[0];
}
StringClass::StringClass(const string str)
{
	len = str.length();
	stroka = new char[len];
	for (int i = 0; i < len; i++)
		stroka[i] = str[i];
}
StringClass::~StringClass()
{
	/*cout << "deleted ";
	for (int i = 0; i < len; i++)
		cout << stroka[i];
	cout <<" "<<this<< endl;*/
	delete[] stroka;
}
string StringClass::getstr(int index)
{
	string res;
	if(index<0 || index>=len)
		throw StringClassException();
	else
	for (int i = index; i < len; i++)
		res = res + stroka[i];
	return res;
}
char& StringClass::operator[](int index)
{
	if (index < 0 || index >= len)
		throw StringClassException();
	else
		return stroka[index];
}
ostream& operator<<(ostream& out, const StringClass& str)
{
	for (int i = 0; i < str.len; i++)
		out << str.stroka[i];
	return out;
}
void StringClass::operator=(string str)
{
	len = str.length();
	char* newstroka = new char[len];
	for (int i = 0; i < len; i++)
		newstroka[i] = str[i];
	delete[] stroka;
	stroka = newstroka;
}

StringClass& StringClass::operator+=(string str)
{
	int i,n=len,m=str.length();
	char* newstroka = new char[len+m];
	for (i = 0; i < len; i++)
	{
		newstroka[i] = stroka[i];
		//cout << newstroka[i];
	}
	len = len + m;
	for (i = 0; i < m; i++)
	{
		newstroka[n + i] = str[i];
		//cout << newstroka[n+i];
	}
	cout << endl;
	delete[] stroka;
	stroka = newstroka;
	return *this;
}

string StringClass::findpodstr_special(const string str)
{
	int k = 0, i, j;
	string rightstr,notrightstr;
	for (i = 0; i < len; i++)
	{
		k = 0;
		for (j = i; j < len; j++)
		{

			if (stroka[j] == str[k] || str[k] == '?')
			{
				rightstr += stroka[j];
				k++;
			}
			else
				if (str[k] == '#')
				{
					switch (stroka[j])
					{
					case '0': k++; rightstr += stroka[j]; break;
					case '1': k++; rightstr += stroka[j]; break;
					case '2': k++; rightstr += stroka[j]; break;
					case '3': k++; rightstr += stroka[j]; break;
					case '4': k++; rightstr += stroka[j]; break;
					case '5': k++; rightstr += stroka[j]; break;
					case '6': k++; rightstr += stroka[j]; break;
					case '7': k++; rightstr += stroka[j]; break;
					case '8': k++; rightstr += stroka[j]; break;
					case '9': k++; rightstr += stroka[j]; break;
					default: break;
					}
				}
				else
					if (str[k] == '*')
					{
						string gig = str.substr(k + 1, str.length());
						string find = this->getstr(j);
						StringClass gig1(find);
						string next = gig1.findpodstr_special(gig);
						if (next != "" || gig == "")
						{
							rightstr += next;
							notrightstr += rightstr;
							return notrightstr;
						}
					}
					else
						break;
			if (k == str.length())
			{
				notrightstr += rightstr;
				return notrightstr;
			}


		}

		notrightstr += stroka[i];
	}
	return "";
}

void StringClass::paste(string str, int index)
{
	if (index < 0 || index >= len)
		throw StringClassException();
	else
	{
		int n = len, m = str.length(), i, j;
		char* newstroka = new char[n + m];
		for (i = 0; i < index; i++)
			newstroka[i] = stroka[i];
		for (i = 0; i < m; i++)
			newstroka[index + i] = str[i];
		for (i = 0; i < n - index; i++)
			newstroka[index + m + i] = stroka[i + index];
		delete[] stroka;
		stroka = newstroka;
	}
}

string StringClass::findpodstr(const string str)
{
	int k = 0,i,j,rightlen=0;
	string rightstr;
	for (i = 0; i < len; i++)
	{
		k = 0;
		for (j = i; j < len; j++)
		{
			
			if (stroka[j] == str[k] || str[k] == '?')
			{
				rightstr += stroka[j];
				k++;
			}
			else
				if (str[k] == '#')
				{
					switch (stroka[j])
					{
					case '0': k++; rightstr += stroka[j]; break;
					case '1': k++; rightstr += stroka[j]; break;
					case '2': k++; rightstr += stroka[j]; break;
					case '3': k++; rightstr += stroka[j]; break;
					case '4': k++; rightstr += stroka[j]; break;
					case '5': k++; rightstr += stroka[j]; break;
					case '6': k++; rightstr += stroka[j]; break;
					case '7': k++; rightstr += stroka[j]; break;
					case '8': k++; rightstr += stroka[j]; break;
					case '9': k++; rightstr += stroka[j]; break;
					default: break;
					}
				}
				else
					if (str[k] == '*')
					{
						string gig = str.substr(k + 1, str.length());
						string find = this->getstr(j);
						StringClass gig1(find);
						string next = gig1.findpodstr_special(gig);
						if (next != "" || gig == "")
						{
							rightstr += next;
							return rightstr;
						}
					}
					else break;
			if (k == str.length())
			{
				return rightstr;
			}


		}
	}
	return "";
}




vector<string> StringClass::split(string str)
{
	vector<string> words;
	string word;
	int i,j,k;
	bool b;
	for (i = 0; i < len; i++)
	{
		if (stroka[i] == str[0] && i+str.length()<len)
		{
			k = 0;
			b = true;
			for (j = i; j < i+str.length(); j++)
			{
				if (stroka[j] != str[k])
				{
					b = false;
					break;
				}
				k++;
			}
			if (b == true)
			{
				words.push_back(word);
				word = "";
				i = i + str.length();
			}
		}
		word += stroka[i];
	}
	words.push_back(word);
	return words;
}

void StringClass::getStatLetters()
{
	bool b;
	vector<char> letters;
	vector<int> stats;
	for (int i = 0; i < len; i++)
	{
		b = false;
		for (int j = 0; j < letters.size(); j++)
		{
			if (stroka[i] == letters[j])
			{
				stats[j]++;
				b = true;
			}
		}
		if (b == false)
		{
			letters.push_back(stroka[i]);
			stats.push_back(1);
		}
	}
	for (int i = 0; i < letters.size(); i++)
		cout << letters[i] << " " << stats[i] << endl;
}

void StringClass::getStatLetters(char c)
{
	bool b;
	int stats=0, i;
	for (i = 0; i < len; i++)
		if (stroka[i] == c)
			stats++;
	cout << c << " " << stats<<endl;
}

void StringClass::getStatWords()
{
	int i;
	bool b;
	vector<string> words = this->split(" ");
	vector<string> answer;
	vector<int> stats;
	for (i = 0; i < words.size(); i++)
	{
		b = false;
		for (int j = 0; j < answer.size(); j++)
		{
			if (words[i] == answer[j])
			{
				stats[j]++;
				b = true;
			}
		}
		if (b == false)
		{
			answer.push_back(words[i]);
			stats.push_back(1);
		}
	}
	for (i = 0; i < answer.size(); i++)
		cout << answer[i] << " " << stats[i] << endl;
}

void StringClass::getStatWords(string str)
{
	int i;
	vector<string> words = this->split(" ");
	int stats = 0;
	for (i = 0; i < words.size(); i++)
	{
		if (words[i] == str)
			stats++;
	}
	cout << str << " " << stats<<endl;

}

void StringClass::getStatSentences()
{
	int i;
	bool b;
	vector<string> words = this->split(". ");
	vector<string> answer;
	vector<int> stats;
	for (i = 0; i < words.size(); i++)
	{
		b = false;
		for (int j = 0; j < answer.size(); j++)
		{
			if (words[i] == answer[j])
			{
				stats[j]++;
				b = true;
			}
		}
		if (b == false)
		{
			answer.push_back(words[i]);
			stats.push_back(1);
		}
	}
	for (i = 0; i < answer.size(); i++)
		cout << answer[i] << " " << stats[i] << endl;
}

void StringClass::getStatSentences(string str)
{
	int i;
	vector<string> words = this->split(". ");
	int stats = 0;
	for (i = 0; i < words.size(); i++)
	{
		if (words[i] == str)
			stats++;
	}
	cout << str << " " << stats << endl;

}


int StringClass::countPredl()
{
	int stats = 0;
	vector<string> predlogs = { "bez", "bezo","bliz","v", "vo", "vmesto","vne", "dlya", "do", "za", "iz", "izo",
		"iz-za", "iz-pod", "k", "ko", "krome", "mezhdu", "mezh", "na", "nad", "o", "ob", "obo", "ot", "oto", "pered",
		"peredo", "pred", "po", "pod", "podo", "pri", "pro", "radi","s", "so", "skvoz" , "sredi" , "u" , "cherez" , "chrez" };
	vector<string> words = this->split(" ");
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < predlogs.size(); j++)
		{
			if (words[i] == predlogs[j] || words[i] == predlogs[j] + ", " || words[i] == predlogs[j] + ". ")
			{
				stats++;
				break;
			}
		}
	}
	return stats;
}