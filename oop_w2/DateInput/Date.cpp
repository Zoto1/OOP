#include "Date.h"
#include <format>
#include <iostream>
#include <stdexcept> // Thêm thư viện để ném lỗi (throw exception)

using namespace std; 

bool Date::isValidDate(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1)
    {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiểm tra năm nhuận
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    {
        daysInMonth[1] = 29; 
    }

    return d <= daysInMonth[m - 1];
}

Date::Date() : day(1), month(1), year(2000) {}

// Đã xóa hàm hủy ~Date() trống (Rule of Zero)

// Sửa lại hàm khởi tạo: Bắt buộc kiểm tra dữ liệu trước khi tạo đối tượng
Date::Date(int d, int m, int y) 
{
    if (isValidDate(d, m, y)) 
    {
        day = d;
        month = m;
        year = y;
    } 
    else 
    {
        throw invalid_argument("Du lieu khoi tao ngay thang nam khong hop le!");
    }
}

// Bỏ chữ 'else' thừa và đổi tên biến để tránh trùng lặp
std::expected<void, std::string> Date::setDay(int newDay)
{
    if (isValidDate(newDay, month, year))
    {
        day = newDay;
        return {};
    }
    
    return std::unexpected("Invalid day");
}

std::expected<void, std::string> Date::setMonth(int newMonth)
{
    if (isValidDate(day, newMonth, year))
    {
        month = newMonth;
        return {};
    }
    
    return std::unexpected("Invalid month");
}

std::expected<void, std::string> Date::setYear(int newYear)
{
    if (isValidDate(day, month, newYear))
    {
        year = newYear;
        return {};
    }
    
    return std::unexpected("Invalid year");
}

std::expected<void, std::string> Date::setDate(int d, int m, int y)
{
    if (isValidDate(d, m, y))
    {
        day = d;
        month = m;
        year = y;
        return {};
    }
    
    return std::unexpected("Invalid date");
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

std::string Date::toString() const
{
    return format("{:02d}/{:02d}/{:04d}\n", getDay(), getMonth(), getYear());
}

void Date::inputDate()
{
    while (true)
    {
        // Khai báo biến ngay tại nơi bắt đầu sử dụng (Bên trong vòng lặp)
        int d = 0, m = 0, y = 0;
        
        cout << "Nhap ngay: ";
        cin >> d;
        cout << "Nhap thang: ";
        cin >> m;
        cout << "Nhap nam: ";
        cin >> y;

        auto result = setDate(d, m, y);
        
        if (result)
        {
            break; // Nhập thành công, thoát vòng lặp
        }
        
        cout << format("Loi: {}. Vui long nhap lai.\n", result.error());
    }
}