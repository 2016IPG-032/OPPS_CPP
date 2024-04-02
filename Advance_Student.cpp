/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll_Number;
    string blood_group;
    string dob;
    string standard;
    string division;

    long long int tel;
    static int counter;

    Student()
    {
        roll_Number = 0;
        counter++;
    }

    Student(int rollNumber)
    {
        this->roll_Number = rollNumber;
        counter++;
    }

    Student(Student &obj)
    {
        name = obj.name;
        roll_Number = obj.roll_Number;
        blood_group = obj.blood_group;
        dob = obj.dob;
        standard = obj.standard;
        division = obj.division;
        tel = obj.tel;
        counter++;
    }
    ~Student()
    {
        cout << "Deleting object" << endl;
        counter--;
    }

    static void display_counter()
    {
        cout << "The no of objects created are- " << counter << endl;
    }
    void addData();

    friend void display(Student &obj);
};
int Student::counter = 0;

void Student::addData()
{
    cout << "Enter name-\n";
    cin >> name;
    cout << "Enter roll number-\n";
    cin >> roll_Number;
    cout << "Enter blood group-\n";
    cin >> blood_group;
    cout << "Enter date of birth-\n";
    cin >> dob;
    cout << "Enter standard-\n";
    cin >> standard;
    cout << "Enter division-\n";
    cin >> division;
    cout << "Enter mobile number-\n";
    cin >> tel;
}

void display(Student &obj)
{
    cout << "Name is- " << obj.name << endl;
    cout << "Roll number is- " << obj.roll_Number << endl;
    cout << "Blood group is- " << obj.blood_group << endl;
    cout << "Date of birth is- " << obj.dob << endl;
    cout << "Standard is- " << obj.standard << endl;
    cout << "Division is- " << obj.division << endl;
    cout << "Mobile number is- " << obj.tel << endl;
}

int main()
{
    Student s1;
    Student s2(1);
    s2.addData();

    Student s3(s2);

    display(s2);
    display(s3);

    Student::display_counter();

    cout << "How many students are in your class?\n";
    int number;
    cin >> number;

    Student *s[50];

    for (int i = 0; i < number; i++)
    {
        s[i] = new Student();
    }
    for (int i = 0; i < number; i++)
    {
        s[i]->addData();
    }
    for (int i = 0; i < number; i++)
    {
        display(*s[i]);
    }
    Student ::display_counter();
    for (int i = 0; i < number; i++)
    {
        delete (s[i]);
    }
    Student ::display_counter();

    return 0;
}
