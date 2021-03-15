//Does not include the functionality of "RetiredTeacher"

#include <iostream>
#include "course.h" //includes all other headers
#include <limits>
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

void printWhat ()
{
    cout << endl;
    cout << "\t\t\tWhat do you want to do?" << endl;
    cout << "\t\tPress 1 to add a new student."<< endl;
    cout << "\t\tPress 2 to check student by FN."<< endl;
    cout << "\t\tPress 3 to remove a student by FN."<< endl;
    cout << "\t\tPress 4 to see how many students are there."<< endl;
    cout << "\t\tPress 5 to sort the students."<< endl;
    cout << "\t\tPress 6 to view all students."<< endl;
    cout << "\t\tPress 7 to add a student to the course."<< endl;
    cout << "\t\tPress 8 to add new students to the course."<< endl;
    cout << "\t\tPress 9 to view info about the course." << endl;
    cout << "\t\tPress 0 to finish."<< endl;
}

int main ()
{
    cout << "*******Welcome to our student system*******" << endl << endl;
    cout << "Enter the starting capacity of the register: ";
    size_t capacity;
    cin >> capacity;
    StudentList studentList(capacity);
    cout << endl;


    char name[51];
    cin.ignore();
    do
    {
        cout << "Enter the name of the course: ";
        cin.getline(name, 51, '\n');
        if(cin.good()) break;
        cout << "Error: Name too long!" << endl;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(true);

    int cap;
    cout << "Enter the course capacity: ";
    cin >> cap;
    Course course1(name, cap);

    while (true){
        system("cls");
        printWhat();
        int n;
        cin >> n;
        cout << endl;
        if (n == 1){
            Student student1;
            student1.readFromConsole();
            studentList.add(student1);
        }

        else if (n == 2){
            unsigned fn;
            cout << "Enter a faculty number: ";
            cin >> fn;
            if (studentList.contains(fn)){
                cout << "Student found" << endl;
            }
            else {
                cout << "Student not found" << endl;
            }
        }

        else if (n == 3){
            unsigned fn;
            cout << "Enter a faculty number: ";
            cin >> fn;
            studentList.remove(fn);
        }

        else if (n == 4){
            cout << "There are " << studentList.getSize() << " student(s)   " << endl;
        }

        else if (n == 5){
            studentList.sortByFn();
            cout << "The list has been sorted" << endl;
        }

        else if (n == 6){
            studentList.print();
        }

        else if (n == 7){
            Student student1;
            student1.readFromConsole();
            course1.enrolStudent(student1);
        }

        else if (n == 8){
            int howMany;
            bool whether = true;
            cout << "Count of students you would like to enroll: ";
            cin >> howMany;

            if (course1.getCurrSize()+howMany > course1.getCapacity()){
                cout << "You will not be able to enroll " << howMany << " students. Would you like to continue anyway?" << endl;
                cout << "0) No" << endl;
                cout << "1) Yes" << endl;
                cin >> whether;
            }

            if (whether){
                Student* students = new Student [howMany];
                if (!students){
                    cerr << "Not enough memory" << endl;
                }

                else {
                    for (int i=0; i<howMany; i++){
                        cout << "Enter the " << i+1 << ". student data:" << endl;
                        students[i].readFromConsole();
                    }
                    course1.enrolStudents(students, howMany);
                }
            }
        }

        else if (n == 9){
            course1.printInformation();
        }

        else if (n == 0){
            cout << "Thank you for using our student system :)" << endl;
            break;
        }

        else {
            cout << "Invalid Operation! Try again!" << endl;
        }
        system("pause");
    }

    return 0;
}
