#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <ostream>

class Course {
private:
    std::string name_;
    std::string location_;

public:
    Course();
    Course(const std::string& name, const std::string& location);

    const std::string& name() const;
    const std::string& location() const;

    void setName(const std::string& n);
    void setLocation(const std::string& loc);

    void print(std::ostream& os) const;
};

#endif




