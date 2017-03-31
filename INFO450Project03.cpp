// INFO450Project03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
class Account
{
protected:
	static int idGenerator;
	int accountNumber;
	double intrestRate = 0;
	double Balance = 0;
	double DepAmt;
	double WithAmt;
	int Term;
	
	
public:
	const char *accountType = new char[100];
	virtual void displayAccount();
	virtual int Deposit(double DepAmt);
	virtual int Withdrawl(double WithAmt);
	int generateID();

	
	
};

int Account::idGenerator = 0;

int Account::generateID()
{
	idGenerator++;
	accountNumber = idGenerator;
	return accountNumber;
}
void Account::displayAccount()
{
	cout << "Account #:" << accountNumber << endl;
	cout << "Account Type: " << accountType << endl;
	cout << "Balance: " << Balance << endl;
	cout << "Interest Rate: " << intrestRate << "%" << endl << endl;
	
}

int Account::Deposit(double DepAmt)
{
	if (DepAmt <= 0)
	{
		cout << "Deposit must be a positive number" << endl;
		return(-1);
	}
	else
	{
		Balance = DepAmt + Balance;
		return (0);
	}
	

}

int Account::Withdrawl(double WithAmt)
{
	if (Balance <= 0)
	{
		cout << "Account balance is 0" << endl;
		return(-1);
	}
	else if (WithAmt > Balance)
	{
		cout << "Insufficient Funds" << endl;
		return(-1);
	}
	else
	{
		Balance = Balance - WithAmt;
		return(0);
	}
	
}


class Savings : public Account
{
public:
	Savings()
	{
		accountType = "Savings Account";
	}
	void CheckBalance()
	{
		if (Balance >= 10000)
		{
			intrestRate = 2.0;
		}
		else
		{
			intrestRate = 1.0;
		}
	}	
	
	void CompoundInterest()
	{
		Balance = Balance + (Balance * (intrestRate / 100) / 12);
	}
};

class Checking : public Account
{
public:
	Checking()
	{
		accountType = "Checking Account";
	}
	void CheckBalance()
	{
		if (Balance < 500)
		{
			Balance = Balance - 5;
			cout << "A monthly mantainance fee of 5$ has been deducted from your account" << endl;
		}
	}
	void OrderChecks()
	{
		Balance = Balance - 15;
		cout << "15$ has been deducted from your account to order new checks" << endl;
	}
	void CompoundInterest()
	{
		Balance = Balance + (Balance * (intrestRate / 100) / 12);
	}
};

class CD : public Account
{
public:

	
	CD(int CDTerm)
	{
		accountType = "Certificate of Deposit";
		Term = CDTerm;
	}
	void CheckBalance()
	{
		if (Term >= 5)
		{
			intrestRate = 10.0;
		}
		else
		{
			intrestRate = 5.0;
		}
	}
	void CompoundInterest()
	{
		Balance = Balance + (Balance * (intrestRate / 100) / 12);
	}
	void Penalty()
	{
		Balance = Balance - (Balance * 0.10);
	}
};

void instructions()
{
	cout << "This is a program that will open several bank accounts and them \nperform various transactions on the accounts \n" << "\nAuthor: Patrick Laughlin" << endl << endl;
	system("PAUSE");
	system("CLS");
}


int main()
{
	
	instructions();

	Savings One;
	One.generateID();
	One.Deposit(10000);
	One.CheckBalance();
	One.displayAccount();
	
	Checking Two;
	Two.generateID();
	Two.Deposit(600);
	Two.CheckBalance();
	Two.displayAccount();

	CD Three(3);
	Three.generateID();
	Three.Deposit(10000);
	Three.CheckBalance();
	Three.displayAccount();

	One.CompoundInterest();
	Three.CompoundInterest();

	One.displayAccount();
	Two.displayAccount();
	Three.displayAccount();

	Two.OrderChecks();
	Two.Withdrawl(200);
	One.Withdrawl(1000);
	Three.Penalty();
	Three.Withdrawl(2000);

	One.displayAccount();
	Two.displayAccount();
	Three.displayAccount();



	
		

	system("PAUSE");
    return 0;
}

