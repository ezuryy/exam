#include <iostream>
#include "DotOnPlane.h"
#include "DotInSpace.h"

using std::vector;

void PrintArray(vector<DotOnPlane> &Arr, std::mutex &MyMutex, DotOnPlane &Average) {
    double x = 0, y = 0;
    for (size_t i = 0; i < Arr.size(); ++i) {
        MyMutex.lock();
        cout << "ID thread = " << std::this_thread::get_id() << "\t\t" << Arr[i] << "\n";
        x += Arr[i].GetX();
        y += Arr[i].GetY();
        MyMutex.unlock();
        usleep(50000);
    }
    x /= Arr.size();
    y /= Arr.size();
    Average.SetX(x);
    Average.SetY(y);
}


int main() {
    cout << "Enter dot on plane :\n";
    DotOnPlane Dot1;
    cin >> Dot1;
    cout << Dot1 << endl;

    cout << "Enter dot in space :\n";
    DotInSpace Dot2;
    cin >> Dot2;
    cout << Dot2 << endl;

    cout << "Enter 3 dots on plane :\n";
    vector<DotOnPlane> ArrThree;
    for (int i = 0; i < 3; ++i) {
        double x, y;
        cin >> x >> y;
        ArrThree.push_back(DotOnPlane(x, y));
    }
    std::sort(ArrThree.begin(), ArrThree.end());
    cout << "Sorted array :\n";
    for (int i = 0; i < 3; ++i) {
        cout << ArrThree[i] << endl;
    }

    cout << "Enter 5 dots on plane :\n";
    vector<DotOnPlane> ArrFive;
    for (int i = 0; i < 5; ++i) {
        double x, y;
        cin >> x >> y;
        ArrFive.push_back(DotOnPlane(x, y));
    }

    DotOnPlane Average1, Average2;
    std::mutex MyMutex;

    std::thread t1(PrintArray, std::ref(ArrThree), std::ref(MyMutex), std::ref(Average1));
    std::thread t2(PrintArray, std::ref(ArrFive), std::ref(MyMutex), std::ref(Average2));
    t1.join();
    t2.join();

    cout << "Average dot in Array 1 = " << Average1 << endl;
    cout << "Average dot in Array 1 = " << Average2 << endl;

    return 0;
}
