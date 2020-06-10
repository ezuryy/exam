#include "DotInSpace.h"

istream &operator>>(istream &in, DotInSpace &Dot) {
    double x, y;
    cin >> x >> y >> Dot.Z;
    Dot.SetX(x);
    Dot.SetY(y);
    return in;
}

ostream &operator<<(ostream &out, const DotInSpace &Dot) {
    cout << "( " << Dot.GetX() << ", " << Dot.GetY() << ", " << Dot.Z << " )";
    return out;
}
