#include "student.h"

/*
Student: Student Class Constructor
Input: id -> student's ID, avg -> student's Average
Output: Void
*/
Student::Student(long id, double avg)
{
    this->id = id;
    this->average = avg;
}

/*
~Student: Student Class Destructor
Input: void
Output: Void
*/
Student::~Student()
{
}

/*
getID: A function to return student's ID
Input: void
Output: Student's ID
*/
long Student::getID() const
{
    return this->id;
}

/*
getAverage: A function to return student's Average
Input: void
Output: Student's Average
*/
double Student::getAverage() const
{
    return this->average;
}

/*
operator+: Addup Students Average
Input: added_average -> amount to be added to average
Output: Copied Class
*/
Student Student::operator+(double added_average) const
{
    Student St { this->id, this->average + added_average };
    return St;
}

/*
operator>: Compare two students' average
Input: input_student -> student to compare to
Output: result of compare
*/
bool Student::operator>(const Student& input_student) const
{
    return this->getAverage() > input_student.getAverage();
}

/*
operator<<: Print Students' ID
Input:  os -> ostream, st -> Student to print it's ID
Output: Stream that contains student's ID
*/
std::ostream& operator<<(std::ostream& os, const Student& st)
{
    os << st.getID();
    return os;
}
