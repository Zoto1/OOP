#pragma once
#include <string>
#include <expected> // Bắt buộc phải có để dùng hộp chứa lỗi

class Date {
private:
    int day;
    int month;
    int year;

    // Chuyển hàm khởi tạo có tham số vào private để cấm việc tạo đối tượng sai quy tắc ngay từ đầu
    Date(int day, int month, int year);

public:
    // Hàm khởi tạo mặc định (vẫn để public để có thể tạo sẵn một ngày an toàn, ví dụ 1/1/2000)
    Date();
    ~Date();

    // Hàm kiểm duyệt "nhà máy": Thay thế việc tạo trực tiếp, trả về đối tượng Date hoặc báo lỗi

    // Các hàm Set giờ sẽ báo cáo lại việc thay đổi dữ liệu có thành công hay không
    std::expected<void, std::string> setDay(int day);
    std::expected<void, std::string> setMonth(int month);
    std::expected<void, std::string> setYear(int year);
    
    std::expected<void,std::string> setDate(int d,int m , int y);
    // Các hàm Get và toString chỉ để đọc dữ liệu ra nên không bao giờ gây lỗi, giữ nguyên
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    std::string toString() const;

     bool isValidDate(int day, int month, int year);
    void inputDate();
};