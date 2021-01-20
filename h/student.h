#ifndef STUDENT_h
#define STUDENT_h

#include <iostream>

class Student {
private:
    long id;
    double average;

public:
    Student(long id, double avg); // Constructor
    ~Student(); // Destructor
    long getID() const; // A function to return student's ID
    double getAverage() const; // A function to return student's Average
    Student operator+(double added_average) const; // Addup Students Average
    bool operator>(const Student& input_student) const; // Compare two students' average
    friend std::ostream& operator<<(std::ostream& os, const Student& st); // Print Students' ID
};
#endif