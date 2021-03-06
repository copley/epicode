// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <iostream>
#include <random>
#include <string>

#include "test_toolkit/main_def.h"

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
// @pg_ignore
string RandString(int len) {
  default_random_engine gen((random_device())());
  string result;
  uniform_int_distribution<int> dis('A', 'Z');
  while (len--) {
    result.push_back(dis(gen));
  }
  return result;
}
// @pg_end

// @include
// @pg_skeleton
int SSDecodeColID(const string& col) {
  // @pg_impl
  int result = 0;
  for (char c : col) {
    result = result * 26 + c - 'A' + 1;
  }
  return result;
  // @pg_end
}
// @pg_end
// @exclude
// @pg_ignore
void SimpleTest() {
  assert(1 == SSDecodeColID("A"));
  assert(2 == SSDecodeColID("B"));
  assert(26 == SSDecodeColID("Z"));
  assert(27 == SSDecodeColID("AA"));
}

int MAIN_FUNC(int argc, char* argv[]) {
  SimpleTest();
  default_random_engine gen((random_device())());
  if (argc == 2) {
    cout << argv[1] << " " << SSDecodeColID(argv[1]) << endl;
  } else {
    uniform_int_distribution<int> len_dis(1, 5);
    string s(RandString(len_dis(gen)));
    cout << s << " " << SSDecodeColID(s) << endl;
  }
  return 0;
}
// @pg_end
