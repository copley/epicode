// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <sstream>
#include <stack>
#include <string>

#include "test_toolkit/main_def.h"

using std::stack;
using std::string;
using std::stringstream;

// @include
// @pg_skeleton
int Eval(const string& RPN_expression) {
  // @pg_impl
  stack<int> intermediate_results;
  stringstream ss(RPN_expression);
  string token;
  const char kDelimiter = ',';

  while (getline(ss, token, kDelimiter)) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      const int y = intermediate_results.top();
      intermediate_results.pop();
      const int x = intermediate_results.top();
      intermediate_results.pop();
      switch (token.front()) {
        case '+':
          intermediate_results.emplace(x + y);
          break;
        case '-':
          intermediate_results.emplace(x - y);
          break;
        case '*':
          intermediate_results.emplace(x * y);
          break;
        case '/':
          intermediate_results.emplace(x / y);
          break;
      }
    } else {  // token is a number.
      intermediate_results.emplace(stoi(token));
    }
  }
  return intermediate_results.top();
  // @pg_end
}
// @pg_end
// @exclude
// @pg_ignore
int MAIN_FUNC(int argc, char* argv[]) {
  assert(0 == Eval("2,-10,/"));
  assert(-5 == Eval("-10,2,/"));
  assert(5 == Eval("-10,-2,/"));
  assert(-5 == Eval("5,10,-"));
  assert(6 == Eval("-10,-16,-"));
  assert(12 == Eval("10,2,+"));
  assert(15 == Eval("1,2,+,3,4,*,+"));
  assert(42 == Eval("1,2,3,4,5,+,*,+,+,3,4,*,+"));
  assert(-6 == Eval("1,2,3,4,5,+,*,+,+,3,4,*,+,-7,/"));
  return 0;
}
// @pg_end
