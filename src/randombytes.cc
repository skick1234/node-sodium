/**
 * Node Native Module for Lib Sodium
 *
 * @Author Pedro Paixao
 * @email paixaop at gmail dot com
 * @License MIT
 */
#include "node_sodium.h"

// Generating Random Data
// Docs: https://download.libsodium.org/doc/generating_random_data/index.html

// Lib Sodium Random

// void randombytes_buf(void *const buf, const size_t size)
Napi::Value bind_randombytes_buf(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    ARGS(1,"argument must be a buffer");

    ARG_TO_UCHAR_BUFFER(buffer);
    randombytes_buf(buffer, buffer_size);

    return env.Null();
}

// void randombytes_stir()
Napi::Value bind_randombytes_stir(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    randombytes_stir();

    return env.Null();
}

Napi::Value bind_randombytes_close(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // int randombytes_close()
    return 
        Napi::Number::New(env, randombytes_close());
}

Napi::Value bind_randombytes_random(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    // uint_32 randombytes_random()
    return 
        Napi::Value::From(env, randombytes_random());
}

Napi::Value bind_randombytes_uniform(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    ARGS(1,"argument size must be a positive number");
    ARG_TO_NUMBER(upper_bound);

    // uint32_t randombytes_uniform(const uint32_t upper_bound)
    return 
        Napi::Value::From(env, randombytes_uniform(upper_bound));
}

/**
 * Register function calls in node binding
 */
void register_randombytes(Napi::Env env, Napi::Object exports) {
   
    NEW_METHOD(randombytes_buf);
    exports.Set(Napi::String::New(env, "randombytes"), Napi::Function::New(env, bind_randombytes_buf));
    NEW_METHOD(randombytes_close);
    NEW_METHOD(randombytes_stir);
    NEW_METHOD(randombytes_random);
    NEW_METHOD(randombytes_uniform);
    NEW_METHOD(randombytes_buf_deterministic);

    NEW_INT_PROP(randombytes_SEEDBYTES);
}