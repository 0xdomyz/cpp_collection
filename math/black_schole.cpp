// g++ black_schole.cpp -o black_schole -std=c++11 && ./black_schole

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

double norm_cdf(double x)
{
    return 0.5 * erfc(-x * M_SQRT1_2);
}

double norm_pdf(double x)
{
    return exp(-x * x / 2.0) / sqrt(2.0 * M_PI);
}

double black_scholes_call(double S, double K, double r, double sigma, double time)
{
    double d1 = (log(S / K) + (r + sigma * sigma / 2.0) * time) / (sigma * sqrt(time));
    double d2 = d1 - sigma * sqrt(time);
    return S * norm_cdf(d1) - K * exp(-r * time) * norm_cdf(d2);
}

double black_scholes_put(double S, double K, double r, double sigma, double time)
{
    double d1 = (log(S / K) + (r + sigma * sigma / 2.0) * time) / (sigma * sqrt(time));
    double d2 = d1 - sigma * sqrt(time);
    return K * exp(-r * time) * norm_cdf(-d2) - S * norm_cdf(-d1);
}

double black_scholes_call_delta(double S, double K, double r, double sigma, double time)
{
    double d1 = (log(S / K) + (r + sigma * sigma / 2.0) * time) / (sigma * sqrt(time));
    return norm_cdf(d1);
}

double black_scholes_put_delta(double S, double K, double r, double sigma, double time)
{
    double d1 = (log(S / K) + (r + sigma * sigma / 2.0) * time) / (sigma * sqrt(time));
    return norm_cdf(d1) - 1.0;
}

int main(void)
{
    double S = 100.0;
    double K = 100.0;
    double r = 0.05;
    double sigma = 0.2;
    double time = 1.0;

    cout << "Call price: " << black_scholes_call(S, K, r, sigma, time) << endl;
    cout << "Put price: " << black_scholes_put(S, K, r, sigma, time) << endl;
    cout << "Call delta: " << black_scholes_call_delta(S, K, r, sigma, time) << endl;
    cout << "Put delta: " << black_scholes_put_delta(S, K, r, sigma, time) << endl;

    return 0;
}