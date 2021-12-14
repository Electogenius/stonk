#include <map>
using namespace std;
void $pop() {
  stak.pop_back();
}
void $dup() {
  stak.push_back(stak.back());
}
void $square() {
  auto h = strToInt(pop());
  stak.push_back(to_string(h * h));
}
void $if() {
  string Else = pop(), If = pop(), cond = stak.back();
  if (cond != "" && cond != "0") {
    run(If);
  } else {
    run(Else);
  }
}
void $swap() {
  string a = pop(), b = pop();
  stak.push_back(a);
  stak.push_back(b);
}
void $repeat() {
  auto num = strToInt(pop());
  string str(pop());
  string res = "";
  for (size_t index = 0; index < num; index++) {
    res += str;
  }
  stak.push_back(res);
}
void $times() {
  auto times = strToInt(pop());
  string code = pop();
  for (size_t i = 0; i < times; i++) {
    run(code);
  }
}
void $stob() {
  string arr = pop();
  Buffer buf;
  auto ns = split(arr, ',');
  for (size_t i = 0; i < ns.size(); i++) {
    buf.push_back((char)strToInt(ns[i]));
  }
  stak.push_back(bufToStr(buf));
}
void $btos() {
  string h = "";
  Buffer buf = strToBuf(pop());
  for (size_t i = 0; i < buf.size(); i++) {
    h += to_string((unsigned char)buf.at(i)) + ",";
  }
  stak.push_back(h.substr(0, h.length() - 1));
}
void $mod() {
  auto a = (strToInt(pop())), b = (strToInt(pop()));
  stak.push_back(to_string(b % a));
}
void $nth() {
  auto i = strToInt(pop());
  stak.push_back((string) "" + pop()[i]);
}
void $del() {
  vars.erase(pop());
}
void $strlength() {
  stak.push_back(to_string(pop().length()));
}
void $addb(){
  string a=pop(), b=pop();
  for (size_t i = a.length(); i--;){
    if(((int)(unsigned char)a[i]+(int)(unsigned char)b[i])>255)a[i-1]++;
    a[i]=a[i]+b[i];
  }
  stak.push_back(a);
}
void $subb(){
  string a=pop(), b=pop(), res="";
  for (size_t i = 0; i < a.length(); i++){
    res+=a[i]-b[i];
  }
  stak.push_back(res);
}
void $stack(){
  string res="";
  for (size_t i = 0; i < stak.size(); i++){
    res+="["+stak[i]+"] ";
  }
  cout<<res<<endl;
}
void $stacknth(){
  auto i = strToInt(pop());
  stak.push_back(stak[i]);
}
void $gets(){
  string h;
  cin>>h;
  stak.push_back(h);
}
void $prints(){
  cout<<stak.back();
}
void $run(){
  run(pop());
}
void $stacklen(){
  stak.push_back(to_string(stak.size()));
}
// part of the standard library can be written in just stonk so...
void blockparse(string code);
void stonklib() {
  blockparse(R"std(
The Stonkception standard library

evaluate code:
@run
 '1 swap 'pop . swap +s '_ if
;

increment var:
@++
 ->++.name ( store )
 getvar (get value )
 '1 +n ( increment )
 '-> $++.name +s run ( store )
 '++.name del ( clean )
; this is version 2

decrement var:
@--
 ->++.name ( store )
 getvar (get value )
 '1 -n ( decrement )
 '-> $++.name +s run ( store )
 '++.name del ( clean )
;

get var value with name:
@getvar
 '$ swap +s run
;

multiply buffers:
@*b
 ->*b.b
 pop ->*b.a pop
 {$*b.b $*b.a +b ->*b.b pop} $*b.b times
 $*b.b $*b.a -b
;

print but also pop
@@
 puts pop
;

remove second last item
@nip
 swap pop
;

duplicate the top below second top
@tuck
 ->tuck.top swap $tuck.top
 'tuck.top del
;
)std");
}
void stds() {
  stdf["pop"] = $pop;
  stdf["square"] = $square;
  stdf["dup"] = $dup;
  stdf["if"] = $if;
  stdf["swap"] = $swap;
  stdf["*sn"] = $repeat;
  stdf["times"] = $times;
  stdf["s->b"] = $stob;
  stdf["b->s"] = $btos;
  stdf["%n"] = $mod;
  stdf["nth"]=$nth;
  stdf["del"] = $del;
  stdf["[]"] = $nth;
  stdf["lengths"] = $strlength;
  stdf["+b"]=$addb;
  stdf["-b"]=$subb;
  stdf["put:"]=$stack;
  stdf["nth:"]=$stacknth;
  stdf["gets"]=$gets;
  stdf["prints"]=$prints;
  stdf["length:"]=$stacklen;
  stonklib();
}