#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <map>
using namespace std;

class UniversitySystemException : public runtime_error {
public:
    UniversitySystemException(const string& message) : runtime_error(message) {}
};
 

class Person {
protected:
    string name;
    int age;
    string ID;
    string contact;

public:
    Person(string n, int a, string id, string c) {
        if (id.empty() || c.empty()) {
            throw UniversitySystemException("Invalid ID or contact information");
        }
        name = n;
        age = a;
        ID = id;
        contact = c;
    }

    
    string getName() const { return name; }
    string getID() const { return ID; }
    
    virtual void displayDetails() const {
        cout << "\n--- Personal Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << ID << endl;
        cout << "Contact: " << contact << endl;
    }

    virtual double calculatePayment() const { return 0.0; }
};


class Student : public Person {
private:
    string program;
    double GPA;
    vector<string> courses;
    map<string, double> grades;

public:
    Student(string n, int a, string id, string c, string prog, double gpa)
        : Person(n, a, id, c), program(prog), GPA(gpa) {}

    void addCourse(string course) {
        courses.push_back(course);
    }

    void addGrade(string course, double grade) {
        if (grade < 0.0 || grade > 100.0) {
            throw UniversitySystemException("Invalid grade value");
        }
        grades[course] = grade;
    }

    void updateGPA(double newGPA) {
        if (newGPA >= 0.0 && newGPA <= 4.0) {
            GPA = newGPA;
        } else {
            throw UniversitySystemException("Invalid GPA value");
        }
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Program: " << program << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrolled Courses: ";
        for (const auto& course : courses) {
            cout << "\n  - " << course;
            auto grade = grades.find(course);
            if (grade != grades.end()) {
                cout << " (Grade: " << grade->second << ")";
            }
        }
        cout << endl;
    }

    double calculatePayment() const override {
        return 1000.0 * courses.size(); 
    }
};


class Professor : public Person {
private:
    string department;
    string specialization;
    vector<string> teachingCourses;
    double baseSalary;
    int yearsOfService;

public:
    Professor(string n, int a, string id, string c, string dept, string spec, double salary, int years)
        : Person(n, a, id, c), department(dept), specialization(spec), 
          baseSalary(salary), yearsOfService(years) {}

    void addCourse(string course) {
        teachingCourses.push_back(course);
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Years of Service: " << yearsOfService << endl;
        cout << "Teaching Courses: ";
        for (const auto& course : teachingCourses) {
            cout << "\n  - " << course;
        }
        cout << endl;
    }

    double calculatePayment() const override {
        return baseSalary + (yearsOfService * 1000) + (teachingCourses.size() * 500);
    }
};


class Course {
private:
    string code;
    string title;
    Professor* instructor;
    vector<Student*> enrolledStudents;
    int maxStudents;

public:
    Course(string c, string t, int max = 30) 
        : code(c), title(t), instructor(nullptr), maxStudents(max) {}

    void setInstructor(Professor* prof) {
        instructor = prof;
        instructor->addCourse(title);
    }

    void enrollStudent(Student* student) {
        if (enrolledStudents.size() >= maxStudents) {
            throw UniversitySystemException("Course is full");
        }
        enrolledStudents.push_back(student);
        student->addCourse(title);
    }

    void displayDetails() const {
        cout << "\n=== Course Information ===" << endl;
        cout << "Code: " << code << endl;
        cout << "Title: " << title << endl;
        cout << "Instructor: " << (instructor ? instructor->getName() : "Not Assigned") << endl;
        cout << "Enrolled Students: " << enrolledStudents.size() << "/" << maxStudents << endl;
    }
};


class Department {
private:
    string name;
    string location;
    vector<Professor*> faculty;
    vector<Course*> courses;
    double budget;

public:
    Department(string n, string loc, double b) 
        : name(n), location(loc), budget(b) {}

    void addProfessor(Professor* prof) {
        faculty.push_back(prof);
    }

    void addCourse(Course* course) {
        courses.push_back(course);
    }

    void displayDetails() const {
        cout << "\n### Department Information ###" << endl;
        cout << "Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Budget: $" << budget << endl;
        cout << "Number of Faculty: " << faculty.size() << endl;
        cout << "Number of Courses: " << courses.size() << endl;
    }
};

int main() {
    try {
      
        Department csDept("Computer Science", "Building A", 500000);
        Department physicsDept("Physics", "Building B", 400000);

        
        Professor prof1("Dr. Smith", 45, "P101", "smith@uni.edu", "Computer Science", 
                      "Software Engineering", 80000, 10);
        Professor prof2("Dr. Johnson", 50, "P102", "johnson@uni.edu", "Physics", 
                      "Quantum Mechanics", 85000, 15);

        
        Student student1("Alice Brown", 20, "S101", "alice@student.edu", 
                       "Computer Science", 3.8);
        Student student2("Bob Wilson", 21, "S102", "bob@student.edu", 
                       "Physics", 3.9);

        
        Course cs101("CS101", "Introduction to Programming");
        Course cs102("CS102", "Data Structures");
        Course phy101("PHY101", "Basic Physics");

        
        cs101.setInstructor(&prof1);
        cs102.setInstructor(&prof1);
        phy101.setInstructor(&prof2);

        
        cs101.enrollStudent(&student1);
        cs102.enrollStudent(&student1);
        phy101.enrollStudent(&student2);

        
        student1.addGrade("Introduction to Programming", 95.0);
        student1.addGrade("Data Structures", 88.0);
        student2.addGrade("Basic Physics", 92.0);

        
        csDept.addCourse(&cs101);
        csDept.addCourse(&cs102);
        physicsDept.addCourse(&phy101);

        
        csDept.addProfessor(&prof1);
        physicsDept.addProfessor(&prof2);

        
        cout << "\n====== University Information System ======\n";
        
        cout << "\n----- Departments -----";
        csDept.displayDetails();
        physicsDept.displayDetails();

        cout << "\n----- Professors -----";
        prof1.displayDetails();
        cout << "Total Payment: $" << prof1.calculatePayment() << endl;
        prof2.displayDetails();
        cout << "Total Payment: $" << prof2.calculatePayment() << endl;

        cout << "\n----- Students -----";
        student1.displayDetails();
        cout << "Total Fees: $" << student1.calculatePayment() << endl;
        student2.displayDetails();
        cout << "Total Fees: $" << student2.calculatePayment() << endl;

        cout << "\n----- Courses -----";
        cs101.displayDetails();
        cs102.displayDetails();
        phy101.displayDetails();

    } catch (const UniversitySystemException& e) {
        cout << "Error: " << e.what() << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
} 