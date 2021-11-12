#include <map>
using namespace std;
void $pop() {
  stak.pop_back();
}
void $dup() {
  stak.push_back(stak.back());
}
void $square() {
  int h = strToInt(pop());
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
  int num = strToInt(pop());
  string str(pop());
  string res = "";
  for (size_t i = 0; i < str.length(); i++) {
    res += *(new string(num, str[i]));
  }
  stak.push_back(res);
}
void $times(){
  int times = strToInt(pop());
  string code = pop();
  for (size_t i = 0; i < times; i++){
    run(code);
  }
}
//part of the standard library can be written in just stonk so...
void blockparse(string code);
void stonklib(){blockparse(R"std(
The Stonkception standard library

evaluate code:
@run
 '1 swap '_ if
;

increment var:
@++
 ->++.varname               ( store var name)
 '$ swap +s run             ( get var value )
 '1 +n                      ( add 1 )
 '' swap +s                 ( prepend single quote )
 { ->} $++.varname +s +s run( add " ->" and var name and evaluate )
 {pop} '3 times             ( remove residue )
; ouch this was hard to make

decrement var:
@--
 ->++.varname
 '$ swap +s run
 '1 -n
 '' swap +s
 { ->} $++.varname +s +s run
 {pop} '3 times
;


)std");}
void stds() {
  stdf["pop"] = $pop;
  stdf["square"] = $square;
  stdf["dup"] = $dup;
  stdf["if"] = $if;
  stdf["swap"] = $swap;
  stdf["*sn"] = $repeat;
  stdf["times"]=$times;
  stonklib();
}