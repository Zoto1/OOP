#pragma once
#include "../PointInput/2D_Point.h"
#include <string>
#include <expected> // Yêu cầu C++23

class Line { // sử dụng class vì line có tính bất biến ( 2 điểm ko thể trùng nhau)
private:
    Point StartPoint;
    Point EndPoint;


public:
    Line(); // Khởi tạo mặc định hợp lệ

    // --- FACTORY METHOD ---
    // Trả về Line nếu thành công, trả về string báo lỗi nếu thất bại
    static std::expected<Line, std::string> createLine(const Point& start, const Point& end);

    // --- SETTER ---
    // Trả về void nếu thành công, string nếu có lỗi
    std::expected<void, std::string> setPointStartPoint(const Point &p);
    std::expected<void, std::string> setPointEndPoint(const Point &p);

    Point getPointStartPoint() const;
    Point getPointEndPoint() const;

    void Input();
    std::string toString() const;
    float getLength() const;
};