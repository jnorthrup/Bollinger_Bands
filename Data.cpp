#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <backward/strstream>

using namespace std;
#include "Data.h"
#include "Strategy.h"

vector<float> Data::read_csv(string filename)
	//Reads in a .csv file and returns it as a vector.
{
	vector<float> PricesTemp;
	vector<float> data;
	ifstream in(filename);

	if(!in.good()){
		strstream x;
		x<<"invalid input filename: "<<filename;
		__throw_invalid_argument(x.str());
	}else
	if(  in)
	{
		string line;
		while(getline(in,line))
		{
			PricesTemp.push_back(static_cast<float &&>(stod(line)));
		}
	}
	in.close();

	for( auto item:PricesTemp)
	{
		data.push_back(item);
	}

	return data;
}