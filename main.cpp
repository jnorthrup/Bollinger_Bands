#include <vector>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
#include "Data.h"
#include "Strategy.h"
#include "Performance.h"

int main(int argc,const char **argv)
{
    Performance
            P;

    P= argc > 2 ? Performance(argv[1], argv[2]) : Performance();
    P.run(2,20); //first parameter is the number of standard deviations for bands.
    //Second parameter is the number of periods in the moving average.
    cout<< "Sharpe Ratio: " << P.sharpe_ratio() << endl;
//	system("pause");
}