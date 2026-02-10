#include "Student.hpp"

// ---------- Student::CourseList ----------
Student::CourseList::CourseList() {
    head = new Node(Course()); 
    head->next = nullptr;
}

Student::CourseList::~CourseList() {
    clear();
    delete head;
    head = nullptr;
}

void Student::CourseList::clear() {
    Node* cur = head->next;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head->next = nullptr;
}

bool Student::CourseList::empty() const {
    return head->next == nullptr;
}

void Student::CourseList::addLast(const Course& c) {
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new Node(c);
}

void Student::CourseList::print(std::ostream& os) const {
    if (empty()) {
        os << "None";
        return;
    }

    Node* cur = head->next;
    while (cur) {
        cur->data.print(os);
        if (cur->next) os << "\n         ";
        cur = cur->next;
    }
}

Student::CourseList::CourseList(const CourseList& other) {
    head = new Node(Course());
    head->next = nullptr;

    Node* cur = other.head->next;
    while (cur) {
        addLast(cur->data);
        cur = cur->next;
    }
}

Student::CourseList& Student::CourseList::operator=(const CourseList& other) {
    if (this == &other) return *this;
    clear();
    Node* cur = other.head->next;
    while (cur) {
        addLast(cur->data);
        cur = cur->next;
    }
    return *this;
}

// ---------- Student ----------
Student::Student() : id_(0), name_(""), gpa_(0.0), courses_() {}

Student::Student(int id, const std::string& name, double gpa)
    : id_(id), name_(name), gpa_(gpa), courses_() {}

void Student::print(std::ostream& os) const {
    os << id_ << " " << name_ << " " << gpa_;
}
