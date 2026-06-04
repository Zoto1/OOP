### How to compile
```bash
g++ -std=c++23 *.cpp ../PointInput/2D_Point.cpp -o chuong_trinh
```
### How to run app
```bash
./chuong_trinh
```

### Class Diagram
```mermaid
classDiagram
    class Line {
        -Point StartPoint
        -Point EndPoint
        +Line()
        +createLine(start: Point, end: Point)$ expected~Line, string~
        +setPointStartPoint(p: Point) expected~void, string~
        +setPointEndPoint(p: Point) expected~void, string~
        +getPointStartPoint() Point
        +getPointEndPoint() Point
        +Input() void
        +toString() string
        +getLength() float
    }
```