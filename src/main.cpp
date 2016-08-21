#include <iostream>
#include <string>

#include "../include/file.h"

using namespace std;

int main() {
    string filename("main.cpp");
    File f(filename);

    // edits
    f.insertCharacter(3, 20, 'K');
    f.deleteCharacter(3, 22);
    f.insertNewLine(3,22);
    // verification
    f.print();
    f.setFileName(filename + '2');
    f.saveFile();
    return 0;
}