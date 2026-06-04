#include "2D_Point.h"
#include <iostream>
#include <format>
using namespace std;

void Point::Input()
{
    cout << format("Nhap gia tri X:\n");
    cin >> this->X;
    cout << format("Nhap gia tri Y: \n");
    cin >> this->Y;
}
Point::Point()
{
    X = 0.0;
    Y = 0.0;
}
Point::~Point()
{
    // do nothing
}
string Point::toString()
{
    return format("Toa do cua diem la ({:.2f} , {:.2f} )\n", X, Y);
}
