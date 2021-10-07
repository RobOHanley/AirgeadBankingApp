#include <iostream>
#include <stdio.h>
#include "savings.h"

using namespace std;

int main()
{
	bool exit = false;
	while (exit != true) {
		//Printing the automatic ouput for the banking layout
		cout << "************************************" << endl;
		cout << "*************Data Input*************" << endl;
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;
		cout << "Annual Interest: " << endl;
		cout << "Number of years: " << endl;
		cout << "Press any key to continue . . ." << endl;
		cin.get(); //This verifies if the user pressed a key and then continues with the program
		//Declaring variables
		double investment;
		double monthlyDeposit;
		double interestRate;
		int years;
		//Printing out statements and getting user input
		cout << "************************************" << endl;
		cout << "*************Data Input*************" << endl;
		cout << "Initial Investment Amount: $";
		cin >> investment;
		cout << "\nMonthly Deposit: $";
		cin >> monthlyDeposit;
		cout << "\nAnnual Interest: %";
		cin >> interestRate;
		cout << "\nNumber of years: ";
		cin >> years;
		cout << "Press any key to continue . . ." << endl;
		cin.get(); //Verifying the user pressed any key
		cout << endl;

		savings potentialSavings = savings(investment, monthlyDeposit, interestRate, years); //Creating local way to call our functions in savings.cpp

		//This function call is to print out what the savings would look like without a monthly deposit
		potentialSavings.statementWithoutDeposits();
		cout << endl;

		//This if statement checks if the deposit is over 0 and calls the appropriate function
		if (monthlyDeposit > 0)
		{
			potentialSavings.statementWithDeposits();
			cout << endl;
		}



		//This section asks the user if they want to enter different amounts and acts accordingly
		cout << "Would you like to enter different amounts? (y/n): ";
		char userChoice;
		cin >> userChoice;

		if (userChoice != 'y') {
			exit = false;
			break;
		}


	}
	return 0;
}