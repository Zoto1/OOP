#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "======Chuong trinh nhap ngay thang nam hop le======\n";
    Date date;
    date.inputDate();
    std::cout << "Enter date: " << date.toString() << std::endl;
    cout << "======Ket thuc chuong trinh======\n";
    return 0;
}