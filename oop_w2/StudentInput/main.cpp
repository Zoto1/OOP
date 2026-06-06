#include"Student.h"
#include <iostream>
#include <format>

using namespace std;
int main()
{
    cout << "====== Chuong trinh nhap thong tin sinh vien ======\n";
    
    // Khởi tạo đối tượng Student
    Student student; 
    
    // Gọi hàm nhập liệu
    student.inputStudent();
    
    // In kết quả: Đã đổi thành 'Thong tin sinh vien vua nhap:' và thay endl bằng \n
    cout << "Thong tin sinh vien vua nhap: \n" << student.toString() << "\n"; 
    
    cout << "====== Ket thuc chuong trinh ======\n";
    
    return 0;
}