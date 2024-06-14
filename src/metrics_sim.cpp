#include <iostream>
#include <array>
#include <string>

using namespace std;

double totalReturn(double dailyPrices[], int size) {
    double startPrice = dailyPrices[0];
    double endPrice = dailyPrices[size - 1];

    return endPrice - startPrice;
}

double returnOnInvestment(double dailyPrices[], int size) {
    double startPrice = dailyPrices[0];
    double endPrice = dailyPrices[size - 1];

    return ((endPrice - startPrice) / startPrice) * 100;
}

double compoundAnnualGrowthRate(double dailyPrices[], int size) {
    double startPrice = dailyPrices[0];
    double endPrice = dailyPrices[size - 1];
    double timeInYears = double(size) / 365;

    return pow(endPrice / startPrice, 1 / timeInYears) - 1;
}

int main() {
    double dailyPrices[6] = {174.52, 176.61, 177.43, 178.45, 176.63};
    int size = sizeof(dailyPrices) / sizeof(dailyPrices[0]);

    double total = totalReturn(dailyPrices, size);
    cout << "Total Return: " << total << "\n";

    double roi = returnOnInvestment(dailyPrices, size);
    cout << "Return On Investment (ROI): " << roi << "%\n";

    double cagr = compoundAnnualGrowthRate(dailyPrices, size);
    cout << "Compound Annual Growth Rate (CAGR): " << cagr << "%\n";

    return 0;
}