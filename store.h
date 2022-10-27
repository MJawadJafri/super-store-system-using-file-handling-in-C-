#include<iostream>
#include<conio.h>
#include"supermarket.h"
#include<fstream>

using namespace std;

class Main :public product
{
private:
	char month[90];
	char day[9];

public:
	void getinfo();
	void showinfo();
	void heading();
	void store();
	void read();
	void delect();
	void search();
	void update();
};

void Main::getinfo()
{
	//gotoxy(7, 16);
	product::getinfo();
	cout << "enter order month::";
	cin >> month;
	cout << "enter order day ::";
	cin >> day;
	cout << "\t\t\'data ADDED to database\'\t \n";

}
void Main::heading()
{
	//gotoxy(7, 16);
	system("cls");
	product::heading();
	cout << "total_price \t" << "month \t" << "day \t ";
}
void Main::showinfo()
{
	int total_price = no_of_order*total_amount;
	cout << "\n" << orderid << " \t" << p_name << "\t\t" << no_of_order << "\t\t" << total_amount << "\t" << total_price << "\t\t" << month << "\t" << day << "\n";
	//cout << "data ADDED to database \n";
}
void Main::store()
{
	ofstream file;
	file.open("book.txt", ios::out | ios::app);
	if (file.fail())
	{
		cout << "error \n";
	}
	//syntext
	file.write((char *)this, sizeof(*this)); // file ko point kar raha han 
	file.close();
}
void Main::read()
{
	ifstream file;
	file.open("book.txt", ios::in);
	heading();
	file.read((char *)this, sizeof(*this));
	while (!file.eof()) //end of file
	{
		showinfo();
		file.read((char *)this, sizeof(*this));

	}
	file.close();
}
void Main::search()
{
	ifstream search;
	int id; 
	search.open("book.txt", ios::in);
	search.read((char *)this, sizeof(*this));
	cout << " enter product id \n";
	cin >> id;
	bool found = 0;
	heading();
	while (!search.eof())

	{
		if (this->no_of_order==id)
		{
			showinfo();
			found = 1;
			break;
		}
		search.read((char *)this, sizeof(*this));
	}
	if (found == 0)
	{
		cout << "data not found \n ";
	}
	search.close();
}
void Main::delect()
{
	ofstream newfile;
	ifstream original;
	int id;
	original.open("book.txt", ios::in);
	newfile.open("temp.txt", ios::out | ios::app);
	original.read((char*)this, sizeof(*this));
	cout << "enter number of order  to remove::";
	cin >> id;
	bool found = 0;
	heading();
	int m;
	while (!original.eof())
	{
		
		if (this->orderid == id)
		{
			found = 1;
			newfile.write((char*)this, sizeof(*this));
		} // if statement
		original.read((char *)this, sizeof(*this));
	}
	if (found == 0)
	{
		cout << "data not found \n ";
	}
	else
	{
		cout << "deleted file \n";
	}
	original.close();
	newfile.close();
	remove("book.txt");
	rename("temp.txt", "book.txt");
}
void Main::update()
{
	fstream update; //creating object
	int id;
	update.open("book.txt", ios::in | ios::out | ios::ate);
	update.seekg(0, ios::beg); //search form bengning;
	update.read((char*)this, sizeof (*this));
	cout << "enter no of order ::";
	cin >> id;
	cin.ignore();
	bool found = 0;
	int count = 0;
	char choice;
	while (!update.eof()) //infinite loop
	{
		count++;
		if (this->orderid == id)
		{
			cout << "press a for id change \n";
			cout << "press b for name change \n";
			cout << "press c for month change \n";
			cout << "press d for day change \n";
			cout << "press e for price change \n";
			cin >> choice;
			switch (choice)
			{
			case'a':
			{
					   cout << "enter order id ::";
					   cin >> orderid;
					   break;
			}
			case'b': //|| 'B'
			{
						 cout << "product name ::";
						 cin >> p_name;
						 break;

			}
			case 'c'://|| 'C'
			{
						 cout << "enter month ::";
						 cin >> month;
						 break;
			}
			case 'd':
			{
						cout << "enter day ::";
						cin >> day;
						break;
			}
			case 'e':
			{
						cout << "enter price ::";
						cin >> total_amount;
			}
			default:
			{
					   cout << "wrrong input \n";
			}

			}
			int pos = (count - 1)*sizeof(*this);
			update.seekg(pos);
			update.write((char*)this, sizeof(*this));
			found = 1;
			break;
		}
		update.read((char*)this, sizeof(*this));
	}
	if (found == 0)
	{
		cout << "NOT FOUND ";
	}
	update.close();
}

