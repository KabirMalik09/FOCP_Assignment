#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Student {
private:
    string name;
    int rollNumber;
    double CGPA;
    vector<string> courses;

public:
    
    Student() : name(""), rollNumber(0), CGPA(0.0) {}

    
    Student(string n, int r, double cg) : name(n), rollNumber(r), CGPA(cg) {}

   
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        CGPA = s.CGPA;
        courses = s.courses;
    }

    
    ~Student() {
        cout << "Destroying record for student: " << name << endl;
    }

    
    void addCourse(string course) {
        courses.push_back(course);
    }

    
    void updateCGPA(double newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 10.0) {
            CGPA = newCGPA;
        } else {
            cout << "Invalid CGPA. Must be between 0 and 10." << endl;
        }
    }

    
    void displayInfo() const {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber;
        cout << "\nCGPA: " << CGPA << "\nCourses Enrolled: ";
        for (const auto &course : courses) {
            cout << course << " ";
        }
        cout << endl;
    }

    int getRollNumber() const {
        return rollNumber;
    }
};


class StudentManagementSystem {
private:
    vector<Student> students;

public:
    
    void addStudent(const Student &s) {
        students.push_back(s);
    }

    
    void searchStudent(int roll) const {
        for (const auto &s : students) {
            if (s.getRollNumber() == roll) {
                s.displayInfo();
                return;
            }
        }
        cout << "Student with Roll Number " << roll << " not found." << endl;
    }

    
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No student records available." << endl;
            return;
        }
        for (const auto &s : students) {
            s.displayInfo();
            cout << "------------------------" << endl;
        }
    }
};


int main() {
    StudentManagementSystem sms;

    
    Student s1("Alice", 101, 9.2);
    s1.addCourse("Mathematics");
    s1.addCourse("Physics");

    Student s2("Bob", 102, 8.5);
    s2.addCourse("Computer Science");

    sms.addStudent(s1);
    sms.addStudent(s2);

    
    cout << "All Student Records:\n";
    sms.displayAllStudents();

   
    cout << "Searching for student with Roll Number 102:\n";
    sms.searchStudent(102);

    return 0;
}