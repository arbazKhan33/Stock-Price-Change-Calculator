// This code was compiled on Microsoft Visual Studio 2019
// Will take stock data inputted from user, compute price change over 2 day span, and display the highest percent changing stock to console
// Written by Arbaz Khan         


#include<iostream>
#include<vector>

using namespace std;


struct stock                // delcare struct 
{

	string stockName;        //variables for stocks    
	float day1Price;
	float day2Price;
	float perChange;

};
//*****************************************************************************************************

int main() 

{

	int numOfstocks;

	cout << "How many stocks do you want to compare?" << endl;
	cin >> numOfstocks;                   // stores number of stocks 

	vector<stock> stocks(numOfstocks);    //  vector of number of stocks 

	for (int i = 0; i < numOfstocks; i++)  // loop stock data
	{

		cout << "Input Stock Name:" << endl;            // stock name input
		cin >> stocks[i].stockName;

		cout << "Input Stock Price on Day 1:" << endl;    // stock price day 1 input
		cin >> stocks[i].day1Price;

		cout << "Input Stock Price on Day 2:" << endl;    // stock price day 2 input
		cin >> stocks[i].day2Price;

		stocks[i].perChange = ((stocks[i].day2Price - stocks[i].day1Price) * 100) / stocks[i].day1Price;    // calculate percent change 
		cout << endl;
		
	}

	float alpha = stocks[0].perChange;
	int delta;
	
	for (int x = 0; x < numOfstocks; x++)         // loop compares to see which stock increased most 
	{

		if (stocks[x].perChange > alpha)
		{
			alpha = stocks[x].perChange;
			delta = x;
		}

	}

	cout << "Stock With Maximum Growth: " << endl;                // stock data of stock with higher increase displayed to console
	cout << "****************************" << endl;
	cout << "Stock Name: " << stocks[delta].stockName << endl;
	cout << "Day 1 Price: " << stocks[delta].day1Price << endl;
	cout << "Day 2 Price: " << stocks[delta].day2Price << endl;
	cout << "Percent Change: " << stocks[delta].perChange << "%"<< endl;

	return 0;

}
