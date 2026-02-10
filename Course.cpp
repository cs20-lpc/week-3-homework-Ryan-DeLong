#include "Course.hpp"

Course::Course() : name_(""), location_("") {}

Course::Course(const std::string& name, const std::string& location)
    : name_(name), location_(location) {}

const std::string& Course::name() const {
    return name_;
}

const std::string& Course::location() const {
    return location_;
}

void Course::setName(const std::string& n) {
    name_ = n;
}

void Course::setLocation(const std::string& loc) {
    location_ = loc;
}

void Course::print(std::ostream& os) const {
    os << name_ << " " << location_;
}
