#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
#include "Data.h"
#include "Strategy.h"

vector<float> Data::read_csv(string filename)
	//Reads in a .csv file and returns it as a vector.
{
	vector<float> PricesTemp;
	vector<float> data;
	ifstream in(filename);
	if(in)
	{
		string line;
		while(getline(in,line))
		{
			PricesTemp.push_back(stod(line));
		}
	}
	in.close();
    auto count = static_cast<int>(PricesTemp.size() - 1);
	for( int i=count; i >= 0; i--)
	{
		data.push_back(PricesTemp.at(i));
	}

	return data;
}