#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class men
{
protected:
	int  no;
	string name;

public:
	void input();
	void heading();

};
void men::input()
{
	cout << "enter serial number ::";
	cin >> no;
	cout << "enter product ::";
	cin.ignore();
	getline(cin, name);
}
void men::heading()
{
	cout << "sr#" << "\t" << "product_type \t";
}

