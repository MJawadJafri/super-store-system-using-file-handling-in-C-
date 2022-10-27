#include<iostream>
#include<conio.h>
using namespace std;
class product
{
protected:
	char p_name[20];
	int total_amount;
	int no_of_order;
	int orderid;
public:
	void getinfo(); //defination
	void heading();

};
void product::getinfo()
{
	system("cls");
	cout << " \n enter product order id \n";
	cin >> orderid;
	cout << "enter product name ::";
	cin >> p_name;
	cout << "enter number of order";
	cin >> no_of_order;
	cout << "product market price \n";
	cin >> total_amount;
}
void product::heading()
{

	system("cls");
	cout << "sr # \t" << " product name \t" << "no.of order \t" << "price \t";
}

