#include "Product.h"
#include <format>
#include <iostream>
using namespace std;
const int ATTEMPTS = 3;
Product::Product() : ID("P0000001"), Name("Sample Product"), ExpiryDate(), Price(1.0f) {}

std::expected<void, std::string> Product::setID(const std::string &newID)
{
    if (newID.empty())
    {
        return std::unexpected("ID cannot be empty");
    }

    ID = newID;
    return {};
}
std::expected<void, std::string> Product::setName(const std::string &newName)
{
    if (newName.empty())
    {
        return std::unexpected("Name cannot be empty");
    }

    Name = newName;
    return {};
}
const int CURR_YEAR = 2026;
std::expected<void, std::string> Product::setExpiryDate(const Date &newExpiryDate)
{
    if (newExpiryDate.getYear() < CURR_YEAR) // Giả sử ngày hết hạn phải sau năm 2025
    {
        return std::unexpected("Expiry date must be after the year 2025");
    }
    ExpiryDate = newExpiryDate;
    return {};
}
std::expected<void, std::string> Product::setPrice(float newPrice)
{
    if (newPrice <= 0)
    {
        return std::unexpected("Price must be a positive number");
    }

    Price = newPrice;
    return {};
}

std::string Product::getID() const
{
    return ID;
}
std::string Product::getName() const
{
    return Name;
}
Date Product::getExpiryDate() const
{
    return ExpiryDate;
}
float Product::getPrice() const
{
    return Price;
}
void Product::inputProduct()
{
    string input = " ";

    // Nhập ID
    int count = 0;
    while (count < ATTEMPTS)
    {
        cout << "Enter product ID : ";
        getline(cin, input);
        if (auto result = setID(input); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
        count++;
    }

    // Nhập Tên
    count = 0;
    while (count < ATTEMPTS)
    {
        cout << "Enter product name: ";
        getline(cin, input);
        if (auto result = setName(input); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
        count++;
    }

    // Nhập Ngày hết hạn
    count = 0;
    while (count < ATTEMPTS)
    {
        cout << "Enter product expiry date:\n";
        Date tempDate;
        tempDate.inputDate(); // Gọi hàm input trong class Date
        if (auto result = setExpiryDate(tempDate); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
        count++;
    }

    // Nhập Giá
    count = 0;
    while (count < ATTEMPTS )
    {
        cout << "Enter product price: ";
        cin.clear(); // Xóa lỗi nếu có
        float tempPrice = 0;
        cin >> tempPrice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa phần

        // Kiểm tra rỗng trước

        if (auto result = setPrice(tempPrice); result)
            break;
        else
            cerr << "Error: " << result.error() << ". Please try again.\n";
        count++;
    }
}
std::string Product::toString() const
{
    return format(" - ID: {}\n - Name: {}\n - Expiry Date: {} - Price: ${:.2f}\n", getID(), getName(), getExpiryDate().toString(), getPrice());
}