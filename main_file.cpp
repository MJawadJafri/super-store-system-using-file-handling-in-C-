#include<iostream>
#include<conio.h>
#include"store.h"
#include"shoping_men.h"
#include"girls_shoping.h"
using namespace std;
int main()
{
		int n; // for first switch statement
		int m; // for second switch
		int p; //3rd switch
		Main m1;
		male_staff men;
		female_staff female;
		//order op;
	L1:
		system("cls");
		cout << "\t\tWelcome to Superstore \n";
		cout << "\t\t press 1 for inputdata \n";
		cout << "\t\t press 2 for readdata \n";
		cout << "\t\t press 3 for searchdata \n";
		cout << "\t\t press 4 for deletedata \n";
		cout << "\t\t press 5 for updatedata \n";
		cout << "\t\t press 6 for male-store \n";
		cout << "\t\t press 7 for female-store \n";
		//cout << "\t\t press 8 for admin-panal \n";
		cout << "enter choice ::";
		cin >> n;
		switch (n)
		{
		case 1:
		{
				  m1.getinfo();
				  m1.store();
				  break;
		}
		case 2:
		{
				  m1.read();
				  break;

		}
		case 3:
		{
				  m1.search();
				  break;
		}
		case 4:
		{
				  m1.delect();
				  break;
		}
		case 5:
		{
				  m1.update();
				  break;
		}
		case 6:
		{
			  d:
				  system("cls");
				  cout << "\t\tWELCOME in male shoping store \n";
				  cout << "\t\tpress 1 for input data \n";
				  cout << "\t\tpress 2 for read data \n";
				  cout << "\t\tpress 3 for search data \n";
				  cout << "enter your choice::";
				  cin >> m;
				  switch (m)
				  {
				  case 1:
					  men.input();
					  men.store();
					  break;
				  case 2:
					  men.read();
					  break;
				  case 3:
					  men.search();
					  break;

				  default:
					  cout << "input error \n";
				  }// second switch statement 
				  char t;
				  cout << "enter y to male store ::";
				  cin >> t;
				  if (t == 'y')
				  {
					  goto d;
				  }
				  else
				  {
					  system("cls");
					  cout << "\t thanks for visit sir \n";
				  }
				  break;
		}
		case 7:
		{
			  w:
				  system("cls");
				  cout << "\t\tWELCOME in female shoping store \n";
				  cout << "\t\tpress 1 for input data \n";
				  cout << "\t\tpress 2 for read data \n";
				  cout << "\t\tpress 3 for search data \n";
				  cout << "enter your choice::";
				  cin >> m;
				  switch (m)
				  {
				  case 1:
					  female.input();
					  female.store();
					  break;
				  case 2:
					  female.read();
					  break;
				  case 3:
					  female.search();
					  break;

				  default:
					  cout << "input error \n";
				  }// second switch statement 
				  char t;
				  cout << "enter y to continue ::";
				  cin >> t;
				  if (t == 'y')
				  {
					  goto w;
				  }
				  else
				  {
					  cout << "\t thanks for visit ma'am \n";
				  }
				  break;
		}
		/*case 8:
			op.input();
			op.store();
			op.read();
			break;
		*/

		default:
			cout << "input error \n";
		} //switch bracket
		char y;
		cout << "enter y to main-menu ::";
		cin >> y;
		if (y == 'y' || y == 'Y')
		{
			goto L1;
		}
		else
		{
			system("cls");
			cout << "******** thanks for visit ************* \n";

		}

		_getch();
		system("pause");
	}// main bracket


