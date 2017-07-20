#pragma once

class Performance : public Strategy {
public:
     Performance(const string &ifn="CSV/ADS.csv",   const  string & ofn="/tmp/bollinger_out.txt")
            : Strategy::Strategy(ifn ), ofname(ofn)
    { };

    float sharpe_ratio(); //Calculates the Sharpe ratio based on the returns vector.

private:
    std::string  ofname;
    float risk_free;

    void matrix(); //Creates the matrix used to find the optimal arguments for the strategy.
    vector<vector<float>> sharpe_matrix;

    void write_file(vector<vector<float>> input_vec); //Writes a vector of vectors to a .txt file
};