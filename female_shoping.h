#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class girls
{
protected:
	int sr;
	string name;
public:
	void input();
	void heading();
};
void girls::input()
{
	cout << "enter serial number ::";
	cin >> sr;
	cout << "enter product ::";
	cin.ignore();
	getline(cin, name);
}
void girls::heading()
{
	cout << "sr#" << "\t" << "product_type \t";
}

