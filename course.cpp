#include "course.h"

//Constructors
Course::Course(const char* _name, const int cap)
{
    strcpy(name, _name);
    if (cap >= 0){
        capacity = cap;
    }
    else {
        std::cerr << "Invalid capacity! Default capacity set to 0" << std::endl;
        capacity = 0;
    }
    students = new Student [capacity];
    if (!students){
        std::cerr << "Not enough memory" << std::endl;
    }
    currSize = 0;
}

Course::Course ()
{
    strcpy(name, "No name");
    capacity = 10;
    students = new Student [capacity];
    if (!students){
        std::cerr << "Not enough memory" << std::endl;
    }
    currSize = 0;
}

//Getters
const char* Course::getName() const {return name;}
const int Course::getCapacity() const {return capacity;}
const int Course::getCurrSize() const {return currSize;}

//Main methods
void Course::enrolStudent(const Student student)
{
    if (currSize+1 > capacity){
        std::cerr << "ERROR: The course limit is reached. New student(s) were not successfully added!" << std::endl;
        return;
    }
    students[currSize] = student;
    currSize++;
}

void Course::enrolStudents(const Student* students, const int count)
{
    for (int i=0; i<count; i++){
        enrolStudent(students[i]);
    }
}

void Course::printInformation()
{
    std::cout << "Course name: " << name << std::endl;
    std::cout << "Max capacity: " << capacity << std::endl;
    for (int i=0; i<currSize; i++){
        std::cout << i+1 << ") " << students[i].getName() << " " << students[i].getFacultyNumber() << std::endl;
    }
    std::cout << "Total participants: " << currSize << std::endl;
}
