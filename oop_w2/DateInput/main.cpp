#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "====== Chuong trinh nhap ngay thang nam hop le ======\n";
    
    // Khởi tạo đối tượng (Quy tắc ES.20: Luôn khởi tạo ngay khi khai báo)
    Date date; 
    
    // Gọi hàm nhập liệu
    date.inputDate();
    
    // In kết quả: Đã đổi thành 'Ngay vua nhap:' và thay endl bằng \n
    cout << "Ngay vua nhap: " << date.toString() << "\n"; 
    
    cout << "====== Ket thuc chuong trinh ======\n";
    
    return 0;
}