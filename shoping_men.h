#include<conio.h>
#include<iostream>
#include"males_shoping.h"
#include<fstream>
using namespace std;
class male_staff:public men
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
void male_staff::input()
{
	system("cls");
	men::input();
	cout << "enter price ::";
	cin >> price;
	cout << "enter order amount ::";
	cin >> order_amount;


}
void male_staff::show()
{
	int total_amount = price*order_amount;
	cout << no << "\t" << name << "\t\t" << price << "\t\t" << order_amount << "\t" << total_amount << endl;
}
void male_staff::heading()
{
	men::heading();
	cout << "price \t" << "order_amount \t" <<"total_bill"<<endl;
}
void male_staff::store()
{
	system("cls");
	ofstream file;
	file.open("men.txt", ios::out | ios::app);
	file.write((char*)this, sizeof(*this));
	if (file.fail())
	{
		cout << "file opening error ::";

	}
	file.close();
}
void male_staff::read()
{
	system("cls");
	ifstream file;
	file.open("men.txt", ios::in);
	heading();
	file.read((char*)this, sizeof(*this));
	while(!file.eof())
	{
		show();
		file.read((char*)this, sizeof(*this));
	}
	file.close();
}
void male_staff::search()
{
	system("cls");
	ifstream search;
	search.open("men.txt", ios::in);
	heading();
	int n;
	cout << "enter serial for search ::";
	cin >> n;
	search.read((char*)this, sizeof(*this));
	bool found = 0;
	while (!search.eof())
	{
		if (this->no == n)
		{
			show();
			found = 1;
			break;

		}
		search.read((char*)this, sizeof(*this));
	}
	search.close();
}
