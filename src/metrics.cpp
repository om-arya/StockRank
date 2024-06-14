#include "../node_modules/node-addon-api/napi.h"

#include <iostream>
#include <array>
#include <string>

using namespace std;

/**
 * Receive JavaScript parameters and perform computations.
 * @param double[] containing the daily prices
 * @return double[] containing the results of the computations
 */
Napi::Value ComputeMetrics(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    Napi::Array dailyPrices = info[0].As<Napi::Array>();
    uint32_t length = dailyPrices.Length();

    std::vector<double> result;
    result.reserve(length);

    for (uint32_t i = 0; i < length; i++) {
        Napi::Value element = dailyPrices[i];
        double value = element.As<Napi::Number>().DoubleValue();
        result.push_back(value + 5);
    }

    // Perform computations

    Napi::Array resultArray = Napi::Array::New(env, length);
    for (uint32_t i = 0; i < length; i++) {
        resultArray[i] = Napi::Number::New(env, result[i]);
    }

    return resultArray; // the result goes back to JavaScript
}

Napi::Object Init(Napi::Env env, Napi::Object exports) { // initialize the module
    exports.Set(Napi::String::New(env, "computeMetrics"), Napi::Function::New(env, ComputeMetrics));
    return exports;
}

NODE_API_MODULE(addon, Init)

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