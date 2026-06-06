#pragma once
#include <string>
#include <expected> 

class Date { // sử dụng class để tránh các invalid date (ngày từ 1-31, tháng từ 1-12, năm dương)
private:
    int day;
    int month;
    int year;

    // Khóa cửa xưởng: Cấm tạo đối tượng tự do để tránh sai quy tắc
    Date(int d, int m, int y);

public:
    // Tạo sẵn một ngày mặc định an toàn
    Date();

 

    // Các hàm Set báo lỗi bằng expected (đã đổi tên biến để không bị trùng lặp)
    std::expected<void, std::string> setDay(int newDay);
    std::expected<void, std::string> setMonth(int newMonth);
    std::expected<void, std::string> setYear(int newYear);
    std::expected<void, std::string> setDate(int d, int m, int y);
    
    // Các hàm Get để đọc dữ liệu
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    std::string toString() const;

    // Cần có static để có thể kiểm tra dữ liệu mọi lúc mọi nơi
    static bool isValidDate(int d, int m, int y);
    
    void inputDate();
};