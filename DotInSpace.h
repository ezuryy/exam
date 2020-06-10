#ifndef EXAM_DOTINSPACE_H
#define EXAM_DOTINSPACE_H

#include "DotOnPlane.h"

class DotInSpace : public DotOnPlane {
private:
    double Z;
public:
    DotInSpace() : DotOnPlane(), Z(0) {}

    DotInSpace(const double &x, const double &y, const double &z) : DotOnPlane(x, y), Z(z) {}

    ~DotInSpace() {}

    friend istream &operator>>(istream &in, DotInSpace &Dot);

    friend ostream &operator<<(ostream &out, const DotInSpace &Dot);
};


#endif //EXAM_DOTINSPACE_H
