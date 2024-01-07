#include <iostream>
#include <cmath>
using namespace std;

/*
1. Implement Black-Scholes for baseline comparison DONE
2. Implement Monte Carlo simulation of future stock prices
3. Use gnuplot to graph simulated paths
4. Experiment with multi-threading or parallelization to speed up simulations
5. Error loop for inputs
6. Extra?
*/

double normal_cdf(double x){
    return (1.0 + erf(x / sqrt(2.0))) / 2;
}

double black_scholes(double S, double K, double T, double r, double sigma, char option_type){
    double d1, d2;

    d1 = (log(S / K) + (r + pow(sigma, 2) / 2) * T) / (sigma * sqrt(T));
    d2 = d1 - sigma * sqrt(T);

    if(option_type == 'P'){
        return K * exp(-r * T) * normal_cdf(-d2) - S * normal_cdf(-d1);
    }
    else if(option_type == 'C'){
        return S * normal_cdf(d1) - K * exp(-r * T) * normal_cdf(d2);
    }
    else{
        cerr << "Incorrect Option Type. Use 'P' or 'C' for Put and Call Respectively." << endl;
        return 0;
    }
}

int main(){
    double stock_price, strike_price, maturity_time, risk_free_rate, volatility;
    char option_type;

    cout << "Current Stock Price: ";
    cin >> stock_price;

    cout << "Strike Price: ";
    cin >> strike_price;

    cout << "Time to Maturity: ";
    cin >> maturity_time;

    cout << "Risk-Free Interest Rate: ";
    cin >> risk_free_rate;
    
    cout << "Asset Volatility: ";
    cin >> volatility;

    cout << "Put 'P' or Call 'C': ";
    cin >> option_type;

    double bs_price = black_scholes(stock_price, strike_price, maturity_time, risk_free_rate, volatility, option_type);
    cout << "The Black-Scholes Option Price is " << bs_price;
    return 0;
}