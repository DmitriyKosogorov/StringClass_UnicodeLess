#include<iostream>
#include<string>
#include"String_Class.cpp"
using namespace std;
int main()
{
	int i;
	StringClass s("kdjfhsfgoshf"), a("Na dvore trava na trave drova na na trava");
	cout << s << endl;
	s = "gdf9d";
	s += "sDDbkl";
	cout <<"adding "<<endl<< s << endl;
	cout << "podstroka " << s.findpodstr("#d*b") << endl;
	cout << "getstatsletter(d): " << endl;
	s.getStatLetters('d');
	vector<string> words = a.split(" t");
	cout << "split:" << endl;
	for (i = 0; i < words.size(); i++)
		cout << i << "): " << words[i] << endl;
	a.getStatWords("na");
	a.paste("Kolodec", 6);
	cout << a<<endl<<a.countPredl()<<endl;

}