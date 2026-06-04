#include<iostream>
#include<format>

#include "Line.h"
using namespace std;

int main(){
    cout << "============== Chuong trinh nhap Duong thang ! ==============\n";
    Line duongThang;
    duongThang.Input();
    cout << duongThang.toString();
    cout << format("Do dai duong thang la {:.3f}\n" , duongThang.getLength());
    cout << "=============== Ket Thuc Chuong Trinh! ====================\n";
    return 0;
}