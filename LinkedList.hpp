#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <ostream>
#include "Student.hpp"

class LinkedList {
private:
    struct Node {
        Student data;
        Node* next;
        Node(const Student& s = Student(), Node* n = nullptr) : data(s), next(n) {}
    };

    Node* head; // sentinel node
    int size;

public:
    LinkedList();
    ~LinkedList();

    
    void insertOrUpdateEnd(int id, const std::string& name, double gpa);

    // delete: return 1 if deleted, 0 if not found
    int deleteById(int id);

    // search: returns pointer to internal Student 
    Student* findById(int id);

    void displayAll(std::ostream& os) const;
    int count() const { return size; }
};

#endif

