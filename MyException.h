#ifndef EXAM_MYEXCEPTION_H
#define EXAM_MYEXCEPTION_H

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <mutex>
#include <thread>
#include <zconf.h>

class MyException : public std::invalid_argument {
private:
    double wrongX, wrongY;
public:
    MyException(const char *msg, const double &x, const double &y) : std::invalid_argument(msg), wrongX(x), wrongY(y) {
        std::cout << "Wrong coordinates : (" << wrongX << ", " << wrongY << ")\n";
    }
};

#endif //EXAM_MYEXCEPTION_H
