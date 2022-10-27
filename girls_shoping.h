#include<conio.h>
#include<iostream>
#include"female_shoping.h"
#include<fstream>
using namespace std;
class female_staff :public girls
{
private:
	int price;
	int order_amount;

public:
	void input();
	void show();
	void heading();
	void store();
	void read();
	void search();

};
void female_staff::input()
{
	girls::input();
	cout << "enter price ::";
	cin >> price;
	cout << "enter order amount ::";
	cin >> order_amount;


}
void female_staff::show()
{
	int total_amount = price*order_amount;
	cout << sr << "\t" << name << "\t" << price << "\t\t" << order_amount << "\t" << total_amount << endl;
}
void female_staff::heading()
{
	girls::heading();
	cout << "price \t" << "order_amount \t" << "total_bill" << endl;
}
void female_staff::store()
{
	ofstream file;
	file.open("girl.txt", ios::out | ios::app);
	file.write((char*)this, sizeof(*this));
	if (file.fail())
	{
		cout << "file opening error ::";

	}
	file.close();
}
void female_staff::read()
{
	system("cls");
	ifstream file;
	file.open("girl.txt", ios::in);
	
	file.read((char*)this, sizeof(*this));
	heading();
	while (!file.eof())
	{
		show();
		file.read((char*)this, sizeof(*this));
	}
	file.close();
}
void female_staff::search()
{
	system("cls");
	ifstream search;
	search.open("girl.txt", ios::in);
	
	int n;
	cout << "enter serial for search ::";
	cin >> n;
	search.read((char*)this, sizeof(*this));
	heading();
	bool found = 0;
	while (!search.eof())
	{
		if (this->sr == n)
		{
			show();
			found = 1;
			break;

		}
		search.read((char*)this, sizeof(*this));
	}
	search.close();
}

