#ifndef PERS_EXCEPTIONS_HPP
#define PERS_EXCEPTIONS_HPP

#include <exception>

class myException : public std::exception {};

class initException : public myException {
public:
    virtual const char* what() const noexcept{ return "Initialization Exception: Check init. values for class object\n"; }
};

class oobException : public myException{
public:
    virtual const char* what() const noexcept{ return "Out of Bounds Exception: An internal value is out of bounds\n "; }
};

#endif // PERS_EXCEPTIONS_HPP
