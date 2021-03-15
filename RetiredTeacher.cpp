#include "RetiredTeacher.h"

//Constructors
RetiredTeacher::RetiredTeacher (const char* name, const int exp)
{
    if (strlen(name) > 50){
        std::cerr << "Teacher's name is too long!" << std::endl;
        strcpy(this->name, "Invalid name");
    }
    else {
        strcpy(this->name, name);
    }

    if (exp < 0){
        std::cerr << "A teacher cannot have negative years of experience" << std::endl;
        this->exp = 0;
    }
    else {
        this->exp = exp;
    }

    capacity = 1;
    currSize = 0;
    courses = new (std::nothrow) Course [capacity];
    if (!courses){
        std::cerr << "Memory error" << std::endl;
    }
}

//Main Methods
void RetiredTeacher::addNewCourse (const Course newCourse)
{
    currSize++;
    if (currSize > capacity){
        int newCapacity = capacity*2;
        Course* newArr = new (std::nothrow) Course [newCapacity];

        if (!newArr){
            std::cerr << "Not enough memory! New courses cannot be added!" << std::endl;
            return;
        }
        capacity = newCapacity;
        for (int i=0; i<currSize-1; i++){
            newArr[i] = courses[i];
        }
        delete [] courses;
        courses = newArr;
    }

    courses[currSize-1] = newCourse;
    std::cout << "Course added successfully" << std::endl;
}


bool RetiredTeacher::hasTeachedByName (const char* courseName)
{
    for (int i=0; i<currSize; i++){
        if (strcmp(courses[i].getName(), courseName) == 0){
            return true;
        }
    }
    return false;
}

bool RetiredTeacher::hasTeachedByCourse (const Course course)
{
    for (int i=0; i<currSize; i++){
        if (strcmp(courses[i].getName(), course.getName()) == 0 &&
            course.getCapacity() == courses[i].getCapacity()){
            return true;
        }
    }
    return false;
}

void RetiredTeacher::printInfo()
{
    std::cout << "Teacher name: " << name << std::endl;
    std::cout << "Years of experience: " << exp << std::endl;
    std::cout << "Courses: " << std::endl;
    for (int i=0; i<currSize; i++){
        std::cout << i+1 << ") " << courses[i].getName() << std::endl;
    }
}
