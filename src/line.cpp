#include <iostream>
#include <string>

#include "../line.h"

using namespace std;

Line::Line(string inputText) {
  text = inputText;
}

Line::~Line(void) { }

size_t Line::length(void) {
  return text.length();
}

int Line::insertChar(size_t index, char ch) {
  string chToInsert(1, ch);
  text.insert(index, chToInsert);

  return 1; // return success/failure
}

int deleteChar(size_t index) {
  text.erase(index, 1);

  return 1; // return success/failure
}
