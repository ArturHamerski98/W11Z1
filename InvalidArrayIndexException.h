#include <iostream>

class MyCustomException : public std::exception {
private:
    char* message;

public:
    MyCustomException(char* msg) : message(msg) {}
    char* what() {
        return message;
    }
};