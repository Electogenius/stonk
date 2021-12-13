#define log(a) cout << a << endl
#define Buffer vector<char>
char** Args;
bool Inlib;
#ifndef __EMSCRIPTEN__
#include <fstream>
#else
#include<emscripten/emscripten.h>
#endif
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
vector<string> stak;

#include "object.cpp"
object blocks = object();
#include "utils.cpp"
map<string, std::function<void()> > stdf;
map<string, string> vars;
#include "runner.cpp"
#include "std.cpp"

void blockparse(string code) {
  string in, cr, blockname;
  for (int i = 0; i < code.length(); i++) {
    char c = code[i];
    if (c == '@' && in == "") {
      in = "name";
    } else if (in == "name") {
      if (c == ' ' || c == '\n') {
        in = "body";
        blockname = cr;
        cr = "";
      } else {
        cr += c;
      }
    } else if (in == "body") {
      if (c == ';' && code[i - 1] != '\\') {
        in = "";
        string e = "";
        if (blocks.get(blockname) != "")
          e = blocks.get(blockname) + " ";
        blocks.set(blockname, e + cr);
        cr = "";
      } else {
        if (c != '\n' || code[i - 1] == '\\')
          cr += c;
      }
    }
  };
}

void nop() {}
#ifndef __EMSCRIPTEN__
int start(int argc, char** argv, bool inlib) {
  Inlib = inlib;
  Args = argv;
  ifstream cde((string)argv[1]);
  string code;
  stringstream buffer;
  buffer << cde.rdbuf();
  code = buffer.str();
  stds();
  blockparse(code);
  run(blocks.get("main"), "main");
  return 0;
}
#endif
int main(int argc, char** args) {
  #ifndef __EMSCRIPTEN__
  start(argc, args, false);
  #endif
}
#ifdef __EMSCRIPTEN__
extern "C" {
EMSCRIPTEN_KEEPALIVE; void runCode(char* args) {
  blockparse(args);
  run(blocks.get("main"),"main");
  stak.clear();
}
}
#endif