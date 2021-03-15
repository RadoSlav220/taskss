#pragma once
#include "student.h"

class StudentList {

private:
    size_t size;
    size_t capacity;
    Student* students;

public:
    StudentList(size_t capacity){
        if (capacity>200){
            std::cout << "The entered capacity is too big\nThe current capacity is set to 200" << std::endl;
            this->capacity = 200;
        }
        else {
            this->capacity = capacity;
        }
        students = new Student[this->capacity];
        if (!students){
            std::cerr << "Not enough memory!" << std::endl;
        }
        size = 0;
    }
    ~StudentList(){
        delete [] students;
    }

public:
    void add(const Student& student); //student is the new member
    size_t getSize();
    void remove(unsigned facultyNumber);
    bool contains(unsigned facultyNumber);
    bool contains(const Student& student);
    void sortByFn();
    void print();

};
