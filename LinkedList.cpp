#include "LinkedList.hpp"

LinkedList::LinkedList() : size(0) {
    head = new Node();   // sentinel
    head->next = nullptr;
}

LinkedList::~LinkedList() {
    Node* cur = head->next;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    delete head;
    head = nullptr;
    size = 0;
}

Student* LinkedList::findById(int id) {
    Node* cur = head->next;
    while (cur) {
        if (cur->data.id() == id) return &cur->data;
        cur = cur->next;
    }
    return nullptr;
}

void LinkedList::insertOrUpdateEnd(int id, const std::string& name, double gpa) {
    // Update if exists
    if (Student* existing = findById(id)) {
        existing->setName(name);
        existing->setGpa(gpa);
        return;
    }

    // Insert at end by traversal (no tail pointer)
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new Node(Student(id, name, gpa));
    ++size;
}

int LinkedList::deleteById(int id) {
    Node* prev = head;
    Node* cur = head->next;

    while (cur) {
        if (cur->data.id() == id) {
            prev->next = cur->next;
            delete cur;
            --size;
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

void LinkedList::displayAll(std::ostream& os) const {
    os << "Students in List:\n";
    Node* cur = head->next;
    if (!cur) {
        os << "<empty>\n";
        return;
    }

    while (cur) {
        cur->data.print(os);
        os << " ";
        if (!cur->data.hasCourses()) {
            os << "None\n";
        } else {
            os << "\nCourses: ";
            cur->data.printCourses(os);
            os << "\n";
        }
        cur = cur->next;
    }
}

