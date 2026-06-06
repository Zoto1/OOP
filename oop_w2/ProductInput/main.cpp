#include "Product.h"
#include <format>
#include <iostream>
using namespace std;
int main()
{
    cout << "====== Chuong trinh nhap thong tin san pham ======\n";
    
    // Khởi tạo đối tượng Product
    Product product; 
    
    // Gọi hàm nhập liệu
    product.inputProduct();
    
    // In kết quả: Đã đổi thành 'Thong tin san pham vua nhap:' và thay endl bằng \n
    cout << "Thong tin san pham vua nhap: \n" << product.toString() << "\n"; 
    
    cout << "====== Ket thuc chuong trinh ======\n";
    
    return 0;
}