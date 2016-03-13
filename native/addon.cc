#include <node.h>
#include <v8.h>

using namespace v8;

void JuliaSet(const v8::FunctionCallbackInfo<v8::Value> & args) {
  Isolate* isolate = args.GetIsolate();

  Local<Array> tileData = Array::New(isolate);
  args.GetReturnValue().Set(tileData);
}

void init (Handle <Object> exports, Handle <Object> module) {
  NODE_SET_METHOD(exports, "julia", JuliaSet);
}

NODE_MODULE(fractal, init)