#include "DotOnPlane.h"

DotOnPlane::DotOnPlane() : X(0), Y(0) {}

DotOnPlane::DotOnPlane(const double &x, const double &y) {
    if (x < 0 || y < 0) {
        throw MyException("Wrong coordinates.\n", x, y);
    } else {
        X = x;
        Y = y;
    }
}

void DotOnPlane::SetX(const double &x) {
    X = x;
}

void DotOnPlane::SetY(const double &y) {
    Y = y;
}

double DotOnPlane::GetX() const {
    return X;
}

double DotOnPlane::GetY() const {
    return Y;
}

istream &operator>>(istream &in, DotOnPlane &Dot) {
    double x, y;
    cin >> x >> y;
    if (x < 0 || y < 0) {
        throw MyException("Wrong coordinates.\n", x, y);
    } else {
        Dot.X = x;
        Dot.Y = y;
    }
    return in;
}

ostream &operator<<(ostream &out, const DotOnPlane &Dot) {
    cout << "( " << Dot.X << ", " << Dot.Y << " )";
    return out;
}

DotOnPlane operator+(const DotOnPlane &left, const DotOnPlane &right) {
    return DotOnPlane(left.GetX() + right.GetY(), left.GetX() + right.GetY());
}

bool operator<(const DotOnPlane &left, const DotOnPlane &right) {
    double LeftDistance = sqrt(left.GetX() * left.GetX() + left.GetY() * left.GetY());
    double RightDistance = sqrt(right.GetX() * right.GetX() + right.GetY() * right.GetY());
    return LeftDistance < RightDistance;
}