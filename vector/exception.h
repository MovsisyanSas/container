#pragma once
#include <iostream>
class OutOfRangeException : public std::exception {
public:
    OutOfRangeException() = default;

    const char* what() const noexcept override {
        return "Out of range exception occurred!";
    }
};
