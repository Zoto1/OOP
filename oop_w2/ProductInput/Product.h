#pragma once
#include <string>
#include <expected>
#include "../DateInput/Date.h"
class Product // sử dụng class để tránh các invariant 
{
private:
    std::string ID; // sản phẩm phải có mã định danh duy nhất
    std::string Name; // sản phẩm phải có tên
    Date ExpiryDate;  
    float Price; // invariant: Giá phải là số dương
public:
    Product();
    std::expected<void, std::string> setID(const std::string &newID);
    std::expected<void, std::string> setName(const std::string &newName);
    std::expected<void, std::string> setExpiryDate(const Date &newExpiryDate);
    std::expected<void, std::string> setPrice(float newPrice);
    std::string getID() const;
    std::string getName() const;
    Date getExpiryDate() const;
    float getPrice() const;
    std::string toString() const;
    void inputProduct();
};