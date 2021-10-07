#ifndef SAVINGS_H_
#define SAVINGS_H_


//Created a file to declare my savings class 
class savings 
{
	public:

		savings(double investment, double monthDeposit,double rate, int years); //Created a savings function
		virtual ~savings(); //Creating a virtual function
		//Creating public functions that can be used form the class
		void statementWithoutDeposits();
		void statementWithDeposits();

	
private:

	//Declaring private variables
	double initialDeposit;
	double monthlyDeposit;
	double interestRate;
	int numYears;
};


#endif