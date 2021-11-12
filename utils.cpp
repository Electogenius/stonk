#include <sstream>
vector<string> split(const string& s, char delim) {  // stak overflow
  vector<string> result;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}
string pop() {
  string h = stak.back();
  stak.pop_back();
  return h;
}
int strToInt(string str) {
  stringstream ss(str);
  int x;
  ss >> x;
  return x;
}
string str(string st) {
  string res;
  for (int i = 0; i < st.length(); i++) {
    if(st[i]!='\\'||st[i+1]=='\\')res+=st[i];
  }
  return res;
}
template <typename t>
vector<t> slice(vector<t> v, int s, int e) {}