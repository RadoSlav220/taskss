#pragma once
#include <cstring>
#include <iostream>

class Student {
private:
    unsigned facultyNumber;
    char name[51];
    char major[33];
    short group;

private:
    bool isCorrectFn(const unsigned) const;
    bool isCorrectName(const char*) const;
    bool isCorrectMajor(const char*) const;
    bool isCorrectGroup(const short) const;

public:
    Student(){
        facultyNumber = 12345;
        strcpy(name, "Student Name");
        strcpy(major, "major");
        group = 0;
    }
    Student(unsigned _facultyNumber, const char * _name, const char * _major, short _group){
        if (isCorrectFn(_facultyNumber)){
            facultyNumber = _facultyNumber;
        }
        else {
            facultyNumber = 0;
        }
        if (isCorrectName(_name)){
            strcpy(name, _name);
        }
        else {
            strcpy(name, "Name not added");
        }
        if (isCorrectMajor(_major)){
            strcpy(major, _major);
        }
        else {
            strcpy(major, "Major not chosen");
        }
        if (isCorrectGroup(_group)){
            group = _group;
        }
        else {
            group = 0;
        }
    }

public:
    Student& operator=(const Student& student1);

public:
    unsigned getFacultyNumber() const;
    const char* getName() const;
    const char* getMajor() const;
    short getGroup() const;

public:
    void setMajor(const char * newMajor);
    void setGroup(const short newGroup);

public:
    void printInformation() const;
    void readFromConsole();
};
