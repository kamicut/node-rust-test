#include <node.h>
#include <v8.h>

using namespace v8;

typedef struct {
  void *data;
  int len;
} array_t;

extern "C" array_t julia (int input);

void JuliaSet(const v8::FunctionCallbackInfo<v8::Value> & args) {
  Isolate* isolate = args.GetIsolate();
  Local<Number> input = Local<Number>::Cast(args[0]);

  array_t pixels = julia(input->Value());
  int * pixelData = ((int *) pixels.data);
  Local<Array> tileData = Array::New(isolate);
  for (int i = 0; i < pixels.len; i ++) {
    tileData->Set(i, Number::New(isolate, pixelData[i]));
  } 
  args.GetReturnValue().Set(tileData);
}

void init (Handle <Object> exports, Handle <Object> module) {
  NODE_SET_METHOD(exports, "julia", JuliaSet);
}

NODE_MODULE(fractal, init)