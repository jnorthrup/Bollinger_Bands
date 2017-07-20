#include <vector>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
#include "Data.h"
#include "Strategy.h"
#include "Performance.h"

int main()
{
	Performance P; //Initializes an instance of the Performance class.
	P.run(2,20); //first parameter is the number of standard deviations for bands. 
				 //Second parameter is the number of periods in the moving average.
	cout<< "Sharpe Ratio: " << P.sharpe_ratio() << endl;
	
	system("pause");
}