
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace   std;
#include "Data.h"
#include "Strategy.h"
#include "Performance.h"

Performance::Performance() = default;

void Performance::write_file(vector<vector<float>> input_vec, string filename)
	//Writes a vector of floats into a .txt file. Values separated by \n.
{
	ofstream outputFile;
	outputFile.open(filename);
	for (auto &i : input_vec) {
		for (float j : i) {
			outputFile << j;
			outputFile << '\n';
		}
	}
}

float Performance::sharpe_ratio()
	//Calculates the Sharpe Ratio for the simulation.
{
	vector<float> risk_free_data = read_csv("C:/Users/Class2016/Downloads/RiskFree.csv");
	for (float i : risk_free_data) {
		if(i > 1)
		{
			cout<< i << endl;
		}
	}
	risk_free = avg(risk_free_data);
	return (avg(returns) - risk_free)/std_dev(returns);
}

void Performance::matrix()
	//Creates a matrix of Sharpe Ratios in order to test optimality.
{
	float dev = 0.25;
	float movavg = 5;
	vector<float> temp_vec;
	for(int i = 0;i < 24; i++)
	{
		for(int j = 0;j<25;j++)
		{
			run(dev,movavg);
			temp_vec.push_back(sharpe_ratio());
			movavg += 1;
			returns.clear();
			buy_prices.clear();
			sell_prices.clear();
		}
		sharpe_matrix.push_back(temp_vec);
		temp_vec.clear();
		dev += 0.25;
		movavg = 5;
	}
	write_file(sharpe_matrix,"vector.txt");
}