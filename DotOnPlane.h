#ifndef EXAM_DOTONPLANE_H
#define EXAM_DOTONPLANE_H

#include "MyException.h"

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

class DotOnPlane {
private:
    double X, Y;

public:
    DotOnPlane();

    DotOnPlane(const double &x, const double &y);

    virtual ~DotOnPlane() {}

    void SetX(const double &x);

    void SetY(const double &y);

    double GetX() const;

    double GetY() const;

    friend DotOnPlane operator+(const DotOnPlane &left, const DotOnPlane &right);

    friend istream &operator>>(istream &in, DotOnPlane &Dot);

    friend ostream &operator<<(ostream &out, const DotOnPlane &Dot);

    friend bool operator<(const DotOnPlane &left, const DotOnPlane &right);

};


#endif //EXAM_DOTONPLANE_H
