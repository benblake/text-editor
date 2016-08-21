#ifndef LINE_H
#define LINE_H

#include <string>

class Line {
private:
  string text;
public:
  Line(string inputText);
  ~Line(void);
  size_t length(void);
  int insertChar(size_t index, char ch);
  int deleteChar(size_t index);
};

#endif /* LINE_H */
