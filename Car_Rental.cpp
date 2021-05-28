#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

class LoginSetup
{
	void Reg()
	{
		ofstream fout;
		fout.open("UserDatabase.txt", ios::app);
		string name, Pw;
		getline(cin, name);
		getline(cin, Pw);
		fout << name << "\n"
			 << Pw << "\n";
		fout.close();
	}

	bool logi()
	{
		ifstream fin("UserDatabase.txt");
		if (!fin.is_open())
		{
			cout << "Could Not Open File\n";
			return false;
		}
		string Name, Password;
		cout << "Enter User Name : ";
		getline(cin, Name);
		cout << "Enter Password : ";
		getline(cin, Password);
		string Nam, Pass;
		while (!fin.eof())
		{
			getline(fin, Nam);
			getline(fin, Pass);
			if (Nam == Name && Pass == Password)
			{
				cout << "Login Successful :)\n\n";
				fin.close();
				return true;
			}
		}
		fin.close();
		cout << "Information not Correct Please try again\n\n";
		return false;
	}

public:
	void Registration()
	{
		Reg();
	}

	bool UserLogin()
	{
		return logi();
	}
};

class Welcome
{
public:
	void welcum()
	{
		ifstream fin("welcome.txt");

		if (!fin)
		{
			cout << "File cannot open\n";
		}
		char str[1000];
		while (fin)
		{
			fin.getline(str, 500); // read upto '\n'
			if (fin)
				cout << str << endl;
		}
		fin.close();
		Sleep(1000); // wait for 1 second
		cout << "\nStarting the program please wait...." << endl;
		Sleep(1000);
		cout << "\nLoading up Files.....\n";
		Sleep(1000);
		system("cls"); //clear screen
	}
};

class customer
{
public:
	string name;
	string carmodel;
	string carnumber;
	char data;
};

class Rent : public customer
{
public:
	int days = 0, rentalfee = 0;
	void start()
	{
		cout << "\t\t\t\tPlease Enter your Name: ";
		cin >> name;
		cout << endl;

		do
		{
			cout << "\t\t\t\tPlease Select a Car" << endl; //giving user a choice to select among three different models
			cout << "\t\t\t\tEnter 'A' for Tesla 20011." << endl;
			cout << "\t\t\t\tEnter 'B' for Hyundai 2015." << endl;
			cout << "\t\t\t\tEnter 'C' for Ford 2017." << endl;
			cout << endl;
			cout << "\t\t\t\tChoose a Car from the above options: ";
			cin >> carmodel;
			cout << endl;
			cout << "--------------------------------------------------------------------------" << endl;

			if (carmodel == "A")
			{
				system("cls");
				cout << "You have choosed Tesla model 2011\n";
				ifstream fin("Tesla2011.txt");
				char str[200];
				while (fin)
				{
					fin.getline(str, 200);
					if (fin)
						cout << str << endl;
				}
				Sleep(2000);
			}
			if (carmodel == "B")
			{
				system("cls");
				cout << "You have choosed Hyundai 2015\n";
				ifstream fin("Hyundai2015.txt");
				char str[200];
				while (fin)
				{
					fin.getline(str, 200);
					if (fin)
						cout << str << endl;
				}
				Sleep(2000);
			}
			if (carmodel == "C")
			{
				system("cls");
				cout << "You have choosed Ford 2017\n";
				ifstream fin("Ford2017.txt");
				char str[200];
				while (fin)
				{
					fin.getline(str, 200);
					if (fin)
						cout << str << endl;
				}
				Sleep(2000);
			}
			if (carmodel != "A" && carmodel != "B" && carmodel != "C")
			{
				cout << "Invalid Car Model....." << endl;
			}
		} while (carmodel != "A" && carmodel != "B" && carmodel != "C");
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Please provide following information: " << endl;
		//getting data from user related to rental service
		cout << "Please select a Car No. : ";
		cin >> carnumber;
		cout << "Number of days you wish to rent the car : ";
		cin >> days;
		cout << endl;
	}
	void calculate()
	{
		Sleep(1000);
		system("CLS");
		cout << "Calculating rent. Please wait......" << endl;
		Sleep(2000);
		if (carmodel == "A" || carmodel == "a")
			rentalfee = days * 56;
		if (carmodel == "B" || carmodel == "b")
			rentalfee = days * 60;
		if (carmodel == "C" || carmodel == "c")
			rentalfee = days * 75;
	}

	void showrent()
	{
		cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
		cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
		cout << "\t\t	| Invoice No. :"
			 << "------------------|" << setw(10) << "#Cnb" << rand() % 14568
			 << " |" << endl;
		cout << "\t\t	| Customer Name:"
			 << "-----------------|" << setw(10) << name << " |" << endl;
		cout << "\t\t	| Car Model :"
			 << "--------------------|" << setw(10) << carmodel << " |" << endl;
		cout << "\t\t	| Car No. :"
			 << "----------------------|" << setw(10) << carnumber << " |" << endl;
		cout << "\t\t	| Number of days :"
			 << "---------------|" << setw(10) << days << " |" << endl;
		cout << "\t\t	| Your Rental Amount is :"
			 << "--------|" << setw(10) << rentalfee << " |" << endl;
		cout << "\t\t	| Caution Money :"
			 << "----------------|" << setw(10) << "0"
			 << " |" << endl;
		cout << "\t\t	| Advanced :"
			 << "---------------------|" << setw(10) << "0"
			 << " |" << endl;
		cout << "\t\t	 ________________________________________________________" << endl;
		cout << "\n";
		cout << "\t\t	| Total Rental Amount is :"
			 << "-------|" << setw(10) << rentalfee << " |" << endl;
		cout << "\t\t	 ________________________________________________________" << endl;
		cout << "\t\t	 # This is a computer generated invoce and it does not" << endl;
		cout << "\t\t	 require an authorised signture #" << endl;
		cout << " " << endl;
		cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
		cout << "\t\t	You are advised to pay up the amount before due date." << endl;
		cout << "\t\t	Otherwise penelty fee will be applied" << endl;
		cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
		int f;
		system("PAUSE");

		system("CLS");

		ifstream inf("thanks.txt");

		char str[300];

		while (inf)
		{
			inf.getline(str, 300);
			if (inf)
				cout << str << endl;
		}
		inf.close();
	}
};

void solve()
{
	/*Welcome W;
	W.welcum();*/

	LoginSetup l;
	if (l.UserLogin())
	{
		Rent r;
		r.start();
		r.calculate();
		r.showrent();
	}
}

int main()
{
	solve();
	return 0;
}
