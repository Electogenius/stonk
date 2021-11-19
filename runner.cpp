void run(string code, string blockname = "") {
  vector<string> tkns = split(code, ' ');
  bool instring = false, incomment = false;
  string cr = "";
  for (unsigned i = 0; i < tkns.size(); i++) {
    string kw = tkns.at(i);
    if (kw[0] == '\n')
      kw = kw.substr(0);
    if (kw == "end") {
      string cd = tkns.at(i + 1);
      for (int h = i + 2; h < tkns.size(); h++) {
        cd += " " + tkns.at(h);
      }
      blocks.set(blockname, cd);
      return;
    }
    if (kw[0] == '{' || kw[kw.length() - 1] == '}') {
      if (kw[0] == '{' && kw[kw.length() - 1] == '}') {
        if (instring) {
          cr += " " + kw;
        } else
          stak.push_back(str(kw.substr(1, kw.length() - 2)));
      } else if (kw[0] == '{') {
        if (instring) {
          cr += " " + kw;
        } else {
          instring = true;
          cr = kw.substr(1);
        }
      } else if (kw[kw.length() - 1] == '}') {
        cr += " " + kw.substr(0, kw.length() - 1);
        stak.push_back(str(cr));
        instring = false;
        cr = "";
      }
    } else if (instring) {
      cr += " " + kw;
    } else if (kw == "stop")
      return;
    else if (incomment) {
      if (kw == ")") {
        incomment = false;
      };
      continue;
    } else if (kw == "(") {
      incomment = true;
    } else if (kw[0] == '\'') {
      stak.push_back(kw.substr(1));
    } else if (kw[0] == '.') {
      string a = (stak.back());
      stak.pop_back();
      stak.push_back(a + " " + kw.substr(1));
    } else if (kw[0] == '-' && kw[1] == '>') {
      vars[kw.substr(2)] = stak.back();
    } else if (kw[0] == '$') {
      stak.push_back(vars[kw.substr(1)]);
    } else if (kw == "+n") {
      auto a = strToInt(stak.back());
      stak.pop_back();
      auto b = strToInt(stak.back());
      stak.pop_back();
      stak.push_back(to_string(a + b));
    } else if (kw == "+s") {
      string a = (stak.back());
      stak.pop_back();
      string b = (stak.back());
      stak.pop_back();
      stak.push_back(b + a);
    } else if (kw == "-n") {
      auto a = strToInt(stak.back());
      stak.pop_back();
      auto b = strToInt(stak.back());
      stak.pop_back();
      stak.push_back(to_string(b - a));
    } else if (kw == "*n") {
      auto a = strToInt(stak.back());
      stak.pop_back();
      auto b = strToInt(stak.back());
      stak.pop_back();
      stak.push_back(to_string(a * b));
    } else if (kw == "/n") {
      auto a = strToInt(stak.back());
      stak.pop_back();
      auto b = strToInt(stak.back());
      stak.pop_back();
      stak.push_back(to_string(b / a));
    } else if (kw == "&n") {
      auto a = strToInt(stak.back());
      stak.pop_back();
      auto b = strToInt(stak.back());
      stak.pop_back();
      stak.push_back(to_string(b && a));
    } else if (kw == "|n") {
      auto a = strToInt(stak.back());
      stak.pop_back();
      auto b = strToInt(stak.back());
      stak.pop_back();
      stak.push_back(to_string(b || a));
    } else if (kw == "=") {
      auto a = strToInt(stak.back());
      stak.pop_back();
      auto b = strToInt(stak.back());
      stak.pop_back();
      stak.push_back((b == a) ? "1" : "0");
    } else if (kw == "puts") {
      log(stak.back());
    } else {
      if (stdf.find(kw) != stdf.end()) {
        stdf[kw]();
      } else {
        run(blocks.get(kw), kw);
      }
    }
  }
}