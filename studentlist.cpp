#include "studentlist.h"

void StudentList::add(const Student& student)
{
    if (size+1 > 200){
        std::cout << "New students cannot be added\n" << std::endl;
        return;
    }

    if (contains(student.getFacultyNumber())){
        std::cout << "This student is already registered" << std::endl;
        return;
    }

    size++;
    if (size > capacity){
        size_t newCapacity = capacity*2;
        Student* newArr = new (std::nothrow) Student [newCapacity];

        //if there is not enough memory for 2x capacity
        //we could try capacity+1
        if (!newArr){
            std::cerr << "Not enough memory! New student cannot be added!" << std::endl;
            return;
        }
        capacity = newCapacity;
        for (size_t i=0; i<size-1; i++){
            newArr[i] = students[i];
        }
        delete [] students;
        students = newArr;
    }

    students[size-1] = student;
    std::cout << "Student added successfully" << std::endl;
}

bool StudentList::contains(const Student& student)
{
    for (size_t i=0; i<size; i++){
        if (student.getFacultyNumber() == students[i].getFacultyNumber() &&
            strcmp(student.getName(), students[i].getName()) == 0 &&
            strcmp(student.getMajor(), students[i].getMajor()) ==0 &&
            student.getGroup() == students[i].getGroup())
            {return true;}
    }
    return false;
}

bool StudentList::contains(unsigned fn)
{
    for (size_t i=0; i<size; i++){
        if (students[i].getFacultyNumber() == fn){
            return true;
        }
    }
    return false;
}

//fn == faculty number
void StudentList::remove(unsigned fn)
{
    size_t i=0;
    for (; i<size; i++){
         if (students[i].getFacultyNumber() == fn){
              for (size_t j=i; j<size-1; j++){
                   students[j] = students[j+1];
              }
              break;
         }
    }
    if (i == size){
        std::cout << "No such student" << std::endl;
    }
    else {
        size--;
        std::cout << "Student removed successfully" << std::endl;
    }
}

void StudentList::sortByFn()
{
    if (size == 0){
        return;
    }
    for (size_t i=0; i<size-1; i++){
        size_t min = i;
        for (size_t j=i+1; j<size; j++){
            if (students[j].getFacultyNumber() < students[min].getFacultyNumber()){
                min = j;
            }
        }
        Student swapper = students[i];
        students[i] = students[min];
        students[min] = swapper;
    }
}

void StudentList::print()
{
    if (size == 0){
        std::cout << "No students to be shown" << std::endl;
        return;
    }

    std::cout << std::endl;
    for (size_t i=0; i<size; i++){
        std::cout << students[i].getFacultyNumber() << " ";
        std::cout << students[i].getName() << " - ";
        std::cout << students[i].getMajor() << " - ";
        std::cout << "Group " << students[i].getGroup();
        std::cout << std::endl;
    }

}

size_t StudentList::getSize()
{
    return size;
}
