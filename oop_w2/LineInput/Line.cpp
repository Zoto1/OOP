#include "Line.h"
#include <cmath>
#include <format>
#include <iostream>
using namespace std;

// --- HELPERS ---

static bool isSamePoint(const Point &a, const Point &b)
{
    return a.X == b.X && a.Y == b.Y;
}

// --- CONSTRUCTORS ---

Line::Line()
{
    StartPoint.X = 0.0f;
    StartPoint.Y = 0.0f;
    EndPoint.X = 1.0f;
    EndPoint.Y = 0.0f;
}

// --- FACTORY METHOD ---

expected<Line, string> Line::createLine(const Point &start, const Point &end)
{
    if (isSamePoint(start, end))
        return std::unexpected("Hai diem khong duoc trung nhau.");

    Line line;
    line.StartPoint = start;
    line.EndPoint = end;
    return line;
}

// --- SETTERS ---

expected<void, string> Line::setPointStartPoint(const Point &p)
{
    if (isSamePoint(p, EndPoint))
        return unexpected("StartPoint khong duoc trung voi EndPoint hien tai.");

    StartPoint = p;
    return {};
}

expected<void, string> Line::setPointEndPoint(const Point &p)
{
    if (isSamePoint(StartPoint, p))
        return unexpected("EndPoint khong duoc trung voi StartPoint hien tai.");

    EndPoint = p;
    return {};
}

// --- GETTERS ---

Point Line::getPointStartPoint() const { return StartPoint; }
Point Line::getPointEndPoint() const { return EndPoint; }

// --- UTILITY ---

float Line::getLength() const
{
    float dx = EndPoint.X - StartPoint.X;
    float dy = EndPoint.Y - StartPoint.Y;
    return sqrt(dx * dx + dy * dy);
}

string Line::toString() const
{
    return format("Line([{:.2f}, {:.2f}] -> [{:.2f}, {:.2f}])\n",
                  StartPoint.X, StartPoint.Y,
                  EndPoint.X, EndPoint.Y);
}

void Line::Input()
{
    cout << "Nhap diem dau (StartPoint):\n";
    StartPoint.Input();

    while (true)
    {
        cout << "Nhap diem cuoi (EndPoint):\n";
        EndPoint.Input();

        if (!isSamePoint(StartPoint, EndPoint))
            break;

        cout << "[Loi] Hai diem khong duoc trung nhau. Vui long nhap lai.\n";
    }
}