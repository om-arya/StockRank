#include "../node_modules/node-addon-api/napi.h"

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

    double sum = arg0 + arg1; // perform the computation

    return Napi::Number::New(env, sum); // the result goes back to JavaScript
}

Napi::Object Init(Napi::Env env, Napi::Object exports) { // initialize the module
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
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