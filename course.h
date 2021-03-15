#pragma once
#include "studentlist.h"

class Course {

private:
    char name[51];
    int capacity;
    Student* students;
    int currSize;

public:
    Course();
    Course(const char*, const int);

public:
    const char* getName() const;
    const int getCapacity() const;
    const int getCurrSize() const;

public:
    void enrolStudent(const Student);
    void enrolStudents(const Student*, const int);
    void printInformation();
};
