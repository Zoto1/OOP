#pragma once
#include <string>
#include "../DateInput/Date.h"
class Student
{ // sử dụng class vì student có invariant
private:
    std::string ID;       // Invariant: ID là duy nhất, không rỗng, đúng định dạng
    std::string Fullname; // Invariant: Không rỗng, chỉ chứa chữ cái
    std::string Address;  // Invariant: Không rỗng
    std::string Email;    // Invariant: Phải đúng định dạng email (có @ và .)
    Date DOB;             // Invariant: Phải là ngày hợp lệ, trước ngày hiện tại

public:
    Student();
    std::expected<void, std::string> setName(const std::string &newName);
    std::expected<void, std::string> setID(const std::string &newID);
    std::expected<void, std::string> setAddress(const std::string &newAddress);
    std::expected<void, std::string> setEmail(const std::string &newEmail);
    std::expected<void, std::string> setDOB(const Date &newDOB);
    std::string getName() const;
    std::string getID() const;
    std::string getAddress() const;
    std::string getEmail() const;
    Date getDOB() const;
    std::string toString() const;
    void inputStudent();
};