#pragma once
#include<string>

struct Point // sử dụng struct ở đây vì không có invarant value nào ở trong 2D point
{
    float X;
    float Y;
    std::string toString();
    void Input();
    Point();
    ~Point();
};
