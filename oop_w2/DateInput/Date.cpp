#include "Date.h"
#include <format>
#include <iostream>
using namespace std;

bool Date::isValidDate(int day, int month, int year)
{
    if (year < 0 || month < 1 || month > 12 || day < 1)
    {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiểm tra năm nhuận
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        daysInMonth[1] = 29; // Tháng 2 có 29 ngày trong năm nhuận
    }

    return day <= daysInMonth[month - 1];
}
Date::Date() : day(1), month(1), year(2000) {}
Date::~Date() {} // do nothing
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

std::expected<void, std::string> Date::setDay(int day)
{
    if (isValidDate(day, month, year))
    {
        this->day = day;
        return {};
    }
    else
    {
        return std::unexpected("Invalid day");
    }
}
std::expected<void, std::string> Date::setMonth(int month)
{
    if (isValidDate(day, month, year))
    {
        this->month = month;
        return {};
    }
    else
    {
        return std::unexpected("Invalid month");
    }
}
std::expected<void, std::string> Date::setYear(int year)
{
    if (isValidDate(day, month, year))
    {
        this->year = year;
        return {};
    }
    else
    {
        return std::unexpected("Invalid year");
    }
}
std::expected<void, std::string> Date::setDate(int d, int m, int y)
{
    if (isValidDate(d, m, y))
    {
        this->day = d;
        this->month = m;
        this->year = y;
        return {};
    }
    else
    {
        return std::unexpected("Invalid date");
    }
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
    return format("{:02d}/{:02d}/{:04d}\n", day, month, year);
}
void Date::inputDate()
{
    int d = 0;
    int m = 0;
    int y = 0;
    while (true)
    {
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
        else
        {
            cout << format("Loi: {}. Vui long nhap lai.\n", result.error());
        }
    }
}