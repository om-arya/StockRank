#include "../node_modules/node-addon-api/napi.h"

#include <iostream>
#include <array>
#include <string>

using namespace std;

/**
 * Take two numbers from JavaScript and return their sum.
 */
Napi::Value Add(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Expected two arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Expected arguments to be numbers").ThrowAsJavaScriptException();
        return env.Null();
    }

    // Parse the arguments from the JavaScript
    double arg0 = info[0].As<Napi::Number>().DoubleValue();
    double arg1 = info[1].As<Napi::Number>().DoubleValue();

    double sum = arg0 - arg1; // perform the computation

    return Napi::Number::New(env, sum); // the result goes back to JavaScript
}

Napi::Object Init(Napi::Env env, Napi::Object exports) { // initialize the module
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
    return exports;
}

NODE_API_MODULE(addon, Init)

/* double totalReturn(double dailyPrices[], int size) {
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
} */

/**
 * To build using 'binding.gyp', run:
 * npx node-gyp configure
 * npx node-gyp build
 * 
 * Create a JavaScript file 'foo.js':
 * const addon = require('./build/Release/addon');
 * const result = addon.add(5, 3);
 * console.log(`The result of the addition is: ${result}`);
 * 
 * Run the JS file:
 * node foo.js
 */