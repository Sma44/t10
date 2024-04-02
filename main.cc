#include <iostream>
using namespace std;

#include "Student.h"

#include "List.h"


int main()
{
  Student *matilda = new Student("100567899", "Matilda", "CS", 9.0f);
  Student *harold  = new Student("100777888", "Harold", "Geography", 7.5f);
  Student *joe     = new Student("100777888", "Joe", "Physics", 8.3f);
  Student *timmy   = new Student("100333444", "Timmy", "CS", 11.5f);
  Student *amy     = new Student("100123444", "Amy", "Math", 10.8f);

  List<Student> comp2404;

  comp2404.add(matilda);
  comp2404.add(harold);
  comp2404.add(joe);
  comp2404.add(timmy);
  comp2404.add(amy);

  cout << endl << "STUDENTS:" << endl;
  comp2404.print();
  cout << endl;

  Student* someStu;
  string   stuName;

  cout << "Student to be deleted: ";
  cin  >> stuName;

  while (stuName != "-1") {
    comp2404.del(stuName, &someStu);
    if (someStu == nullptr) {
      cout << "--Could not delete " << stuName << endl;
    }
    else {
      cout << "--Deleted: ";
      someStu->print();
      cout << endl;
      delete someStu;
    }

    cout << endl << "STUDENTS:" << endl;
    comp2404.print();
    cout << endl;

    cout << "Student to be deleted: ";
    cin  >> stuName;
  }

  return 0;
}

