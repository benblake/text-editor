#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>

using namespace std;


class File {
private:
    vector<string> fileLines;
    string filename;
    bool editedSinceSave;
public:
    /* Constructors and destructor */
    File(void);
    File(string fname);
    ~File(void);

    /* File operations */
    void setFileName(string fname);
    int openFile(void);
    int saveFile(void);
    bool edited(void);

    /* Text and/or line operations */
    int insertCharacter(size_t line, size_t column, char ch);
    int deleteCharacter(size_t line, size_t column);
    int insertString(size_t line, size_t column, string str);
    int deleteString(size_t line, size_t column, size_t length);
    int insertNewLine(size_t line, size_t column);

    /* Testing methods */
    void print(void);
};

#endif /* FILE_H */