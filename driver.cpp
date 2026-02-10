#include <iostream>
#include <string>
#include <limits>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"

using namespace std;

static void clearLine() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static int readInt(const string& prompt) {
    int x;
    while (true) {
        cout << prompt;
        if (cin >> x) { clearLine(); return x; }
        cin.clear();
        clearLine();
        cout << "Invalid integer. Try again.\n";
    }
}

static double readDouble(const string& prompt) {
    double x;
    while (true) {
        cout << prompt;
        if (cin >> x) { clearLine(); return x; }
        cin.clear();
        clearLine();
        cout << "Invalid number. Try again.\n";
    }
}

static string readLine(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

int main() {
    LinkedList students;

    while (true) {
        cout << "\n1. Insert Student\n"
             << "2. Delete Student\n"
             << "3. Search Student\n"
             << "4. Display All\n"
             << "5. Count Students\n"
             << "6. Add a course\n"
             << "7. Exit\n";

        int choice = readInt("Enter choice: ");

        if (choice == 1) {
            int id = readInt("Enter ID: ");
            string name = readLine("Enter Name: ");
            double gpa = readDouble("Enter GPA: ");

            // Update-on-duplicate behavior
            students.insertOrUpdateEnd(id, name, gpa);
            cout << "Saved student with ID " << id << "\n";
        }
        else if (choice == 2) {
            int id = readInt("Enter ID to delete: ");
            int status = students.deleteById(id);
            if (status == 1) cout << "Deleted student with ID " << id << "\n";
            else cout << "No student found with ID " << id << "\n";
        }
        else if (choice == 3) {
            int id = readInt("Enter ID to search: ");
            Student* s = students.findById(id);
            if (!s) {
                cout << "No student found with ID " << id << "\n";
            } else {
                cout << "Found: ";
                s->print(cout);
                cout << "\nCourses: ";
                s->printCourses(cout);
                cout << "\n";
            }
        }
        else if (choice == 4) {
            students.displayAll(cout);
        }
        else if (choice == 5) {
            cout << "Total students: " << students.count() << "\n";
        }
        else if (choice == 6) {
            int id = readInt("Enter ID: ");
            Student* s = students.findById(id);
            if (!s) {
                cout << "No student found with ID " << id << "\n";
            } else {
                string cname = readLine("Enter Course Name: ");
                string loc = readLine("Enter location: ");
                s->addCourse(Course(cname, loc));
                cout << "Added course to student " << id << "\n";
            }
        }
        else if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

