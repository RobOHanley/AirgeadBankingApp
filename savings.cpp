#include <iostream>
#include "savings.h"
#include <iomanip>

using namespace std;

savings::savings(double investment, double monthDeposit, double rate, int years) 
{
	//This section creates pointers from our savings class and saves them to local variables
	this->initialDeposit = investment;
	this->monthlyDeposit = monthDeposit;
	this->interestRate = rate;
	this->numYears = years;
}

savings::~savings() 
{

}

//This defines a function so that it adds the interest gained to the amount in savings
void savings::statementWithoutDeposits()
{	
	//This prints out the header for the bank statement
	cout << "	Balance and Interest Without additional Monthly Deposits" << endl;
	cout << "================================================================================" << endl;
	cout << "      Year" << "        Year End Balance" << "          Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	
	int currentYear = 1;
	double yearEndBalance = this->initialDeposit;
	double interestEarned = 0.0;
	double monthEndBalance = yearEndBalance;
	//Creates a while loop that prints out our balances as long as the year is less than or equal to the years entered
	while (currentYear <= this->numYears)
	{
		double interestEarned = yearEndBalance * this->interestRate / 100;
		yearEndBalance += interestEarned;
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(20) << '$' << yearEndBalance << setw(35) << '$' << interestEarned << endl;
		++currentYear;

	}


}



void savings::statementWithDeposits() //Populating the function from our savings class
{
	//Shows the header display
	cout << "	  Balance and Interest With additional Monthly Deposits" << endl;
	cout << "================================================================================" << endl;
	cout << "      Year" << "        Year End Balance" << "          Year End Earned Interest Rate" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	
	//Declaring and initializing variables
	int currentYear = 1;
	double yearEndBalance = this->initialDeposit;

	//Creates a while loop that prints out our balances as long as the year is less than or equal to the years entered
	while (currentYear <= this->numYears)
	{
		int month = 1;
		double interestEarned = 0.0;
		double monthEndBalance = yearEndBalance;

		//This while loop loops over our months to add to our balances
		while (month <= 12)
		{
			monthEndBalance += this->monthlyDeposit;
			double monthlyInterest = monthEndBalance * this->interestRate / (100 * 12);
			interestEarned += monthlyInterest;
			monthEndBalance += monthlyInterest;
			++month;
		}
		yearEndBalance = monthEndBalance;
		//Final print statement that prints out all data for as many years as the user requires
		cout << right << setw(10) << currentYear << fixed << setprecision(2) << setw(17) << "$" << yearEndBalance << setw(33) << "$" << right << interestEarned << endl;
		++currentYear;
	}

}