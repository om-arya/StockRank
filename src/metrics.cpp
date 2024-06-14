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

    if (!info[0].IsArray() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Expected first argument to be an array and second argument to be a number").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::Array inputArray = info[0].As<Napi::Array>();
    double number = info[1].As<Napi::Number>().DoubleValue();
    uint32_t length = inputArray.Length();

    std::vector<double> result;
    result.reserve(length);

    for (uint32_t i = 0; i < length; i++) {
        Napi::Value element = inputArray[i];
        if (!element.IsNumber()) {
            Napi::TypeError::New(env, "Array elements must be numbers").ThrowAsJavaScriptException();
            return env.Null();
        }
        double value = element.As<Napi::Number>().DoubleValue();
        result.push_back(value + number); // perform the computation
    }

    Napi::Array resultArray = Napi::Array::New(env, length);
    for (uint32_t i = 0; i < length; i++) {
        resultArray[i] = Napi::Number::New(env, result[i]);
    }

    return resultArray; // the result goes back to JavaScript
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