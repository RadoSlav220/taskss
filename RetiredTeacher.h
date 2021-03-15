#pragma once
#include "course.h"

class RetiredTeacher {

private:
    char name[51];
    int exp; // years experience
    Course* courses;
    int capacity;
    int currSize;

public:
    RetiredTeacher (const char* name, const int exp);

public:
    void addNewCourse (const Course newCourse);
    bool hasTeachedByName (const char* courseName);
    bool hasTeachedByCourse (const Course course);
    void printInfo();
};
