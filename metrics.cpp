#include <iostream>
#include <array>
#include <string>
using namespace std;

double totalReturn(double dailyPrices[], int size) {
    return dailyPrices[size - 1] - dailyPrices[0];
}

double returnOnInvestment(double dailyPrices[], int size) {
    return ((dailyPrices[size - 1] - dailyPrices[0]) / dailyPrices[0]) * 100;
}

double compoundAnnualGrowthRate(double dailyPrices[], int size) {
    return pow((dailyPrices[size - 1] / dailyPrices[0]), 1.0 / double(size)) - 1;
}

int main() {
    double dailyPrices[5] = {174.52, 176.61, 177.43, 178.45, 176.63};
    int size = sizeof(dailyPrices) / sizeof(dailyPrices[0]);

    double total = totalReturn(dailyPrices, size);
    cout << "Total Return: " << total << "\n";

    double roi = returnOnInvestment(dailyPrices, size);
    cout << "Return On Investment (ROI): " << roi << "%\n";

    double cagr = compoundAnnualGrowthRate(dailyPrices, size);
    cout << "Compound Annual Growth Rate (CAGR): " << cagr << "%\n";

    return 0;
}