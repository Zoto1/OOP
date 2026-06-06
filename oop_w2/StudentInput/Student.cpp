#include "Student.h"
using namespace std;
#include <format>
#include <iostream>
Student::Student() : ID("25127000"), Fullname("Nguyen Van A"), Address("Duong so 1 , Phu Thanh , TP. HCM"), Email("fithcmus@gmail.com"), DOB() {}
const int curr_year = 2026;
std::expected<void, std::string> Student::setName(const std::string &newName)
{
    if (newName.empty())
    {
        return std::unexpected("Name cannot be empty");
    }

    for (char c : newName)
    {
        if (!isalpha(c) && !isspace(c))
        {
            return std::unexpected("Name can only contain letters and spaces");
        }
    }

    Fullname = newName;
    return {};
}

std::expected<void, std::string> Student::setID(const std::string &newID)
{
    if (newID.empty())
    {
        return std::unexpected("ID cannot be empty");
    }

    // Kiểm tra định dạng ID (ví dụ: phải bắt đầu bằng 'S' và theo sau là 8 chữ số)
    for (int i = 0; i < newID.size(); i++)
    {
        if (!isdigit(newID[i]))
        {
            return std::unexpected("ID must contain only digits after the first character");
        }
    }

    ID = newID;
    return {};
}

std::expected<void, std::string> Student::setAddress(const std::string &newAddress)
{
    if (newAddress.empty())
    {
        return std::unexpected("Address cannot be empty");
    }

    Address = newAddress;
    return {};
}

std::expected<void, std::string> Student::setEmail(const std::string &newEmail)
{
    if (newEmail.empty())
    {
        return std::unexpected("Email cannot be empty");
    }

    // Kiểm tra định dạng email đơn giản (có @ và .)
    if (newEmail.find('@') == string::npos || newEmail.find('.') == string::npos)
    {
        return std::unexpected("Invalid email format");
    }

    Email = newEmail;
    return {};
}

std::expected<void, std::string> Student::setDOB(const Date &newDOB)
{
    // Kiểm tra ngày sinh phải trước ngày hiện tại
    Date currentDate; // Giả sử có hàm lấy ngày hiện tại
    {
        if (newDOB.getYear() < curr_year)

            DOB = newDOB;
        return {};
    }

return std::unexpected("Date of birth must be before the current year");
}

std::string Student::getName() const
{
    return Fullname;
}

std::string Student::getID() const
{
    return ID;
}

std::string Student::getAddress() const
{
    return Address;
}

std::string Student::getEmail() const
{
    return Email;
}

Date Student::getDOB() const
{
    return DOB;
}

std::string Student::toString() const
{
    return format("- ID: {} \n - Name: {}\n - Address: {}\n - Email: {}\n - DOB: {}", getID(), getName(), getAddress(), getEmail(), getDOB().toString());
}

void Student::inputStudent()
{
    string input;

    // Nhập ID
    while (true)
    {
        cout << "Enter student ID : ";
        getline(cin, input);
        if (auto result = setID(input); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
    }

    // Nhập Tên
    while (true)
    {
        cout << "Enter student name: ";
        getline(cin, input);
        if (auto result = setName(input); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
    }

    // Nhập Địa chỉ
    while (true)
    {
        cout << "Enter student address: ";
        getline(cin, input);
        if (auto result = setAddress(input); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
    }

    // Nhập Email
    while (true)
    {
        cout << "Enter student email: ";
        getline(cin, input);
        if (auto result = setEmail(input); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
    }

    // Nhập Ngày sinh
    while (true)
    {
        cout << "Enter student date of birth:\n";
        Date tempDate;
        tempDate.inputDate(); // Gọi hàm input trong class Date
        if (auto result = setDOB(tempDate); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
    }

    cout << "Successfully added student information!" << endl;
}