#include "student.h"
#include <limits>
//using std::cin;

bool Student::isCorrectFn(const unsigned fn) const
{
    if (fn>=10000 && fn<=99999){
        return true;
    }
    return false;
}

bool Student::isCorrectName(const char* name) const
{
    if (strlen(name)<=50){
        return true;
    }
    return false;
}

bool Student::isCorrectMajor(const char* major) const
{
     if (strcmp(major, "Informatics") == 0 ||
         strcmp(major, "Computer Science") == 0 ||
         strcmp(major, "Software Engineering") == 0 ||
         strcmp(major, "Mathematics and Informatics") == 0 ||
         strcmp(major, "Mathematics") == 0){
            return true;
         }
    return false;
}

bool Student::isCorrectGroup(const short group) const
{
    if (group>=1 && group<=8){
        return true;
    }
    return false;
}


unsigned Student::getFacultyNumber() const
{
    return facultyNumber;
}

const char* Student::getName() const
{
    return name;
}

const char* Student::getMajor() const
{
    return major;
}

short Student::getGroup() const
{
    return group;

}

Student& Student::operator=(const Student& other)
{
    if (this != &other) {
        this->facultyNumber = other.getFacultyNumber();
        strcpy(this->name, other.getName());
        strcpy(this->major, other.getMajor());
        this->group = other.getGroup();
    }
    return *this;
}


void Student::setMajor(const char * newMajor)
{
    if (isCorrectMajor(newMajor)){
        strcpy(major, newMajor);
        std::cout << "Major Changed Successfully" << std::endl;
    }
    else {
        std::cerr << "Invalid New Major" << std::endl;
    }
}

void Student::setGroup(const short newGroup)
{
    if (isCorrectGroup(newGroup)){
        group = newGroup;
        std::cout << "Group Changed Successfully" << std::endl;
    }
    else {
        std::cerr << "Invalid New Group" << std::endl;
    }
}

void Student::printInformation() const
{
    std::cout << "Your Faculty Number: " << facultyNumber << std::endl;
    std::cout << "Your Name: " << name << std::endl;
    std::cout << "Your Major: " << major << std::endl;
    std::cout << "Your Group: " << group << std::endl;
}

void Student::readFromConsole()
{
    std::cout << "Enter FN: ";
    std::cin >> facultyNumber;
    if (!std::cin){
        std::cin.clear();
        facultyNumber = 0;
        std::cin.ignore();
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter name: ";
    std::cin.getline(name, 51);
    std::cout << "Enter major: ";
    std::cin.getline(major, 31);
    std::cout << "Enter group: ";
    std::cin >> group;
    if (!std::cin){
        std::cin.clear();
        std::cin.ignore();
        group = 0;
    }
    if (!isCorrectFn(facultyNumber)){
        std::cerr << "Invalid Faculty Number" << std::endl;
        facultyNumber = 0;
    }
    if (!isCorrectName(name)){
        std::cerr << "Invalid Name" << std::endl;
        strcpy(name, "Name not added");
    }
    if (!isCorrectMajor(major)){
        std::cerr << "Invalid Major" << std::endl;
        strcpy(major, "Major Not Chosen");
    }
    if (!isCorrectGroup(group)){
        std::cerr << "Invalid Group" << std::endl;
        group = 0;
    }
}
