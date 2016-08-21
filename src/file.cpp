#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/file.h"

using namespace std;


/*
 * File - standard constructor, initialize class with emptry string filename
 */
File::File(void) {
    filename = "";
    editedSinceSave = false;
}


/*
 * File - constructor with filename provided, open file
 */
File::File(string fname) {
    filename = fname;
    editedSinceSave = false;
    openFile();
}


/*
 * ~File - empty destructor
 */
File::~File(void) { }


/*
 * setFileName - set the filename of the class
 */
void File::setFileName(string fname) {
    filename = fname;
}


/*
 * openFile - read file contents into vector data structure
 */
int File::openFile(void) {
    ifstream file;
    file.open(filename);
    string line;
    while (getline(file, line)) {
        fileLines.push_back(line);
    }
    file.close();

    return 0;
}


/*
 * saveFile - write the line of file to filename file
 */
int File::saveFile(void) {
    ofstream file;
    file.open(filename);

    /* Write all lines with a newline character except the last */
    for (size_t i = 0; i < (fileLines.size()-1); i++) {
        file << fileLines.at(i) << '\n';
    }
    file << fileLines.at(fileLines.size()-1);
    file.close();

    /* Update the edited since saved member */
    editedSinceSave = false;

    return 0;
}


/*
 * edited - returns whether or not the file has been updated since last save
 */
bool File::edited(void) {
    return editedSinceSave;
}


/*
 * insertCharacter - insert a single character into a line
 */
int File::insertCharacter(size_t line, size_t column, char ch) {
    string chToInsert(1, ch);
    fileLines[line].insert(column, chToInsert);

    editedSinceSave = true;
    return 0;
}


/*
 * deleteCharacter - delete single character from line
 */
int File::deleteCharacter(size_t line, size_t column) {
    fileLines[line].erase(fileLines[line].begin() + (long)column);

    editedSinceSave = true;
    return 0;
}


/*
 * insertString - insert a string at certain location on line
 */
int File::insertString(size_t line, size_t column, string str) {
    fileLines[line].insert(column, str);

    editedSinceSave = true;
    return 0;
}


/*
 * deleteString - delete a string from certain location on line
 */
int File::deleteString(size_t line, size_t column, size_t length) {
    fileLines[line].erase(column, length);

    editedSinceSave = true;
    return 0;
}


/*
 * insertNewLine - insert a new line, splitting line at column
 */
int File::insertNewLine(size_t line, size_t column) {
    string newLine = fileLines[line].substr(column);
    fileLines[line].erase(column);
    fileLines.insert(fileLines.begin() + (long)line + 1, newLine);

    editedSinceSave = true;
    return 0;
}


/*
 * print - print file contents to terminal
 */
void File::print(void) {
    /* Write all lines with a newline character to terminal */
    for (size_t i = 0; i < fileLines.size(); i++) {
        cout << fileLines.at(i) << endl;
    }
}