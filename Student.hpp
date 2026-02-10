#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <ostream>
#include "Course.hpp"

class Student {
public:
   
    class CourseList {
    private:
        struct Node {
            Course data;
            Node* next;
            Node(const Course& c, Node* n = nullptr) : data(c), next(n) {}
        };

        Node* head; // sentinel node (dummy)

    public:
        CourseList();
        ~CourseList();

        CourseList(const CourseList& other);
        CourseList& operator=(const CourseList& other);

        void addLast(const Course& c);
        bool empty() const;
        void print(std::ostream& os) const;
        void clear();
    };

private:
    int id_;
    std::string name_;
    double gpa_;
    CourseList courses_;

public:
    Student();
    Student(int id, const std::string& name, double gpa);

    int id() const { return id_; }
    const std::string& name() const { return name_; }
    double gpa() const { return gpa_; }

    void setName(const std::string& n) { name_ = n; }
    void setGpa(double g) { gpa_ = g; }

    void addCourse(const Course& c) { courses_.addLast(c); }
    bool hasCourses() const { return !courses_.empty(); }

    void print(std::ostream& os) const;
    void printCourses(std::ostream& os) const { courses_.print(os); }
};

#endif

